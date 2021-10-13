#include "definitions.h"
typedef struct 
{
SDL_Surface* fond;
SDL_Surface* fond2;
SDL_Surface* visible;
SDL_Rect position_background;
}background;
background stage1,stage2;
SDL_Rect camera;
void SetCamera();
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip  );
int collision_map (int a, int b/*,int stage_complet*/);

