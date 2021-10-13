#include "ennemis.h"
#include "map.h"
#include "hero.h"
#include "gestion.h"
#include "attaque.h"
void initialiser_ennemis()
{
	int i;
       for (i=0;i<5;i++)
        {
        enemy[i].image=IMG_Load("enemy.png");
	enemy[i].mort=0;
	enemy[i].vitesse=VITESSE_ENNEMIS;
        }
        enemy[0].position.x=100;
	enemy[0].position.y=500;
        enemy[0].initiale=500;
        enemy[0].finale=700;
        enemy[1].position.x=1000;
	enemy[1].position.y=500;
        enemy[1].initiale=1000;
        enemy[1].finale=1200;
        enemy[2].position.x=1500;
	enemy[2].position.y=500;
        enemy[2].initiale=1500;
        enemy[2].finale=1700;
        enemy[3].position.x=2000;
	enemy[3].position.y=500;
        enemy[3].initiale=2000;
        enemy[3].finale=2200;
        enemy[4].position.x=2500;
	enemy[4].position.y=500;
        enemy[4].initiale=2500;
        enemy[4].finale=2700;
}
void initialiser_ennemis2()
{
	int i;
       for (i=0;i<5;i++)
        {
        enemy[i].image=IMG_Load("enemy.png");
	enemy[i].mort=0;
	enemy[i].vitesse=VITESSE_ENNEMIS;
        }
        enemy[0].position.x=100;
	enemy[0].position.y=500;
        enemy[0].initiale=500;
        enemy[0].finale=700;
        enemy[1].position.x=1500;
	enemy[1].position.y=500;
        enemy[1].initiale=1500;
        enemy[1].finale=3000;
        enemy[2].position.x=2300;
	enemy[2].position.y=500;
        enemy[2].initiale=2300;
        enemy[2].finale=2500;
        enemy[3].position.x=2800;
	enemy[3].position.y=500;
        enemy[3].initiale=2800;
        enemy[3].finale=3000;
        enemy[4].position.x=3500;
	enemy[4].position.y=500;
        enemy[4].initiale=3500;
        enemy[4].finale=3600;
}
void initialiser_ennemis3()
{
	int i;
       for (i=0;i<5;i++)
        {
        enemy[i].image=IMG_Load("enemy.png");
	enemy[i].mort=0;
	enemy[i].vitesse=VITESSE_ENNEMIS;
        }
        enemy[0].position.x=100;
	enemy[0].position.y=500;
        enemy[0].initiale=500;
        enemy[0].finale=700;
        enemy[1].position.x=1700;
	enemy[1].position.y=700;
        enemy[1].initiale=1700;
        enemy[1].finale=3200;
        enemy[2].position.x=2100;
	enemy[2].position.y=2700;
        enemy[2].initiale=2900;
        enemy[2].finale=3200;
        enemy[3].position.x=3500;
	enemy[3].position.y=500;
        enemy[3].initiale=2000;
        enemy[3].finale=2200;
        enemy[4].position.x=2500;
	enemy[4].position.y=500;
        enemy[4].initiale=2500;
        enemy[4].finale=2700;
}
void mouvement_ennemis()
{
   int i;
   if((enemy[0].initiale-enemy[0].position.x)==0)
   {
      enemy[0].vitesse=VITESSE_ENNEMIS;
   }
   else if ((enemy[0].position.x-enemy[0].finale)==0)
   {
      enemy[0].vitesse=-VITESSE_ENNEMIS;
   }
   for (i=0;i<5;i++)
   {
   enemy[i].position.x+=enemy[0].vitesse;
   }
}
void afficher_ennemis(SDL_Surface *ecran)
{
	int i;
     for (i=0;i<5;i++)
        {
           if(enemy[i].mort==0)
           {
		SDL_BlitSurface(enemy[i].image,&camera,ecran,&enemy[i].position);
	   }
        }
}
int collision_joueur_ennemi (int a,int b)
{
 int i,verif;
i=0;  
verif=0;
 do
   {
   if ((a+60>enemy[i].position.x) && (b+30>enemy[i].position.y) && (b+30<enemy[i].position.y+60) && (a+60<enemy[i].position.x+60) && (enemy[i].mort==0))
   {  

      return 1;
      verif=1;
   }
   else if ((a>enemy[i].position.x) && (b+30>enemy[i].position.y) && (b+30<enemy[i].position.y+60) && (a<enemy[i].position.x+60) && (enemy[i].mort==0))
   {  
      verif=1;
      return 2;

   }
   else
    {
    i++;
    return 0;  
    }
   
  }while (i<5 || verif!=1);
}
void tuer_ennemi(int *score)
{
  int i;	
  for (i=0;i<5;i++)
   {
 if(projectile.position.x+20<enemy[i].position.x+60 && projectile.position.x+20>enemy[i].position.x && projectile.position.y<enemy[i].position.y+60 && projectile.position.y>enemy[i].position.y && enemy[i].mort==0) 
        {
		enemy[i].mort=1;
		(*score)= (*score)+500;
                projectile.actif=0;
	}
   }
}
