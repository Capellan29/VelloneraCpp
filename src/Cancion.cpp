/*
 * Cancion.cpp
 *
 *  Created on: Mar 12, 2017
 *      Author: Capellán
 */

#include "Cancion.h"

namespace Vellonera
{

	Cancion::Cancion(string titulo, string artista, int minutos, int segundos) :
	_titulo(titulo), _artista(artista),
	_duracionMinuto(minutos), _duracionSegundo(segundos),
	_siguiente(NULL), _anterior(NULL)
	{

	}

	Cancion::~Cancion()
	{

	}

}
