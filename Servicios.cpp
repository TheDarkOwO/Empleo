#include "Servicios.h"

Servicios::Servicios(string cod, string nom, double sb, double Hora) : empleado(cod, nom, sb)
{
	PonHorasExtras(Hora);
}

Servicios::~Servicios()
{
}

void Servicios::PonHorasExtras(double Hora)
{
	HorasExtras = Hora;
}

long Servicios::baseHorasExtras()
{
	return (salarioBasico / 30 / 8) * 1.20;
}

void Servicios::imprimir()
{
	cout << "|||   Empleado Servicios   |||\n\n";
	empleado::imprimir();
	cout << "\n\tHoras extra: " << HorasExtras << " Horas" << endl << endl;
}
long Servicios::neto()
{
	return(salarioBasico + (HorasExtras * baseHorasExtras())) * 0.89;
}