#include "attaque.h"
#include "hero.h"
#include "gestion.h"
#include "map.h"
void initialiser_attaque()
{
	projectile.position.x=perso.position.x;
	projectile.position.y=perso.position.y+5;
	projectile.image=IMG_Load("balle.png");
	projectile.actif=0;
}

void update_attaque()
{
	if(projectile.actif==1)
{
		if(perso.direction==1)
                   {
		projectile.position.x+=15;
		    if(projectile.position.x>5000)
                    {
			    projectile.actif=0;
                             SDL_FreeSurface (projectile.image);
		    }
	    }
	    if(perso.direction==2)
            {
		    projectile.position.x-=15;
		    if(projectile.position.x<0)
                    {
			    projectile.actif=0;
                            SDL_FreeSurface (projectile.image);
		    }
	    }
	}
}

void afficher_attaque (SDL_Surface *ecran)
{
        if(projectile.actif==1)
        {
		SDL_BlitSurface(projectile.image,&camera,ecran,&projectile.position);
	} 
        
}
