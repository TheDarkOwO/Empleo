#ifndef SERVICIOS_H
#define SERVICIOS_H
#include "Empleo.h"
class Servicios : public empleado
{
public:
	Servicios(string, string, double, double);
	~Servicios();
	void PonHorasExtras(double);
	long baseHorasExtras();
	virtual void imprimir();
	virtual long neto();
private:
	double HorasExtras;
};

#endif