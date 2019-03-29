#include <ControladorTexturas.h>

SDL_Texture* ControladorTexturas::LoadTexture(const char* texture ){
	SDL_Surface* tempSurface = IMG_Load(texture);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Juego::renderer, tempSurface);
	SDL_FreeSurface(tempSurface);
	//hola
	return tex;
}