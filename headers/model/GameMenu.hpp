#ifndef HEADERS_MODEL_GAMEMENU_HPP_
#define HEADERS_MODEL_GAMEMENU_HPP_
#include <Boton.hpp>
#include <vector>
#include <SDL2/SDL_ttf.h>

class GameMenu{
public:
	GameMenu(ControladorGrafico &graficos);
	~GameMenu();
	void crearBotones(ControladorGrafico &graficos);
	void crearBotonParaPersonaje(ControladorGrafico &graficos, int i);
	void handleEvent(ControladorGrafico &graficos);
	void dibujar(ControladorGrafico &graficos);
	void elegirPersonajes(ControladorGrafico &graficos);

private:
	std::vector<Boton> botones;
	TTF_Font* marvelFont;
};



#endif /* HEADERS_MODEL_GAMEMENU_HPP_ */
