#include "definitions.h"
typedef struct 
{
  SDL_Surface *sprite;
  SDL_Rect position;
  int nbre_vies;
  int air;/*0 si sur terre 1 en l'air*/
  int dirX;
  float dirY;
  int direction; /*1 droite 2 gauche*/
  int basx;
  int basy;
}personnage;
personnage perso;
void initialiser_hero();
void move_hero(int *framed,int *frameg,int *sante,int stage_complet,int score);
void afficher_hero(int framed,int frameg,SDL_Surface *ecran); 
