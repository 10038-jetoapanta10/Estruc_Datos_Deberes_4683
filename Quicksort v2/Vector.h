#pragma once
class Vector
{
private:
	int* arreglo;
public:
	Vector() = default;
	Vector(int*);
	void set_arreglo(int*);
	int* get_arreglo();
};