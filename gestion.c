#include "gestion.h"
#include "hero.h"
#include "map.h"
#include "input.h"
#include "son.h"
void initialiser_bonus()
{
   bonus[0].position.x= 600;
   bonus[0].position.y=200;
   bonus[1].position.x=1000;
   bonus[1].position.y=200;
   bonus[0].image=IMG_Load ("bonus.png");
   bonus[0].actif=1;
   bonus[1].image=IMG_Load ("bonus.png");
   bonus[1].actif=1;
   indice.image=IMG_Load ("puzzle.png");
   indice.position.x=4736;
   indice.position.y=236;
   indice.actif=1;
   score=0;
}
void initialiser_bonus2()
{
   bonus[0].position.x= 600;
   bonus[0].position.y=200;
   bonus[1].position.x=1500;
   bonus[1].position.y=200;
   bonus[0].image=IMG_Load ("bonus.jpg");
   bonus[0].actif=1;
   bonus[1].image=IMG_Load ("bonus.jpg");
   bonus[1].actif=1;
   indice.image=IMG_Load ("puzzle.png");
   indice.position.x=4736;
   indice.position.y=236;
   indice.actif=1;
   score=0;
}
void afficher_bonus(SDL_Surface *ecran)
{
  int i;      
for (i=0;i<3;i++)
      {	
        if(bonus[i].actif==1)
        {
            SDL_BlitSurface(bonus[i].image,NULL,stage1.fond,&bonus[i].position);
	}
       }
}
void afficher_indice (SDL_Surface *ecran)
{

   SDL_BlitSurface (indice.image,NULL,stage1.fond,&indice.position);
} 
void mise_a_jour_score(int *stage_complet)
{
      int i;
	for(i=0;i<2;i++)
        {
		if((perso.position.x<bonus[i].position.x) && (bonus[i].position.x<perso.position.x+30) && (perso.position.y<bonus[i].position.y) && (bonus[i].position.y<perso.position.y+30) && (bonus[i].actif==1))
                {
			score+=100; 
			bonus[i].actif=0;
                        effet_sonor(assets.bonus);
		}
	}
        if((perso.position.x>indice.position.x) && (indice.position.x+284>perso.position.x) && (perso.position.y>indice.position.y) && (indice.position.y+184>perso.position.y) && indice.actif==1)
        {
            score+=1000;
            indice.actif=0;
            *stage_complet=1;
        }
    
}
void loadFont()
{	
	font = TTF_OpenFont("leadcoat.ttf", 52);
	if (font == NULL)
        {
		printf("Failed to open Font : %s\n", TTF_GetError());
		exit(1);
	}
}

void afficher_chaine(char *text, int a, int b, TTF_Font *font,SDL_Surface *ecran)
{
	SDL_Rect dest;
	SDL_Surface* surface;
	SDL_Color couleure_texte;
	
	couleure_texte.r = 255;
	couleure_texte.g = 0;
	couleure_texte.b = 0;

	surface = TTF_RenderText_Blended (font,text,couleure_texte);

	if (surface == NULL)
        {
		printf("impossible de creer la chaine %s: %s\n", text, SDL_GetError());

		return;
        }
	dest.x = a;
	dest.y = b;
	dest.w = surface->w;
	dest.h = surface->h;
	SDL_BlitSurface(surface, NULL,ecran, &dest);
	SDL_FreeSurface(surface);
}

void afficher_score(SDL_Surface *ecran)
{
	char chaine[10];
	afficher_chaine("score", 10, 0, font,ecran);
	sprintf(chaine,"%d",score);
	afficher_chaine(chaine, 15 ,50, font,ecran);	
}
void afficher_sante (SDL_Surface *ecran,int sante)
{
char chaine[10];
	afficher_chaine("sante",400, 0, font,ecran);
	sprintf(chaine,"%d",sante);
	afficher_chaine(chaine, 410 ,50, font,ecran);	

}
void afficher_vie (SDL_Surface *ecran,int nbre_vie)
{
        char chaine[10];
	afficher_chaine("vie", 1000, 0, font,ecran);
	sprintf(chaine,"%d",nbre_vie);
	afficher_chaine(chaine, 1010 ,50, font,ecran);	
}
