#include "son.h"


void initialiser_son()
{
	assets.choix=Mix_LoadWAV("cl.wav");
	assets.bonus=Mix_LoadWAV("star.wav");
	assets.attaque=Mix_LoadWAV("shot.wav");
}

void effet_sonor(Mix_Chunk *audio)
 {
 	 Mix_PlayChannel(-1,audio,0);
 }
