#include "definitions.h"
typedef struct
{
	SDL_Surface *image;
	SDL_Rect position;
        int initiale;
        int finale;
	int vitesse;
	int mort;
}enemys; 
enemys enemy[5];
/*int nbr_ennemis;*/
void initialiser_ennemis();
void mouvement_ennemis();
void afficher_ennemis(SDL_Surface *ecran);
int collision_joueur_ennemi (int a,int b);
