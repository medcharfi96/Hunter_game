#include "definitions.h"
typedef struct
{
	SDL_Surface *image;
	SDL_Rect position;
	int actif;
}entite;
entite projectile;
void upadate_attaque();
void afficher_attaque (SDL_Surface *ecran);
void upadate_attaque();
void initialiser_attaque(); 
