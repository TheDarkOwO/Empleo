#ifndef EMPLEO_H
#define EMPLEO_H

#include <iostream>
#include <Windows.h>
using namespace std;

class empleado {
public:
	empleado(string, string, double);
	~empleado();
	void ponCedula(string);
	void ponNombre(string);
	void PonFechaNacimiento(int*);
	void SalarioBasico(double);
	int estableceFecha(int);
	/* Escribe el prototipo de la funcion virtual imprimir*/
	virtual void imprimir();
	/* Escribe el prototipo de la funcion virtual */
	virtual long neto();
protected:
	string codigo;
	string nombre;
	int* fechaNac;
	double salarioBasico;
};

#endif // EMPLEADO_H

