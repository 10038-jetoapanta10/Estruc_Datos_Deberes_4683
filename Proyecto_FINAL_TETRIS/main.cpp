#include <iostream>
#include <allegro.h>
#include <time.h>
#include "Tetris_allegro.h"

using namespace std;

int main(){

    // Iniciar allegro
    allegro_init();
    install_keyboard();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, ANCHO, ALTO, 0, 0);

    // Inicializar Audio
    if(install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) != 0){
        allegro_message("Error: inicilizando sistema de sonido\n%s\n", allegro_error);
        return 1;
    }
    set_volume(70, 70);

    // BITMAPS
    BITMAP *buffer = create_bitmap(ANCHO, ALTO);
    BITMAP *muroH = load_bitmap("Imagenes/muro_horizontal.bmp", NULL);
    BITMAP *muroV = load_bitmap("Imagenes/muro_vertical.bmp", NULL);
    BITMAP *img_b = load_bitmap("Imagenes/funca.bmp", NULL);
    BITMAP *elimn = load_bitmap("Imagenes/elimina_piezas.bmp", NULL);
    BITMAP *img_texto = load_bitmap("Imagenes/textos.bmp", NULL);
    BITMAP *img_num = load_bitmap("Imagenes/numeros.bmp", NULL);
    BITMAP *goBmp = load_bitmap("Imagenes/GameOver.bmp", NULL);
    BITMAP *p = load_bitmap("Imagenes/portada.bmp", NULL);

    portada(p);
    delete p;

    // SAMPLES
    SAMPLE *col = load_wav("Sonidos/colocar_pieza.wav");
    SAMPLE *eli = load_wav("Sonidos/elimina_fila.wav");
    SAMPLE *rot = load_wav("Sonidos/rotar_pieza.wav");


    MIDI *musica_fondo = load_midi("Sonidos/fondo.mid");
    //SAMPLE *musica_fondo = load_sample("Sonidos/musica.wav");
    //play_sample(musica_fondo, 75, 100, 1000, 1000);
    play_midi(musica_fondo, 1);

    salto:
    // Integers
    int vcaida = 7, aux = 0, pb = 0;
    int aleatorio, fila, cfila, fin;
    int puntos = 0, nivel = 0;

    // Booleanos
    bool colb = false;
    bool coli = false, cold = false;
    bool gameOver = false, reproducir;

    // Bloques
    Bloque b_prin = { 5, 2, NORMAL};
    Bloque b_prin_sig = { 15, 5, NORMAL };
    Bloque bl1[7] = {};//naranja

    Bloque bl2[7] = { };//verde

    Bloque bl3[7] = { };//amarillo

    Bloque bl4[7] = { };//morado

    Bloque bl5[7] = { };//rojo

    Bloque bl6[7] = { };//celeste

    //Generar piezas aleatoriamente
    Pieza pAc(b_prin, bl1, 0);
    srand(time(NULL));
    aleatorio = 1 + rand() % 6;
    if(aleatorio == 1) pAc.setBls(bl1), pAc.setColor(NARANJA);
    else if(aleatorio == 2) pAc.setBls(bl2), pAc.setColor(VERDE);
    else if(aleatorio == 3) pAc.setBls(bl3), pAc.setColor(AMARILLO);
    else if(aleatorio == 4) pAc.setBls(bl4), pAc.setColor(MORADO);
    else if(aleatorio == 5) pAc.setBls(bl5), pAc.setColor(ROJO);
    else if(aleatorio == 6) pAc.setBls(bl6), pAc.setColor(AZUL);

    Pieza pSig(b_prin_sig, bl1, 0);
    aleatorio = 1 + rand() % 6;
    if(aleatorio == 1) pSig.setBls(bl1), pSig.setColor(NARANJA);
    else if(aleatorio == 2) pSig.setBls(bl2), pSig.setColor(VERDE);
    else if(aleatorio == 3) pSig.setBls(bl3), pSig.setColor(AMARILLO);
    else if(aleatorio == 4) pSig.setBls(bl4), pSig.setColor(MORADO);
    else if(aleatorio == 5) pSig.setBls(bl5), pSig.setColor(ROJO);
    else if(aleatorio == 6) pSig.setBls(bl6), pSig.setColor(AZUL);

    limpiar_mapa();
    while(!key[KEY_ESC] && gameOver == false){
        clear_to_color(buffer, 0x000000);
        mostrar_muros(buffer, muroH, muroV);
        mostrar_datos(buffer, img_texto, img_num, puntos, nivel);
        mostrar_mapa(buffer, img_b);

        if(pAc.colision_abajo()) colb = true;
        if(pAc.colision_derec()) cold = true;
        if(pAc.colision_izqui()) coli = true;

        // Bajar pieza
        if(pb++ >= vcaida && !colb){
            pb = 0;
            pAc.incrY(1);
        }

        // Colosison abajo
        if(colb){
            play_sample(col, 100, 150, 1000, 0);
            pAc.insertar_mapa();
            fila = pAc.getY() + 2;
            while(fila > 19)
                fila--;
            fin = fila - 4;
            cfila = fila;
            while(fila >= fin){
                if(pAc.fila_llena(fila)){
                    play_sample(eli, 100, 150, 1000, 0);
                    for(int i=1; i<11; i++)
                        blit(elimn, buffer, 0, 0, i*SBLOCK, fila*SBLOCK, 25, 25);
                    blit(buffer, screen, 0, 0, 0, 0, ANCHO, ALTO);
                    for(int i=1; i<11; i++){
                        blit(elimn, buffer, 25, 0, i*SBLOCK, fila*SBLOCK, 25, 25);
                        blit(buffer, screen, 0, 0, 0, 0, ANCHO, ALTO);
                        blit(elimn, buffer, 50, 0, i*SBLOCK, fila*SBLOCK, 25, 25);
                        rest(8);
                    }
                    puntos++;
                    if(puntos % 5 == 0)
                        nivel++;
                }
                fila--;
            }
            fila = cfila;
            while(fila >= fin){
                if(pAc.fila_llena(fila))
                    eliminar_fila(fila);
                else
                    fila--;
            }
            if(pAc.getY() < 3){
                gameOver = true;
                break;
            }
            b_prin.x = 5, b_prin.y = 2;
            pAc = pSig;
            pAc.setBPrin(b_prin);
            aleatorio = 1 + rand() % 6;
            if(aleatorio == 1) pSig.setBls(bl1), pSig.setColor(NARANJA);
            else if(aleatorio == 2) pSig.setBls(bl2), pSig.setColor(VERDE);
            else if(aleatorio == 3) pSig.setBls(bl3), pSig.setColor(AMARILLO);
            else if(aleatorio == 4) pSig.setBls(bl4), pSig.setColor(MORADO);
            else if(aleatorio == 5) pSig.setBls(bl5), pSig.setColor(ROJO);
            else if(aleatorio == 6) pSig.setBls(bl6), pSig.setColor(AZUL);
            colb = false;
            rest(100);
        }

        // Detectando el teclado
        if(key[KEY_RIGHT] && !cold)
            pAc.incrX(1);
        if(key[KEY_LEFT] && !coli)
            pAc.incrX(-1);
        if(key[KEY_UP]){
            reproducir = true;
            Pieza pAux = pAc;
            pAc.rotar();
            pAc.incrX(1);
            if(pAc.colision_izqui()){
                pAc = pAux;
                reproducir = false;
            }
            pAc.incrX(-2);
            if(pAc.colision_derec()){
                pAc = pAux;
                reproducir = false;
            }
            pAc.incrX(1);
            if(reproducir)
                play_sample(rot, 100, 150, 1000, 0);
        }
        if(key[KEY_DOWN])
            vcaida = 0;

        if(++aux >= 7){
            vcaida = 7;
            aux = 0;
        }

        pAc.mostrar_pieza(buffer, img_b);
        pSig.mostrar_pieza(buffer, img_b);
        blit(buffer, screen, 0, 0, 0, 0, ANCHO, ALTO);
        // Reiniciar variables
        cold = false, coli = false;
        rest(50);
    }

    if(gameOver){
        while(!key[KEY_ESC]){
            blit(goBmp, buffer, 0, 0, 29, 175, 243, 108);
            if(key[KEY_ENTER])
                goto salto;
            blit(buffer, screen, 0, 0, 0, 0, ANCHO, ALTO);
            rest(5);
        }
    }

    return 0;
}
END_OF_MAIN();
