#ifndef SOURCE_MODEL_TEXTURASPERSONAJES_HPP_
#define SOURCE_MODEL_TEXTURASPERSONAJES_HPP_
#include <ControladorGrafico.hpp>
#include <ControladorJson.hpp>
#include <map>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

using namespace std;

class Texturas {
	public:
		Texturas(ControladorGrafico &graficos,vector<tuple<string, const string>> nombresYpaths);
		~Texturas();
		SDL_Texture * getTextura(string nombre);
		void cargarTitulos(ControladorGrafico &graficos,vector<tuple<string,string,int,string,int ,int ,int >>titulos);
		void agregarTextura(string nombre, SDL_Texture* textura);
		bool existeTextura(string nombre);
	private:
		std::map<string, SDL_Texture*> texturas;
};



#endif
