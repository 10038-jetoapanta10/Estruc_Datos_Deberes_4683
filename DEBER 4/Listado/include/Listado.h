#ifndef LISTADO_H
#define LISTADO_H


class Listado
{
    private:
    int num;
    Listado *siguiente;
    public:
        Listado();
        virtual ~Listado();
        void insertarLista(Listado *&lista, int n);
        void mostrarLista(Listado *lista);
        void buscarLista(Listado *lista, int n);
        void elimarLista(Listado *&lista, int n);
};

#endif // LISTADO_H
