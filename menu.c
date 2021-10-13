#include "menu.h"
#include "son.h"
int menu (SDL_Surface *ecran)
{
    SDL_Surface *background = NULL, *message1 = NULL, *message2= NULL, *message3 =NULL,*message4=NULL,*message1s=NULL;
    SDL_Surface *message2s=NULL,*message3s=NULL,*message4s=NULL;
    SDL_Rect positionbackground,positionmessage1,positionmessage2,positionmessage3,positionmessage4;
    SDL_Rect positionmessage1s,positionmessage2s,positionmessage3s,positionmessage4s;
    SDL_Event event1,event2;
    int continuer1=1;
    int continuer2=1;
    positionbackground.x = 0;
    positionbackground.y = 0;
    positionmessage1.x=10;
    positionmessage1.y=10;
    positionmessage1s.x=10;
    positionmessage1s.y=10;
    positionmessage2.x=10;
    positionmessage2.y=120;
    positionmessage2s.x=10;
    positionmessage2s.y=120;
    positionmessage3.x=10;
    positionmessage3.y=230;
    positionmessage3s.x=10;
    positionmessage3s.y=230;
    positionmessage4.x=10;
    positionmessage4.y=340;
    positionmessage4s.x=10;
    positionmessage4s.y=340;
    background =IMG_Load("background.png");
    message1=IMG_Load("new game.png");
    message2=IMG_Load ("loadgame.png");
    message3=IMG_Load ("help.png");
    message4=IMG_Load ("exit.png");
    message1s=IMG_Load ("newgamePRESSED.png");
    message2s=IMG_Load ("loadgamePRESSED.png");
    message3s=IMG_Load ("helpPRESSED.png");
    message4s=IMG_Load ("exitPRESSED.png");
   
  while (continuer1==1)
  {   
    SDL_WaitEvent(&event1);
      continuer2=1;
        switch(event1.type)
        {
            case SDL_QUIT:
                continuer1= 0;
                break;
            case SDL_MOUSEMOTION:
            if (event1.motion.x<210 && event1.motion.x>10 && event1.motion.y>10 && event1.motion.y<110)
            {
           
           SDL_BlitSurface(background, NULL, ecran, &positionbackground);
           SDL_BlitSurface(message1s, NULL, ecran, &positionmessage1s);
           SDL_BlitSurface(message2, NULL, ecran, &positionmessage2);
           SDL_BlitSurface(message3, NULL, ecran, &positionmessage3);
           SDL_BlitSurface(message4, NULL, ecran, &positionmessage4);
            }
           else if (event1.motion.x<210 && event1.motion.x>10 && event1.motion.y>120 && event1.motion.y<220)
            {
           SDL_BlitSurface(background, NULL, ecran, &positionbackground);
           SDL_BlitSurface(message1, NULL, ecran, &positionmessage1);
           SDL_BlitSurface(message2s, NULL, ecran, &positionmessage2s);
           SDL_BlitSurface(message3, NULL, ecran, &positionmessage3);
           SDL_BlitSurface(message4, NULL, ecran, &positionmessage4);
            }
           else if (event1.motion.x<210 && event1.motion.x>10 && event1.motion.y>230 && event1.motion.y<330)
            {
             SDL_BlitSurface(background, NULL, ecran, &positionbackground);
           SDL_BlitSurface(message1, NULL, ecran, &positionmessage1);
           SDL_BlitSurface(message2, NULL, ecran, &positionmessage2);
           SDL_BlitSurface(message3s, NULL, ecran, &positionmessage3s);
           SDL_BlitSurface(message4, NULL, ecran, &positionmessage4);
            }
           else if (event1.motion.x<210 && event1.motion.x>10 && event1.motion.y>340 && event1.motion.y<440)
            {
           SDL_BlitSurface(background, NULL, ecran,&positionbackground);
           SDL_BlitSurface(message1, NULL, ecran, &positionmessage1);
           SDL_BlitSurface(message2, NULL, ecran, &positionmessage2);
           SDL_BlitSurface(message3, NULL, ecran, &positionmessage3);
           SDL_BlitSurface(message4s, NULL, ecran, &positionmessage4s);
           
            }
          else
            {
           SDL_BlitSurface(background, NULL, ecran,&positionbackground);
           SDL_BlitSurface(message1, NULL, ecran, &positionmessage1);
           SDL_BlitSurface(message2, NULL, ecran, &positionmessage2);
           SDL_BlitSurface(message3, NULL, ecran, &positionmessage3);
           SDL_BlitSurface(message4, NULL, ecran, &positionmessage4);
           }
           SDL_Flip(ecran);
           break;
           
           case SDL_MOUSEBUTTONUP:
           if (event1.button.x<210 && event1.button.x>10 && event1.button.y>10 && event1.button.y<110)
           {
               
               return 1;
               effet_sonor(assets.choix);
               continuer1=0;
               
           }
            else if (event1.button.x<210 && event1.button.x>10 && event1.button.y>120 && event1.button.y<220)
            {    
                 return 2;
                 
                 effet_sonor(assets.choix);
                 continuer1=0;
            }
           else if (event1.button.x<210 && event1.button.x>10 && event1.button.y>230 && event1.button.y<330)
            {
                effet_sonor(assets.choix);
            }            
           else if (event1.button.x<210 && event1.button.x>10 && event1.button.y>340 && event1.button.y<440)
            {
              return 0;   
              continuer1=0;
         
            }
          break;
}
   
}
    SDL_FreeSurface(background);
    SDL_FreeSurface(message1);
    SDL_FreeSurface(message2);
    SDL_FreeSurface(message3);
    SDL_FreeSurface(message4);
    
    /*Mix_FreeChunk(selection);*/
    /*SDL_Quit();*/  
}   
