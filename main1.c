#include "map.h"
#include "input.h"
#include "hero.h"
#include "gestion.h"
#include "ennemis.h"
#include "definitions.h"
#include "menu.h"
#include "attaque.h"
#include "son.h"
int main()
{
    SDL_Surface *ecran;
    SDL_Event event;
    int continuer=1;
    int framed=0;
    int frameg=1;
    int nbre_vie;
    int sante;
    int stage_complet;
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init(); 	
    ecran=SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,32,SDL_HWPALETTE|SDL_DOUBLEBUF|SDL_FULLSCREEN);
    SDL_EnableKeyRepeat(100, 100);
    loadFont();
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ) 
    { 
        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError()); 
    }
    initialiser_son();
    camera.w=SCREEN_WIDTH;
    camera.h=SCREEN_HEIGHT;
    camera.x=0;
    camera.y=0;
    continuer=0;
   do
   {
    continuer=menu(ecran);
    stage_complet=0;
    nbre_vie=3;
    sante=3;
    stage_complet=0;
    initialiser_niveau();
    initialiser_bonus();
    initialiser_hero ();
    initialiser_ennemis();
    initialiser_attaque();
    while(nbre_vie!=0 && continuer==1 && stage_complet==0)
    {
    update_attaque();
    mouvement_ennemis();
    getinput(event);
    if (sante==0)
    {
       nbre_vie--;
       sante=3;
    }
    tuer_ennemi(&score);
    move_hero(&framed,&frameg,&sante,stage_complet,score);
    SetCamera();
    afficher_niveau(ecran);
    afficher_bonus (ecran);
    afficher_indice (ecran);
    afficher_ennemis(ecran);
    afficher_hero(framed,frameg,ecran);
    afficher_attaque (ecran);
    afficher_score(ecran);
    afficher_sante (ecran,sante);
    afficher_vie (ecran,nbre_vie);
    mise_a_jour_score(&stage_complet);
    SDL_Flip(ecran);
    }
   if (stage_complet==1)
   {
    initialiser_niveau2();
    initialiser_bonus2();
    initialiser_hero();
    initialiser_ennemis2();
    initialiser_attaque();
   }
   while(nbre_vie!=0 && continuer==1 && stage_complet==1)
    {
    update_attaque();
    mouvement_ennemis();
    getinput(event);
    if (sante==0)
    {
       nbre_vie--;
       sante=3;
    }
    tuer_ennemi(&score);
    move_hero(&framed,&frameg,&sante,stage_complet,score);
    SetCamera();
    afficher_niveau2(ecran);
    afficher_bonus (ecran);
    afficher_indice (ecran);
    afficher_ennemis(ecran);
    afficher_hero(framed,frameg,ecran);
    afficher_attaque (ecran);
    afficher_score(ecran);
    afficher_sante (ecran,sante);
    afficher_vie (ecran,nbre_vie);
    mise_a_jour_score(&stage_complet);
    SDL_Flip(ecran);
    }
   }while (continuer!=0);
   SDL_FreeSurface(stage1.fond);
   SDL_FreeSurface(stage1.fond2);
   SDL_FreeSurface(perso.sprite);
   SDL_FreeSurface(ecran);
   TTF_CloseFont(font);  
   return 0;
}
