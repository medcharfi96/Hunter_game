#include "definitions.h"
typedef struct 
{
	int haut,bas,gauche,droite,attaque,save;
}controle;
controle input;
void getinput(SDL_Event event);
