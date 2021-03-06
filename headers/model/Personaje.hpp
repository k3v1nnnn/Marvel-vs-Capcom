#ifndef PERSONAJE_HPP_
#define PERSONAJE_HPP_

#include <Juego.hpp>
#include <SpriteAnimado.hpp>
#include <ControladorGrafico.hpp>
#include <string>
#include <ControladorJson.hpp>
#include <ControladorSonido.hpp>

using namespace std;

class ControladorGrafico;

class Personaje{

	public:

		Personaje( std::string nombre, int posicionXinicial, SDL_RendererFlip flip);
		~Personaje();
		int zindexPersonaje();
		void actualizar(Personaje *enemigo);
		bool moverDerecha(Personaje *enemigo, bool finEscenarioDerecha); //devuelve true o false si hay que mover o no le parallax
		bool moverIzquierda(Personaje *enemigo,bool finEscenarioIzquierda); //devuelve true o false si hay que mover o no le parallax
		bool colisionaAlaDerecha(SDL_Rect rectanguloOponente, string oponente);
		bool colisionaAlaIzquierda(SDL_Rect rectanguloOponente, string oponente);
		bool colisionaAbajoIzquierda(SDL_Rect rectanguloOponente);
		bool colisionaAbajoDerecha(SDL_Rect rectanguloOponente);
		bool ladoDerecho();
		bool estaSaltando();
		void correrADerecha();
		void correrAIzquierda();
		void saltar(Personaje *enemigo);
		void cambio();
		void golpe(string tipoDeGolpe);
		void agacharse();
		void tirar();
		void cambiarAnimacion(string nombre);
		void Flip();
		void recibirGolpe();
		void defenderse();
		void disparar();
		SDL_RendererFlip getFlip();
		void actualizarPiso();
		float getPosX();
		float getPosY();
		void saltarEnemigoAIzq();
		SDL_Rect  obtenerRectangulo();
		SDL_Rect getRectDestinoArrojable();
		SDL_Rect getRectOrigenArrojable();
		std::string getNombre();
		string getSonido();
		SpriteAnimado *obtenerSprite();
		void restarVida(int cantidad);
		int obtenerVida();
		void reiniciarVida();
		void bloquear();
		void habilitar();
		bool bloqueado();
		void forzarPosicion(float x, float y);
		bool estaDisparando();
		void setDisparo();
		void actualizarDisparo();
		void serLanzado(Personaje * enemigo);
		void levantarse();
		void festejar(int i);
		int getAncho();
		int getAlto();


	private:
		bool habilitado;
		int posicionXinicial;
		int zindex;
		int ancho;
		int alto;
		int velocidad = 10;
		int posicionYdefault ;
		float posx, posy;
		float velocidadInicial;
		float alturaActualSalto = 0;
		float tiempo = 0;
		bool agachado = false;
		bool saltando = false;
		bool defendiendo = false;
		bool moviendoIzq=false;
		bool moviendoDer=false;
		bool lanzado=false;
		SpriteAnimado *spriteAnimado;
		SpriteAnimado *disparable;
		SDL_RendererFlip flip;
		std::string nombre;
		int vida;
		int anchoEnemigo;
		int offsetX=0;
		int anchoDefault;
		float constanteEstiramientoHorizontal;
		float constanteEstiramientoVertical;
		int velocidadArrojable=10;
		int anchoDisparo,altoDisparo,posyDisparo;
		int distanciaDisparada = 0;
		int distanciaMaximaDisparo = 300;
		bool disparando = false;
		bool lanzadoAderecha=false;
		bool lanzadoAizquierda=false;
		int distanciaRecorrida=0;
		int maximaDistanciaArrojable = 500;
		map<string,int>offset;

};

#endif

