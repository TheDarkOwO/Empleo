#include "Empleo.h"

empleado::empleado(string cod, string nom, double sb)
{
    ponCedula(cod);
    ponNombre(nom);
    fechaNac = new int[3];
    fechaNac[0] = fechaNac[1] = fechaNac[2] = 0;
    PonFechaNacimiento(fechaNac);
    SalarioBasico(sb);
    system("cls");
}

empleado::~empleado()
{
}

void empleado::ponCedula(string cod)
{
    codigo = cod;
}

void empleado::ponNombre(string nom)
{
    nombre = nom;
}

void empleado::PonFechaNacimiento(int* fecha)
{
    do {
        cout << "\nFECHA DE NACIMIENTO\n";
        do {
            cout << "\n\tDigite mes: ";
            cin >> fecha[1];
        } while (fecha[1] < 1 || fecha[1] > 12);
        do {
            cout << "\n\tDigite anio: ";
            cin >> fecha[2];
        } while (fecha[2] < 1900 || fecha[2] > 2020);
        cout << "\n\tDigite dia: ";
        cin >> fecha[0];
        if (estableceFecha(fecha[0]) == 0) cout << "\t\tError en el dia!";
    } while (estableceFecha(fecha[0]) != 1);
}

int empleado::estableceFecha(int F)
{
    int dias[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if ((fechaNac[1] == 2) && (fechaNac[2] % 400 == (fechaNac[2] % 100 != 0 && fechaNac[2] % 4 == 0)))
        if (F >= 1 && F <= 29)
            return 1;
        else
            return 0;
    else
        if (F < 1 || F > dias[fechaNac[1]])
            return 0;
        else
            return 1;
}

void empleado::SalarioBasico(double salario)
{
    
    salarioBasico = salario;
          
}

void empleado::imprimir()
{
    cout << "\tCedula No: " << codigo;
    cout << "\n\tNombre del empleado: " << nombre;
    cout << "\n\tFecha de nacimiento: " << fechaNac[0] << "/" << fechaNac[1] << "/" << fechaNac[2] << "\n";
    cout << "\n\tSalario: " << neto() << endl;
}

long empleado::neto()
{
    return salarioBasico;
}
