#include "sauvegarde.h"
#include "hero.h"
#include "gestion.h"

void sauvegarder(int score,int stage_complet)
{
	FILE *fp = NULL;
	int i;
	fp = fopen("save.txt","w");
	if(fp == NULL)
		printf("Erreur de sauvgarde!");
	else{
		fprintf(fp,"%d ",score);
		fprintf(fp,"%d ",perso.position.x);
		fprintf(fp,"%d ",perso.position.y);
		fprintf (fp,"%d",stage_complet);
	}
	fclose(fp);
}
