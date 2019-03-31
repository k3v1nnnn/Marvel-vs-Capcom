#include <ControladorGrafico.hpp>
#include <ConfiguracionGlobal.hpp>
#include <controler/ControladorJson.hpp>
#include <iostream>
using namespace globals;
using namespace std;

extern ControladorJson *controladorJson;

ControladorGrafico::ControladorGrafico(){
	SDL_CreateWindowAndRenderer(controladorJson->anchoVentana(),controladorJson->alturaVentana(), 0, &this->_window, &this->_renderer);
	SDL_SetWindowTitle(this->_window, "Marvel vs Capcom");
}

ControladorGrafico::~ControladorGrafico(){
	SDL_DestroyWindow(this->_window);
	SDL_DestroyRenderer(this->_renderer);
	SDL_Quit();
}

SDL_Surface* ControladorGrafico::cargarImagen(const string &filePath){
	if(this->_spriteSheets.count(filePath) == 0){
		this->_spriteSheets[filePath] = IMG_Load(filePath.c_str());
	}
	return this->_spriteSheets[filePath];
}

void ControladorGrafico::dibujarImagen(SDL_Texture* textura, SDL_Rect* rectanguloOrigen, SDL_Rect* rectanguloDestino){
	SDL_RenderCopy(this->_renderer, textura, rectanguloOrigen, rectanguloDestino);
}

void ControladorGrafico::render(){
	SDL_RenderPresent(this->_renderer);
}

void ControladorGrafico::limpiar(){
	SDL_RenderClear(this->_renderer);
}

SDL_Renderer* ControladorGrafico::getRenderer() const{
	return this->_renderer;
}


