#include "Empleo.h"
#include "Servicios.h"
#include "Administrativo.h"
#include "Academico.h"
void MenuAdministrativo(char&), MenuDatosPrincipales(string&, string&), MenuAcademico(int&, char&), MenuServicio(double&);
int main()
{
    string AuxName, AuxCod; double SalarioB; int AuxInt; double AuxDouble;
    char Auxchar;
    cout << "|||   Salario Basico   |||\n\n";
    cout << "\nDigite el salario en el cual se basara el pago de los empleados: ";
    cin >> SalarioB;
    system("cls");

    cout << "|||   Empleado administrativo   |||\n\n";
    MenuDatosPrincipales(AuxCod, AuxName);
    MenuAdministrativo(Auxchar);
    Administrativo Empleado1(AuxCod, AuxName, SalarioB, Auxchar); 
    system("cls");

    cout << "|||   Empleado academico   |||\n\n";
    MenuDatosPrincipales(AuxCod, AuxName);
    MenuAcademico(AuxInt, Auxchar);
    Academico Empleado2(AuxCod, AuxName, SalarioB, AuxInt, Auxchar);
    system("cls");

    cout << "|||   Empleado de servicio   |||\n\n";
    MenuDatosPrincipales(AuxCod, AuxName);
    MenuServicio(AuxDouble);
    Servicios Empleado3(AuxCod, AuxName, SalarioB, AuxDouble);
    system("cls");

    cout << "Datos: \n\n";
    Empleado1.imprimir();
    Empleado2.imprimir();
    Empleado3.imprimir();
    return 0;
}

void MenuDatosPrincipales(string &Codigo, string &Nombre)
{
    cout << "\nDigite el nombre del empleado: ";
    cin >> Nombre;
    cout << "\nDigite el codigo de identificacion del empleado: ";
    cin >> Codigo;
}

void MenuAdministrativo(char &Cargo)
{
    Cargo = 'X';
    while (!(Cargo == 'D' || Cargo == 'J' || Cargo == 'A'))
    {
        cout << "\nD. Directivo";
        cout << "\nJ. Jefe";
        cout << "\nA. Administrativo";
        cout << "\n\nDigite el cargo del empleado: ";
        cin >> Cargo;
        if (!(Cargo == 'D' ||  Cargo == 'J' || Cargo == 'A'))
        {
            cout << "Entrada invalida...\n";
            cin.ignore();
            cin.get();
            system("cls");
            cout << "|||   Empleado administrativo   |||\n\n";
        }
    }
}
void MenuAcademico(int& Puntos, char& Estudio)
{
    Estudio = 'X';
    Puntos = -1;
    while (!(Estudio == 'T' || Estudio == 'P' || Estudio == 'E' || Estudio == 'M' || Estudio == 'D'))
    {
        cout << "\nT.Tecnico o tecnologico";
        cout << "\nP. Profesional";
        cout << "\nE. Especialista";
        cout << "\nM. Magister";
        cout << "\nD. Doctor";
        cout << "\n\nDigite el nivel de estudio del empleado: ";
        cin >> Estudio;
        if (!(Estudio == 'T' || Estudio == 'P' || Estudio == 'E' || Estudio == 'M' || Estudio == 'D'))
        {
            cout << "Entrada invalida...\n";
            cin.ignore();
            cin.get();
            system("cls");
            cout << "|||   Empleado academico   |||\n\n";
        }
    }
    while (Puntos < 0)
    {
        cout << "\n\nDigite el puntaje de investigacion del empleado: ";
        cin >> Puntos;
        if (Puntos < 0)
        {
            cout << "El numero no puede ser menor que 0\n";
            cin.ignore();
            cin.get();
        }
    }
}

void MenuServicio(double &Hora)
{
    Hora = -1;
    while (Hora < 0)
    {
        cout << "\n\nDigite las horas extras trabajadas: ";
        cin >> Hora;
        if (Hora < 0)
        {
            cout << "El numero no puede ser menor que 0\n";
            cin.ignore();
            cin.get();
        }
    }
}
