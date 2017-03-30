/*
 * Cancion.h
 *
 *  Created on: Mar 12, 2017
 *      Author: Capellán
 */


#ifndef CANCION_H_
#define CANCION_H_
#include <string>

using namespace std;

namespace Vellonera
{

	class Cancion
	{

		private:
			string _titulo;
			string _artista;
			int _duracionMinuto;
			int _duracionSegundo;
			Cancion* _siguiente;
			Cancion* _anterior;

		public:
			Cancion(string titulo, string artista, int minutos, int segundos);
			virtual ~Cancion();

			Cancion* getAnterior()
			{
				return _anterior;
			}

			string getArtista()
			{
				return _artista;
			}

			int getDuracionMinuto()
			{
				return _duracionMinuto;
			}

			int getDuractionSegundo()
			{
				return _duracionSegundo;
			}

			Cancion* getSiguiente()
			{
				return _siguiente;
			}

			string getTitulo()
			{
				return _titulo;
			}

			void setAnterior(Cancion* anterior)
			{
				_anterior = anterior;
			}

			void setSiguiente(Cancion* siguiente)
			{
				_siguiente = siguiente;
			}

		};
}

#endif
