#include "Academico.h"
#include "Empleo.h"

Academico::Academico(string cod, string nom, double sb,int PdI,  char NsE) : empleado( cod,  nom,  sb)
{
	PonNiveldeEstudio(NsE);
	PonPuntajeInvestigacion(PdI);
}
Academico::~Academico()
{
}

void Academico::PonNiveldeEstudio(char NsE)
{
	NivelEstudio = NsE;

}
void Academico::PonPuntajeInvestigacion(int PdI)
{
	PuntajeInvestigacion = PdI;
}

long Academico::BonifEstudio()
{
	switch (NivelEstudio)
	{
	case 'T':
		return 0.05 * salarioBasico;
	case 'P':
		return 0.08 * salarioBasico;
	case 'E':
		return 0.10 * salarioBasico;
	case 'M':
		return 0.20 * salarioBasico;
	case 'D':
		return 0.30 * salarioBasico;
	default:
		break;
	}
	return 0;
}

long Academico::BonifInvestigacion()
{
	if (0 <= PuntajeInvestigacion && PuntajeInvestigacion <= 10)
	{
		return (PuntajeInvestigacion * ( 0.01 * salarioBasico));
	}
	else
	{
		if (11 <= PuntajeInvestigacion && PuntajeInvestigacion <= 100)
		{
			return (PuntajeInvestigacion * (0.03 * salarioBasico));
		}
		else
		{
			if (101 <= PuntajeInvestigacion && PuntajeInvestigacion <= 500)
			{
				return (PuntajeInvestigacion * (0.05 * salarioBasico));
			}
			else
			{
				return (PuntajeInvestigacion * (0.08 * salarioBasico));
			}
		}
	}
}

void Academico::imprimir()
{
	cout << "|||   Empleado academico   |||\n\n";
	string Aux[5] = { "Tecnico o tecnologico", " Profesional", "Especialista", "Magister", "Doctor" };
	string Aux2[4] = {"No categorizado", "Junior", "Asociado", "Senior"};
	empleado::imprimir();
	cout << "\n\tNivel de estudio: ";
	switch (NivelEstudio)
	{
	case 'T':
		cout << Aux[0] << endl;
		break;
	case 'P':
		cout << Aux[1] << endl;
		break;
	case 'E':
		cout << Aux[2] << endl;
		break;
	case 'M':
		cout << Aux[3] << endl;
		break;
	case 'D':
		cout << Aux[4] << endl;
		break;
	default:
		break;
	}
	cout << "\n\tTipo de investigador: ";

	if (0 <= PuntajeInvestigacion && PuntajeInvestigacion <= 10)
	{
		cout << Aux2[0] << endl << endl;
	}
	else
	{
		if (11 <= PuntajeInvestigacion && PuntajeInvestigacion <= 100)
		{
			cout << Aux2[1] << endl << endl;
		}
		else
		{
			if (101 <= PuntajeInvestigacion && PuntajeInvestigacion <= 500)
			{
				cout << Aux2[2] << endl << endl;
			}
			else
			{
				cout << Aux2[3] << endl << endl;
			}
		}
	}
}

long Academico::neto() 
{
	return (0.89 * (salarioBasico + BonifEstudio() + BonifInvestigacion()));
}
