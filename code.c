#include "code.h"
void loadannimation(imgconfig *image2)
{ 


image2[0].screen=IMG_Load("IMAGE/ANNIMATION/00000.jpg");
image2[1].screen=IMG_Load("IMAGE/ANNIMATION/00001.jpg");
image2[2].screen=IMG_Load("IMAGE/ANNIMATION/00002.jpg");
image2[3].screen=IMG_Load("IMAGE/ANNIMATION/00003.jpg");
image2[4].screen=IMG_Load("IMAGE/ANNIMATION/00004.jpg");
image2[5].screen=IMG_Load("IMAGE/ANNIMATION/00005.jpg");
image2[6].screen=IMG_Load("IMAGE/ANNIMATION/00006.jpg");
image2[7].screen=IMG_Load("IMAGE/ANNIMATION/00007.jpg");
image2[8].screen=IMG_Load("IMAGE/ANNIMATION/00008.jpg");
image2[9].screen=IMG_Load("IMAGE/ANNIMATION/00009.jpg");
image2[10].screen=IMG_Load("IMAGE/ANNIMATION/00010.jpg");
image2[11].screen=IMG_Load("IMAGE/ANNIMATION/00011.jpg");
image2[12].screen=IMG_Load("IMAGE/ANNIMATION/00012.jpg");
image2[13].screen=IMG_Load("IMAGE/ANNIMATION/00013.jpg");
image2[14].screen=IMG_Load("IMAGE/ANNIMATION/00014.jpg");
image2[15].screen=IMG_Load("IMAGE/ANNIMATION/00015.jpg");
image2[16].screen=IMG_Load("IMAGE/ANNIMATION/00016.jpg");
image2[17].screen=IMG_Load("IMAGE/ANNIMATION/00017.jpg");
image2[18].screen=IMG_Load("IMAGE/ANNIMATION/00018.jpg");
image2[19].screen=IMG_Load("IMAGE/ANNIMATION/00019.jpg");
image2[20].screen=IMG_Load("IMAGE/ANNIMATION/00020.jpg");
image2[21].screen=IMG_Load("IMAGE/ANNIMATION/00021.jpg");
image2[22].screen=IMG_Load("IMAGE/ANNIMATION/00022.jpg");
image2[23].screen=IMG_Load("IMAGE/ANNIMATION/00023.jpg");
image2[24].screen=IMG_Load("IMAGE/ANNIMATION/00024.jpg");
image2[25].screen=IMG_Load("IMAGE/ANNIMATION/00025.jpg");
image2[26].screen=IMG_Load("IMAGE/ANNIMATION/00026.jpg");
image2[27].screen=IMG_Load("IMAGE/ANNIMATION/00027.jpg");
image2[28].screen=IMG_Load("IMAGE/ANNIMATION/00028.jpg");
image2[29].screen=IMG_Load("IMAGE/ANNIMATION/00029.jpg");
image2[30].screen=IMG_Load("IMAGE/ANNIMATION/00030.jpg");
image2[31].screen=IMG_Load("IMAGE/ANNIMATION/00031.jpg");
image2[32].screen=IMG_Load("IMAGE/ANNIMATION/00032.jpg");
image2[33].screen=IMG_Load("IMAGE/ANNIMATION/00033.jpg");
image2[34].screen=IMG_Load("IMAGE/ANNIMATION/00034.jpg");
image2[35].screen=IMG_Load("IMAGE/ANNIMATION/00035.jpg");
image2[36].screen=IMG_Load("IMAGE/ANNIMATION/00036.jpg");
image2[37].screen=IMG_Load("IMAGE/ANNIMATION/00037.jpg");
image2[38].screen=IMG_Load("IMAGE/ANNIMATION/00038.jpg");
image2[39].screen=IMG_Load("IMAGE/ANNIMATION/00039.jpg");
image2[40].screen=IMG_Load("IMAGE/ANNIMATION/00040.jpg");
image2[41].screen=IMG_Load("IMAGE/ANNIMATION/00041.jpg");

}
void loadimage(imgconfig *image)
{
image[0].screen=IMG_Load("IMAGE/cursor.png");
image[1].screen=IMG_Load("IMAGE/background.png");
			image[1].position.x=0;
			image[1].position.y=0;
image[2].screen=IMG_Load("IMAGE/new_game.png");
			image[2].position.x=560;
			image[2].position.y=310;
image[3].screen=IMG_Load("IMAGE/new_game2.png");
image[4].screen=IMG_Load("IMAGE/new_game3.png");
image[5].screen=IMG_Load("IMAGE/SETTING1.png");
			image[5].position.x=560;
			image[5].position.y=392;
image[6].screen=IMG_Load("IMAGE/SETTING2.png");
image[7].screen=IMG_Load("IMAGE/SETTING3.png");
image[8].screen=IMG_Load("IMAGE/QUIT1.png");
			image[8].position.x=560;
			image[8].position.y=474;
image[9].screen=IMG_Load("IMAGE/QUIT2.png");
image[10].screen=IMG_Load("IMAGE/QUIT3.png");
image[11].screen=IMG_Load("IMAGE/JOUER.png");
image[12].screen=IMG_Load("IMAGE/BACK.png");
			image[12].position.x=166;
			image[12].position.y=81;		
image[13].screen=IMG_Load("IMAGE/NORMAL.png");
			image[13].position.x=621;
			image[13].position.y=532;
image[14].screen=IMG_Load("IMAGE/FULLSCREEN.png");
			image[14].position.x=756;
			image[14].position.y=532;
image[15].screen=IMG_Load("IMAGE/backgroundsetting.png");
			image[15].position.x=0;
			image[15].position.y=0;
image[16].screen=IMG_Load("IMAGE/VOL.png");
			image[16].position.x=1015;
			image[16].position.y=456;
}



void start(imgconfig *image,int *son ,SDL_Surface *icon)
{
loadimage(image);
SDL_Init(SDL_INIT_VIDEO);
icon=IMG_Load("IMAGE/icon.png");
putenv("SDL_VIDEO_CENTERED=1");
SDL_WM_SetCaption("Back To Life", NULL);//nom de fenetre de programme.
SDL_WM_SetIcon(icon, NULL);//icone de programme.
}



void FREEimage(imgconfig *image)
{ int i;
for(i=0;i<20;i++)
SDL_FreeSurface(image[i].screen);
}





void down(int *prec,imgconfig *image,int *entre)
{if((*prec)==0){(*entre)=1;(*prec)=3;}else{(*prec)++;(*entre)++;}if((*entre)==4){(*entre)=1;(*prec)=0;}}





void up(int *prec,imgconfig *image,int *entre)
{if((*prec)==0){(*entre)=3;(*prec)=1;}else{(*prec)++;(*entre)--;}if((*entre)==0){(*entre)=3;(*prec)=1;}}




void jouer(SDL_Surface *ecran,imgconfig *image,Mix_Music *music2,int *captson,Mix_Chunk *clickson)
{
int continuer=1;
SDL_Event event;
Mix_PlayMusic(music2,-1);
(*captson)=1;
while(continuer)
{	
SDL_BlitSurface(image[11].screen,NULL,ecran,&image[11].position);
SDL_Flip(ecran);
SDL_PollEvent(&event);
	switch (event.type)
	{
		case SDL_KEYDOWN:
		Mix_PlayChannel(-1,clickson,0);
		switch (event.key.keysym.sym)
		{
		case SDLK_ESCAPE:
		SDL_Delay(200);
		continuer=0;
		break;
		}}}}







void setting (SDL_Surface *ecran,imgconfig *image,int *boutonfull,int *captfull,Mix_Chunk *clickson,Mix_Music *music ,int *menu,int *prec)
{
   FILE* fichier = NULL;
	int continuer=1,x,boutonback=0;
	SDL_Event event;
	


while(continuer)
{

	



	SDL_PollEvent(&event);
	switch (event.type)
	{

	case SDL_QUIT:
	continuer=0;
	break;

	case SDL_KEYDOWN:
		{
			Mix_PlayChannel(-1,clickson,0);
		switch (event.key.keysym.sym)
		{
			case SDLK_ESCAPE:
			{
			continuer=0;
			boutonback=1;
			}
			break;
		}
	
		}
		break;
	case SDL_MOUSEMOTION:
		image[0].position.x = event.motion.x;
		image[0].position.y = event.motion.y;

		if	(event.motion.x> 166 && event.motion.x< 310 && event.motion.y> 81 && event.motion.y< 226 )
			{
			boutonback=1;
			}
			
	break;

	case SDL_MOUSEBUTTONDOWN:
		Mix_PlayChannel(-1,clickson,0);
		if(event.button.button == SDL_BUTTON_LEFT)	
		{
			
			if(event.button.x> 757 && event.button.x< 830 && event.button.y> 532 && event.button.y< 605 && (*boutonfull)==0 )
			{
				  fichier = fopen("FICHE/mode.txt", "w");(*boutonfull)=1;(*captfull)=1;
				  fclose(fichier);
			}
			else if(event.button.x> 621 && event.button.x< 695 && event.button.y> 532 && event.button.y< 605 && (*boutonfull)==1 )
				  {remove("FICHE/mode.txt.txt");(*boutonfull)=0;(*captfull)=1;}
			
			else if(event.button.x> 166 && event.button.x< 310 && event.button.y> 81 && event.button.y< 226 )
			{continuer=0;boutonback=1;}
			else if(event.button.x> 716 && event.button.x< 723 && event.button.y> 462 && event.button.y< 476 )
			{
			image[16].position.x=image[0].position.x-10;
			Mix_VolumeMusic(Mix_VolumeMusic(-1)-32);
			Mix_VolumeMusic(Mix_VolumeMusic(-1)-32);
			Mix_VolumeMusic(Mix_VolumeMusic(-1)-32);Mix_VolumeMusic(Mix_VolumeMusic(-1)-32);
			Mix_VolumeMusic(Mix_VolumeMusic(-1)-2400);
			Mix_VolumeChunk(clickson,0);
			}
			else if(event.button.x> 725 && event.button.x< 1036 && event.button.y> 462 && event.button.y< 476 )
			{ x=100 - ((1036 - image[0].position.x)/3.2);
			Mix_VolumeChunk(clickson,x);
			image[16].position.x=image[0].position.x-10;
			Mix_VolumeMusic(Mix_VolumeMusic(-1)-100);
			Mix_VolumeMusic(Mix_VolumeMusic(-1)+x);


			
			}
			
		}

		
	break;

	}

SDL_BlitSurface(image[15].screen,NULL,ecran,&image[15].position);
if(boutonback==1)
{SDL_BlitSurface(image[12].screen,NULL,ecran,&image[12].position);boutonback==0;SDL_Delay(100);}
SDL_BlitSurface(image[12].screen,NULL,ecran,&image[12].position);
if((*boutonfull)==1)
	{SDL_BlitSurface(image[14].screen,NULL,ecran,&image[14].position);}
else if((*boutonfull)==0)
	{SDL_BlitSurface(image[13].screen,NULL,ecran,&image[13].position);}

SDL_BlitSurface(image[16].screen,NULL,ecran,&image[16].position);
SDL_Flip(ecran);





}
(*menu)=0;
(*prec)=0;

}










