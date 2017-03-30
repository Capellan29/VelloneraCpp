/*
 * Player.h
 *
 *  Created on: Mar 12, 2017
 *      Author: Capellán
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include "Cancion.h"
#include <iostream>

namespace Vellonera
{

	class Player
	{
		private:
			Cancion* _primera;
			Cancion* _ultima;
			Cancion* _actual;
			bool _repeticion;

		public:
			Player();
			virtual ~Player();
			void agregar(Cancion* cancion);
			void listar();
			Cancion* avanzar();
			Cancion* retroceder();
			void repeticion();
			void desactivarRepeticion();
			Cancion* obtener(int posicion);
			void eliminar(Cancion* cancion);
			Cancion* getActual()
			{
				return _actual;
			}

			Cancion* getPrimera()
			{
				return _primera;
			}

			bool isRepeticion()
			{
				return _repeticion;
			}
	};

}

#endif
