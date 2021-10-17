#ifndef ACADEMICO_H
#define ACADEMICO_H

#include "Empleo.h"
#include <iostream>
#include <Windows.h>
using namespace std;

class Academico :public empleado
{
public:
	Academico(string cod, string nom, double sb, int PdI, char NsE);
	~Academico();
	void PonNiveldeEstudio(char);
	void PonPuntajeInvestigacion(int);
	virtual void imprimir();
	virtual long neto();
	long BonifEstudio();
	long BonifInvestigacion();
private:
	char NivelEstudio;
	int PuntajeInvestigacion;
};

#endif