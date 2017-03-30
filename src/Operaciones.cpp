/*
 * Operaciones.cpp
 *
 *  Created on: Mar 19, 2017
 *      Author: Capellán
 */

#include "Operaciones.h"

namespace Vellonera
{

	Operaciones::Operaciones() : _player(new Player()), _cancion(NULL)
	{

	}

	void Operaciones::agregar()
	{
		string titulo, artista;
		int minutos = 0, segundos = 0;
		cout << "Introduzca el nombre de la canción: ";
		cin >> titulo;
		cout << "Introduzca el nombre del artista: ";
		cin >> artista;
		cout << "Introduzca los minutos de duración: ";
		cin >> minutos;
		cout << "Introduzca los segundos de duración: ";
		cin >> segundos;
		_cancion = new Cancion(titulo,artista,minutos,segundos);
		_player -> agregar(_cancion);
	}

	void Operaciones::listar()
	{
		bool repeticion = false;
		if(_player -> isRepeticion())
		{
			repeticion = true;
			_player -> desactivarRepeticion();
		}

		int pos = 0;
		while(_cancion != NULL)
		{
			pos++;
			_cancion = _cancion ->  getSiguiente();
		}

		Cancion* canciones[pos] = { NULL };
		pos = 0;
		_cancion = _player -> getPrimera();
		while(_cancion != NULL)
		{
			canciones[pos] = _cancion;
			pos++;
			_cancion = _cancion ->  getSiguiente();
		}

		int duracion = 0, duracion2 = 0;
		for(int i = 0; i < pos; i++)
		{
			duracion = canciones[i] -> getDuracionMinuto();
			duracion = duracion * 60;
			duracion += canciones[i] -> getDuractionSegundo();

			for(int j = 0; j < pos; j++)
			{
				duracion2 = canciones[j] -> getDuracionMinuto();
				duracion2 = duracion2 * 60;
				duracion2 += canciones[j] -> getDuractionSegundo();
				if(duracion < duracion2)
				{
					_cancion = canciones[i];
					canciones [i] = canciones[j];
					canciones[j] = _cancion;
				}
			}
		}

		for(int i = 0; i < pos; i++ )
		{
			cout
			<< canciones[i] -> getTitulo() << ", "
			<< canciones[i] -> getArtista() << " "
			<< canciones[i] -> getDuracionMinuto() << ":"
			<< canciones[i] -> getDuractionSegundo() << endl ;
		}
		if(repeticion)
		{
			_player -> repeticion();
		}
	}

	void Operaciones::verActual()
	{
		_cancion = _player -> getActual();
		cout << "Canción Actual: " << endl;
		cout
		<< _cancion -> getTitulo() << ", "
		<< _cancion -> getArtista() << " "
		<< _cancion -> getDuracionMinuto() << ":"
		<< _cancion -> getDuractionSegundo() << endl;
	}

	void Operaciones::avanzar()
	{
		cout << "Avanzando a la próxima pista ..." << endl;
		_cancion = _player -> avanzar();

		if(_cancion == NULL)
		{
			cout << "No se pudo  avanzar, al parecer ha finalizado la lista..." << endl;
		}
		else
		{
			cout << "Canción Actual: " << endl;
			cout
			<< _cancion -> getTitulo() << ", "
			<< _cancion -> getArtista()
			<< _cancion -> getDuracionMinuto() << ":"
			<< _cancion -> getDuractionSegundo() << endl;
		}
	}

	void Operaciones::retroceder()
	{
		cout << "Retrocediendo a la pista anterior ... " << endl;
		_cancion = _player -> retroceder();

		if(_cancion == NULL)
		{
			cout << "No se pudo  retroceder" << endl;
		}
		else
		{
			cout << "Canción Actual: " << endl;
			cout
			<< _cancion -> getTitulo() << ", "
			<< _cancion -> getArtista() << " "
			<< _cancion -> getDuracionMinuto() << ":"
			<< _cancion -> getDuractionSegundo() << endl;
		}
	}

	void Operaciones::activarRepeticion()
	{
		_player -> repeticion();
		cout << "Repetición en lista activado." << endl;
	}

	void Operaciones::eliminar()
	{
		cout << "Introduzca el número de la canción que desea eliminar:" << endl;
		bool repeticion = false;
		if(_player -> isRepeticion())
		{
			repeticion = true;
			_player -> desactivarRepeticion();
		}
		_cancion = _player -> getPrimera();
		int pos = 1;
		while(_cancion != NULL)
		{
			cout << pos << " - " << _cancion -> getTitulo() << ","
			<< _cancion -> getArtista() << " " << _cancion -> getDuracionMinuto()
			<< ":" << _cancion -> getDuractionSegundo() << endl;
			_cancion = _cancion -> getSiguiente();
			pos++;
		}

		cin >> pos;
		_cancion = _player -> obtener(pos);
		cout << "¿Confirma que desea eliminar: Never say never, Justing Bieber 4:48? (S/N) " << endl;
		char conf;
		cin >> conf;
		if(conf == 's' || conf == 'S')
		{
			cout << " Canción " << _cancion -> getTitulo() << ", "
			<< _cancion -> getArtista() << " " << _cancion -> getDuracionMinuto()
			<< ":" << _cancion -> getDuractionSegundo() << " ha sido eliminada " << endl;
			_player -> eliminar(_cancion);
		}

		if(repeticion)
		{
			_player -> repeticion();
		}
	}

	Operaciones::~Operaciones()
	{

	}

}
