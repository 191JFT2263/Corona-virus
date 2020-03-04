#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#ifndef DEF_CONSTANTES
#define DEF_CONSTANTES //evite les inclustions infinies.

typedef struct imgconfig
{
SDL_Surface *screen;
SDL_Rect position;

}imgconfig;



//load
void loadannimation(imgconfig *image2);
void loadimage(imgconfig *image);
void loadmusic(Mix_Music *music);



//star
void start(imgconfig *image,int *son,SDL_Surface *icon);

//jeu
void jouer(SDL_Surface *ecran,imgconfig *image,Mix_Music *music2,int *captson,Mix_Chunk *clickson);



//setting
void setting (SDL_Surface *ecran,imgconfig *image,int *boutonfull,int *captfull,Mix_Chunk *clickson,Mix_Music *music ,int *menu,int *prec);


// up-down
void down(int *prec,imgconfig *image,int *entre);
void up(int *prec,imgconfig *image,int *entre);




//free
void FREEimage(imgconfig *image);
void FREEmusic(Mix_Music *music);








#define  L_F	1280
#define  H_F	720

#endif
