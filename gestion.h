#include "definitions.h"
typedef struct 
{
  SDL_Surface* image;
  SDL_Rect position;
  int actif;
}elements;
elements bonus[2];
elements indice;
TTF_Font *font;
int score;
void initialiser_bonus();
void mise_a_jour_score(int *stage_complet);
void afficher_bonus(SDL_Surface *ecran);
void afficher_indice (SDL_Surface *ecran);
void afficher_score(SDL_Surface *ecran);
void afficher_chaine(char *texte, int a, int b, TTF_Font *font,SDL_Surface *ecran);
void afficher_vie (SDL_Surface *ecran,int nbre_vie);
void afficher_sante (SDL_Surface *ecran,int sante);
void closeFont();

  
