/*
 * Operaciones.h
 *
 *  Created on: Mar 19, 2017
 *      Author: Capellán
 */

#ifndef OPERACIONES_H_
#define OPERACIONES_H_
#include "Player.h"


namespace Vellonera
{

	class Operaciones
	{
		private:
			Player* _player;
			Cancion* _cancion;

		public:
			Operaciones();
			void agregar();
			void listar();
			void verActual();
			void avanzar();
			void retroceder();
			void activarRepeticion();
			void eliminar();
			virtual ~Operaciones();
	};

}

#endif
