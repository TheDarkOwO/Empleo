#ifndef ADMINISTRATIVO_H
#define ADMINISTRATIVO_H
#include "Empleo.h"
class Administrativo : public empleado
{
public:
	Administrativo(string, string, double, char);
	~Administrativo();
	virtual long neto();
	void PonCargo(char);
	virtual void imprimir();
	long BonifCargo();
private:
	char cargo;
};

#endif