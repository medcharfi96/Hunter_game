#include "map.h"
#include "hero.h"

void initialiser_niveau()
{
        /*if (stage_complet==0)
        {*/
        stage1.fond= IMG_Load("map.png");
        stage1.fond2=IMG_Load("mapco.png");
	stage1.position_background.x = 0;
	stage1.position_background.y = 0;
        /*}*/
        /*else if (stage_complet==1)
        {
        
        /*}*/
 
}
void initialiser_niveau2()
{
        stage2.fond= IMG_Load("map2.jpg");
        stage2.fond2=IMG_Load("mapco2.jpg");
	stage2.position_background.x = 0;
	stage2.position_background.y = 0;
}
void afficher_niveau(SDL_Surface *ecran,int stage_complet)
{
    SDL_BlitSurface (stage1.fond,&camera,ecran,&stage1.position_background); 
}
void afficher_niveau2 (SDL_Surface *ecran)
{
   
    SDL_BlitSurface (stage2.fond,&camera,ecran,&stage2.position_background); 
}
void SetCamera()
{
     camera.x = ( perso.position.x + (perso.sprite->w) / 2 ) - SCREEN_WIDTH / 2;
    camera.y = ( perso.position.y + (perso.sprite->h) / 2 ) - SCREEN_HEIGHT / 2;

    //Keep the camera in bounds.
    if( camera.x < 64 )
    {
        camera.x = 0;
    }
    if( camera.y < 0 )
    {
        camera.y = 0;
    }
    if( camera.x > 5000 - camera.w)
    {
        camera.x = 5000 - camera.w;
    }
    if( camera.y > 600 - camera.h )
    {
        camera.y = 600 - camera.h;
    }

}


void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip  )
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface( source, clip, destination, &offset );
}
SDL_Color GetPixel (SDL_Surface* pSurface,int x,int y)
{
  SDL_Color color;
  Uint32 col= 0;
  char* pPosition = (char*) pSurface->pixels;
  pPosition += (pSurface->pitch * y);
  pPosition += (pSurface->format->BytesPerPixel * x);
  memcpy (&col,pPosition,pSurface->format->BytesPerPixel);
  SDL_GetRGB (col,pSurface->format,&color.r,&color.g,&color.b);
 return (color);
}
int collision_map (int a, int b)
{
  SDL_Color couleure;
  int d;
  couleure=GetPixel (stage1.fond2,a,b);
  if (couleure.r==255 && couleure.g==255 && couleure.b==255)
  {
     d=1;
  }
  else
  {
    d=0;
  }
  return d;
}
int collision_map2 (int a, int b)
{
  SDL_Color couleure;
  int d;
  couleure=GetPixel (stage2.fond2,a,b);
  if (couleure.r==255 && couleure.g==255 && couleure.b==255)
  {
     d=1;
  }
  else
  {
    d=0;
  }
  return d;
}
