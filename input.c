#include "input.h"

void getinput(SDL_Event event)
{
	while (SDL_PollEvent(&event))
        {
		switch (event.type)
                 {	
			case SDL_QUIT:
				exit(0);
				break;
			
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
                                {
					case SDLK_UP:
						input.haut = 1;
						break;
					
					case SDLK_DOWN:
						input.bas = 1;
						break;
						
					case SDLK_LEFT:
						input.gauche = 1;
						break;
						
					case SDLK_RIGHT:
						input.droite = 1;
						break;
					case SDLK_w:
					    input.attaque=1;
					    break;
					case SDLK_ESCAPE:
						exit(0);
						break;
					case SDLK_SPACE:
                                        input.save=1;
                                        break;
					default:
					break;
				}
				break;
			
			case SDL_KEYUP:
				switch (event.key.keysym.sym){
					case SDLK_UP:
						input.haut = 0;
						break;
					
					case SDLK_DOWN:
						input.bas = 0;
						break;
						
					case SDLK_LEFT:
						input.gauche = 0;
						break;
						
					case SDLK_RIGHT:
						input.droite = 0;
						break;
					case SDLK_w:
					    input.attaque = 0;
					    break;
					case SDLK_SPACE:
                                        input.save=0;
                                        break;
					default:
						break;
				}
				break;
		}
}
}
