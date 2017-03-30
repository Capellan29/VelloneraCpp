/*
 * Player.cpp
 *
 *  Created on: Mar 12, 2017
 *      Author: Capellán
 */

#include "Player.h"

namespace Vellonera
{

	Player::Player() : _primera(NULL), _ultima(NULL), _actual(NULL), _repeticion(false)
	{

	}

	Player::~Player()
	{

	}

	void Player::agregar(Cancion* cancion)
	{
		if(_primera == NULL)
		{
			_primera = cancion;
			_actual = cancion;
			_ultima = cancion;
		}
		else
		{
			if(_ultima -> getSiguiente() != NULL)
			{
				cancion -> setSiguiente(_primera);
				_primera -> setAnterior(cancion);
			}
			else
			{
				cancion -> setAnterior(_ultima);
			}
			_ultima -> setSiguiente(cancion);
			_ultima = cancion;
		}

	}

	void Player::listar()
	{

	}

	Cancion* Player::avanzar()
	{
		if(_actual -> getSiguiente() != NULL)
		{
			_actual = _actual -> getSiguiente();
			return _actual;
		}

		return NULL;
	}

	Cancion* Player::retroceder()
	{
		if(_actual -> getAnterior() != NULL)
		{
			_actual = _actual -> getAnterior();
			return _actual;
		}

		return NULL;
	}

	void Player::repeticion()
	{
		_primera -> setAnterior(_ultima);
		_ultima -> setSiguiente(_primera);
		_repeticion = true;
	}

	void Player::desactivarRepeticion()
	{
		_primera -> setAnterior(NULL);
		_ultima -> setSiguiente(NULL);
		_repeticion = false;
	}

	Cancion* Player::obtener(int posicion)
	{
		if(_primera != NULL)
		{
			Cancion* aux = _primera;
			for(int i = 2; i <= posicion; i++)
			{
				aux = aux -> getSiguiente();
				if(aux == NULL)
					break;
			}
			return aux;
		}

		return  NULL;
	}

	void Player::eliminar(Cancion* cancion)
	{
		if(_actual == cancion)
		{
			if(cancion -> getSiguiente() != NULL)
			{
				_actual = _actual -> getSiguiente();
			}
			else
			{
				_actual = _actual -> getAnterior();
			}
		}


		if(cancion -> getAnterior() == NULL && cancion -> getSiguiente() == NULL)
		{
			_primera = NULL;
			_ultima = NULL;
		}
		else
		{
			Cancion* aux = cancion -> getAnterior();
			if(aux == NULL)
			{
				_primera = cancion -> getSiguiente();
				_primera -> setAnterior(NULL);
			}
			else
			{
				aux -> setSiguiente(cancion -> getSiguiente());
				aux = cancion -> getSiguiente();
				if(aux == NULL)
				{
					_ultima = cancion -> getAnterior();
					_ultima -> setAnterior(NULL);
				}
				else
				{
					aux -> setAnterior(cancion -> getAnterior());
				}
			}


		}

		cout << endl << endl;

		delete cancion;
	}

}
