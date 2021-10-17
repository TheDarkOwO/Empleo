#include "Administrativo.h"

Administrativo::Administrativo(string cod, string nom, double sb, char Carg) : empleado(cod, nom, sb)
{
	PonCargo(Carg);
}
Administrativo::~Administrativo()
{
}
void Administrativo::PonCargo(char Carg)
{
	cargo = Carg;
}

long Administrativo::BonifCargo()
{
	switch (cargo)
	{
	case 'D':
		return 0.30 * salarioBasico;
	case 'J':
		return 0.20 * salarioBasico;
	case 'A':
		return 0.10 * salarioBasico;
	default:
		break;
	}
	return 0;
}

void Administrativo::imprimir()
{
	cout << "|||   Empleado administrativo   |||\n\n";
	string Aux[3] = { "Directivo", "Jefe", "Auxiliar" };
	empleado::imprimir();
	cout << "\n\tCargo: ";
	switch (cargo)
	{
	case 'D':
		cout << Aux[0] << endl << endl;
		break;
	case 'J':
		cout << Aux[1] << endl << endl;
		break;
	case 'A':
		cout << Aux[2] << endl << endl;
		break;
	default:
		break;
	}
}

long Administrativo::neto()
{
	return (0.89 * (salarioBasico + BonifCargo()));
}