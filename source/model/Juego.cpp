#include <Jugador.hpp>
#include <ControladorLogger.hpp>
#include <Juego.hpp>
#include <SpriteAnimado.hpp>

extern ControladorJson *controladorJson;
extern ControladorLogger *controladorLogger;

Juego::Juego(){
	int posicionMoverFondoIzq = controladorJson->anchoVentana() * 1/4;
	int posicionMoverFondoDer = controladorJson->anchoVentana() * 3/4;

	this->isRunning=true;
	SDL_Init(SDL_INIT_EVERYTHING);
	this->gameLoop(posicionMoverFondoIzq, posicionMoverFondoDer);
}

Juego::~Juego()
{}

void Juego::gameLoop(int posicionMoverFondoIzq, int posicionMoverFondoDer){
	ControladorGrafico graficos;
	ControladorTeclado teclado;
	SDL_Event evento;
	/*SpriteAnimado *pruebaMovimiento;

	pruebaMovimiento=new SpriteAnimado(graficos,"contents/images/CaptainAmericaSprites.png");
	pruebaMovimiento->agregarAnimacion(6,0,286,"caminarDerecha",101,126);
	pruebaMovimiento->agregarAnimacion(9,0,19,"quieto",90,120);
	pruebaMovimiento->iniciarAnimacion("caminarDerecha");*/

	this->dibujarFondo(graficos);
	this->jugador1 = new Jugador(graficos,"CapitanAmerica", "Spiderman");
	this->jugador2 = new Jugador(graficos,"Spiderman2", "CapitanAmerica2");

	while (isRunning){
		startTime = SDL_GetTicks();
		this->teclear(evento,teclado, posicionMoverFondoIzq, posicionMoverFondoDer);
		this->dibujar(graficos);
		if(SDL_GetTicks() - startTime < MAX_FRAME_TIME)
			SDL_Delay( MAX_FRAME_TIME - SDL_GetTicks() +startTime );

	}

}
void Juego::dibujarFondo(ControladorGrafico &graficos){
	this-> parallax = new Parallax(graficos);
	if(this->parallax == NULL)
		controladorLogger->registrarEvento("ERROR", "No se pudo cargar el parallax");
	else
		controladorLogger->registrarEvento("DEBUG", "Se cargo correctamente el parallax");
}

void Juego::dibujar(ControladorGrafico &grafico){
	grafico.limpiar();
	grafico.dibujarImagen(parallax->Backgroundz1(), parallax->Camaraz1(), NULL);
	grafico.dibujarImagen(parallax->Backgroundz2(), parallax->Camaraz2(), NULL);
	grafico.dibujarImagen(parallax->Backgroundz3(), parallax->Camaraz3() , NULL);
	this->jugador1->personajeActualDibujar(grafico);
	this->jugador2->personajeActualDibujar(grafico);
	/*pruebaMovimiento->dibujar(grafico,200,400);
	pruebaMovimiento->update(10);*/
	grafico.render();
}


void Juego::teclear(SDL_Event evento,ControladorTeclado teclado, int posicionMoverFondoIzq, int posicionMoverFondoDer){
	const Uint8 *keys = SDL_GetKeyboardState(NULL);
	while(SDL_PollEvent(&evento)){
			if (evento.type == SDL_QUIT  || keys[SDL_SCANCODE_ESCAPE] ){
				isRunning = false;
		        break;
		    }
			if (evento.type == SDL_KEYDOWN){
				if(evento.key.keysym.sym == SDLK_l){
					this->jugador1->cambiarPersonaje();
					controladorLogger->registrarEvento("DEBUG", "Cambio de personaje del jugador 1");
					break;
				}
				if(evento.key.keysym.sym == SDLK_o){
					this->jugador2->cambiarPersonaje();
					controladorLogger->registrarEvento("DEBUG", "Cambio de personaje del jugador 2");
					break;
				}
			}

			 if (keys[SDL_SCANCODE_D]){
				this->jugador1->personajeActualMoverDerecha();
				if(jugador1->obtenerPosicionXPersonaje(true) > posicionMoverFondoDer) this->parallax->MoverCamaraDerecha();
				controladorLogger->registrarEvento("DEBUG", "Jugador 1 a la derecha");
			}
			if (keys[SDL_SCANCODE_A]){
				this->jugador1->personajeActualMoverIzquierda();
				if (jugador1->obtenerPosicionXPersonaje(false) < posicionMoverFondoIzq) this->parallax->MoverCamaraIzquierda();
				controladorLogger->registrarEvento("DEBUG", "Jugador 1 a la izquierda");
			}
			if (keys[SDL_SCANCODE_W]){
				this->jugador1->personajeActualSaltar();
				controladorLogger->registrarEvento("DEBUG", "Jugador 1 salta");
			}
		   if (keys[SDL_SCANCODE_RIGHT]){
		    	this->jugador2->personajeActualMoverDerecha();
		    	if(jugador2->obtenerPosicionXPersonaje(true) > posicionMoverFondoDer) this->parallax->MoverCamaraDerecha();
		    	controladorLogger->registrarEvento("DEBUG", "Jugador 2 a la derecha");
		    }
		    if (keys[SDL_SCANCODE_LEFT]){
		    	this->jugador2->personajeActualMoverIzquierda();
		    	if (jugador2->obtenerPosicionXPersonaje(false) < posicionMoverFondoIzq) this->parallax->MoverCamaraIzquierda();
		    	controladorLogger->registrarEvento("DEBUG", "Jugador 2 a la izquierda");
		    }
		    if (keys[SDL_SCANCODE_UP]){
		    	this->jugador2->personajeActualSaltar();
		    	controladorLogger->registrarEvento("DEBUG", "Jugador 2 salta");
		    }
		    if (keys[SDL_SCANCODE_P]){
				this->jugador2->cambiarPersonaje();
				controladorLogger->registrarEvento("DEBUG", "Cambio de personaje de jugador 2");
			}
	}
}
