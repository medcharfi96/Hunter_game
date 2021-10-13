#include "definitions.h"
struct audio
{
	Mix_Chunk *bonus;
	Mix_Chunk *choix;
	Mix_Chunk *attaque;
};

struct audio assets;
void initialiser_son();
void effet_sonor(Mix_Chunk *audio);


