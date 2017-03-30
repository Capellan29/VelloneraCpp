//============================================================================
// Name        : Vellonera.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "Operaciones.h"
using namespace std;
using namespace Vellonera;

int main()
{
	Operaciones* operaciones = new Operaciones();
	int op = 0;
	do
	{
		cout << "Bienvenidos al sistema de Vellonera" << endl << endl;
		cout << "1- Agregar nueva canción\n2- Visualizar canciones\n3- Mostrar canción actual\n";
		cout << "4- Próxima Canción\n5- Canción Anterior\n6- Activar repetición en lista\n";
		cout << "7- Eliminar\n8- Salir\n\n";
		cout << "Elija la opcion que desea realizar -> ";
		cin >> op;
		switch (op)
		{
			case 1:
				operaciones -> agregar();
				cout << "Cancion agreagda con exito a la lista" ;
				break;
			case 2:
				operaciones -> listar();
				break;
			case 3:
				operaciones -> verActual();
				break;
			case 4:
				operaciones -> avanzar();
				break;
			case 5:
				operaciones -> retroceder();
				break;
			case 6:
				operaciones -> activarRepeticion();
				break;
			case 7:
				operaciones -> eliminar();;
				break;
			case 8:
				cout << "Saliendo del sistema..." ;
				break;

		}
		system("pause>n");
		cout << endl << endl;
	} while( op != 8);

	return 0;
}
