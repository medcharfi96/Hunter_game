#include "hero.h"
#include "map.h"
#include "input.h"
#include "gestion.h"
#include "ennemis.h"
#include "attaque.h"
#include "son.h"
void initialiser_hero()
{
	perso.position.x=50;
	perso.position.y=100;
	perso.nbre_vies = 3;
        perso.dirX=VITESSE_JOUEUR;
        perso.dirY= HAUTEUR_SAUT;
	perso.sprite=IMG_Load("marche_droite.png");
	perso.position.w=perso.sprite->w;
	perso.position.h=perso.sprite->h;
        perso.basx=perso.position.x+ 30;
        perso.basy=perso.position.y+ 60;
}

void move_hero(int *framed,int *frameg,int *sante,int stage_complet,int score)
{
      int verif;
      int c,c1;
     if (stage_complet==0)
     {
     c=collision_map (perso.basx,perso.basy);
     }
     else
     {
        c=collision_map2 (perso.basx,perso.basy);
     }
     c1=collision_joueur_ennemi (perso.position.x,perso.position.y);
    if (c1!=0)
    { 
       (*sante)--;
       if (c1==1)/*collision a droite*/
       {
         perso.position.x-=perso.dirX+CHOC;
         perso.basx-=perso.dirX+CHOC;
       }
       else/*collision a gauche*/
       {
         perso.position.x+=perso.dirX+CHOC;
         perso.basx+=perso.dirX+CHOC;
       }
    }
else
{
    if (c==1)
     {
         perso.air=0;
         perso.dirY=HAUTEUR_SAUT;
     }
     else
     {
       perso.air=1;
        perso.dirY=0;
     }
	if(input.droite==1 && perso.air==0)
        {
		perso.sprite=IMG_Load("marche_droite.png");
		perso.position.x+=perso.dirX;
                perso.basx+=perso.dirX;
                perso.direction=1;
		(*framed)+=1;
		if(*framed>1)
                {
			(*framed)=0;
		}
                
	}
	else if(input.gauche==1 && perso.air==0)
        {
		perso.direction=0;
                perso.sprite=IMG_Load("marche_droite.png");
		perso.position.x-=perso.dirX;
                perso.basx -=perso.dirX;
		(*frameg)--;
                perso.direction=2;
		if(*frameg<0)
                {
			*frameg=1;
		}
	}
	else if(input.haut==1 && perso.air==0)
        {		
                perso.position.y-=perso.dirY*2;
                perso.basy-=perso.dirY*2;
                perso.air=1;
		*framed=2;
        }
      
      else if (perso.air==1)
         { 
           perso.dirY+=GRAVITE;
           perso.air=1;
           perso.basy+=perso.dirY;
           perso.position.y=perso.basy - 60;
           verif=0;
           if(input.droite==1)
        {
		perso.direction=1;
		perso.position.x+=perso.dirX*2;
                perso.basx+=perso.dirX*2;
		*framed=2;
	}
	if(input.gauche==1)
        {
		perso.direction=2;
		perso.position.x-=perso.dirX*2;
                perso.basx -=perso.dirX*2;
		*frameg=2;
		if(*frameg<0)
                {
			*frameg=1;
		}
	}
       
    }
}   
if(input.attaque==1)
{
                /*if(projectile.actif==0)
                {*/
		   	initialiser_attaque();
		    	projectile.actif=1;
                        effet_sonor(assets.attaque);
		/*}*/
}
if (input.save==1)
{
  sauvegarder (score,stage_complet);
}
}
void afficher_hero(int framed,int frameg,SDL_Surface *ecran)
{
	int verif,c;
        SDL_Rect animation[3];
	animation[0].x=0;animation[0].y=0;
	animation[0].w=60;animation[0].h=60;
	animation[1].x=60;animation[1].y=0;
	animation[1].w=60;animation[1].h=60;
	animation[2].x=120;animation[2].y=0;
	animation[2].w=60;animation[2].h=60;
        verif=0;
    
        /*if(perso.direction==1)
        {
	   SDL_BlitSurface(perso.sprite,&animation[framed],ecran,&perso.position);
	}
	if(perso.direction==2)
        {
	    SDL_BlitSurface(perso.sprite,&animation[frameg],ecran,&perso.position);
	}*/
        if(perso.direction==1)
        {
	apply_surface(((perso.position.x)-(camera.x)),((perso.position.y-(camera.y))),perso.sprite,ecran,&animation[framed]);
	}
	if(perso.direction==2)
        {
	    apply_surface(((perso.position.x)-(camera.x)),((perso.position.y-(camera.y))),perso.sprite,ecran,&animation[frameg]);
	}
}

