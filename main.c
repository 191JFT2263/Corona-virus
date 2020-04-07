#include "code.h"
int main(int argc,char *argv[]){
SDL_Event event;FILE* fichier = NULL;
int continuer=1,boutonfull,son,captson=0,captfull=0,boutonmenu1,boutonmenu2,boutonmenu3;
imgconfig image[20],image2[200];
SDL_Surface *ecran = NULL,*icon= NULL;
SDL_Rect positionClic,positionSouris;
int k=0,resultat;

TTF_Font *fonttest=NULL;
SDL_Color colorCoor={1,254,254};
SDL_Surface *coordinates;
SDL_Rect coordinatespos;


TTF_Init();
coordinatespos.x=1100;
coordinatespos.y=650;
fonttest=TTF_OpenFont("IMAGE/font.ttf",40);
coordinates=TTF_RenderText_Blended (fonttest,"Welcome",colorCoor);

start(image,&son,icon);



fichier = fopen("FICHE/mode.txt", "r");
if (fichier != NULL)
    	{ecran= SDL_SetVideoMode(L_F,H_F,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN );
	boutonfull=1;fclose(fichier);}
else{
ecran = SDL_SetVideoMode(L_F,H_F,32,SDL_HWSURFACE | SDL_DOUBLEBUF ); //fenetre de programme. | SDL_NOFRAME |SDL_FULLSCREEN
boutonfull=0;
    }



loadannimation(image2);

if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2,1024) == -1) //Mixer init music (22050) old 2048
{
printf("%s", Mix_GetError());
}



Mix_Chunk *clickson=Mix_LoadWAV("MUSIC/click.wav");
Mix_Music *music=Mix_LoadMUS("MUSIC/intro.mp3"),*music2=Mix_LoadMUS("MUSIC/music-1.mp3");
Mix_PlayMusic(music,-1);


//SDL_ShowCursor(SDL_DISABLE);
int prec=0,entre,i=0;
while(continuer)
{
	if(captson==1){Mix_PlayMusic(music,-1);captson=0;}
if(captfull==1)
{
fichier = fopen("FICHE/mode.txt", "r");
if (fichier != NULL)
    	{
	ecran= SDL_SetVideoMode(L_F,H_F,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN );
	boutonfull=1;

	fclose(fichier);
    	}
else
	{
	ecran = SDL_SetVideoMode(L_F,H_F,32,SDL_HWSURFACE | SDL_DOUBLEBUF  ); //fenetre de programme. | SDL_NOFRAME |SDL_FULLSCREEN
        boutonfull=0;
	}
captfull=0;
}



SDL_BlitSurface(image2[i].screen,NULL,ecran,&image[1].position);
if(k==10)
{i++;
k=0;
}
k++;
if(i==40)i=0;
SDL_BlitSurface(image[2].screen,NULL,ecran,&image[2].position);
SDL_BlitSurface(image[5].screen,NULL,ecran,&image[5].position);
SDL_BlitSurface(image[8].screen,NULL,ecran,&image[8].position);

SDL_BlitSurface(coordinates,NULL,ecran,&coordinatespos);
if(entre==1 || boutonmenu1==1)
{SDL_BlitSurface(image[3].screen,NULL,ecran,&image[2].position);}
else if(entre==2 || boutonmenu2==1)
{SDL_BlitSurface(image[6].screen,NULL,ecran,&image[5].position);}
else if(entre==3 || boutonmenu3==1)
{SDL_BlitSurface(image[9].screen,NULL,ecran,&image[8].position);}





	SDL_PollEvent(&event);
	switch (event.type)
{

	case SDL_QUIT:
	continuer=0;
	break;
	case SDL_KEYDOWN:
		SDL_Delay(100);
		Mix_PlayChannel(-1,clickson,0);
		switch (event.key.keysym.sym)
		{

		case SDLK_ESCAPE:
		continuer=0;
    break;

    case SDLK_p:
    enigme(image,ecran,&resultat);
    break;
		case SDLK_j:
		SDL_BlitSurface(image[4].screen,NULL,ecran,&image[2].position);
		jouer(ecran,image,music2,&captson,clickson);
		SDL_Flip(ecran);
		SDL_Delay(100);
		break;

		case SDLK_UP:
		up(&prec,image,&entre);SDL_Delay(100);break;

		case SDLK_DOWN:
		down(&prec,image,&entre);SDL_Delay(100);break;

		case SDLK_KP_ENTER:
		Mix_PlayChannel(-1,clickson,0);
		switch (entre)
		{
		case 1:	SDL_BlitSurface(image[4].screen,NULL,ecran,&image[2].position);
			SDL_Flip(ecran);
			SDL_Delay(100);
			jouer(ecran,image,music2,&captson,clickson);
			break;


		case 2:	SDL_BlitSurface(image[7].screen,NULL,ecran,&image[5].position);
			SDL_Flip(ecran);
			SDL_Delay(100);
			setting(ecran,image,&boutonfull,&captfull,clickson,music,&entre,&prec);
			break;


		case 3:	SDL_BlitSurface(image[10].screen,NULL,ecran,&image[8].position);
			SDL_Flip(ecran);
			SDL_Delay(100);
			exit(0);
			break;
		}
		break;

		}

	case SDL_MOUSEBUTTONDOWN:
		Mix_PlayChannel(-1,clickson,0);
		if(event.button.button == SDL_BUTTON_LEFT)
		{
			if(event.button.x> 570 && event.button.x< 710 && event.button.y> 320 && event.button.y< 366)
			{

			SDL_BlitSurface(image[4].screen,NULL,ecran,&image[2].position);
			SDL_Flip(ecran);
			SDL_Delay(100);
			jouer(ecran,image,music2,&captson,clickson);


			}
			else if(event.button.x> 570 && event.button.x< 710 && event.button.y> 402 && event.button.y< 447)
			{

			SDL_BlitSurface(image[7].screen,NULL,ecran,&image[5].position);
			SDL_Flip(ecran);
			SDL_Delay(100);
			setting(ecran,image,&boutonfull,&captfull,clickson,music,&entre,&prec);
			}
			else if(event.button.x > 570 && event.button.x < 710 && event.button.y > 485 && event.button.y< 530 )
			{
			SDL_BlitSurface(image[10].screen,NULL,ecran,&image[8].position);
			SDL_Flip(ecran);
			SDL_Delay(100);

			exit(0);
			}
		}
	break;


	case SDL_MOUSEMOTION:

		image[0].position.x = event.motion.x;image[0].position.y = event.motion.y;
		if(event.motion.x> 570 && event.motion.x< 710 && event.motion.y> 320 && event.motion.y< 366 )
		{
			SDL_BlitSurface(image[3].screen,NULL,ecran,&image[2].position);entre=1;

		}
		if(event.motion.x> 570 && event.motion.x< 710 && event.motion.y> 402 && event.motion.y< 447 )
		{
			SDL_BlitSurface(image[6].screen,NULL,ecran,&image[5].position);entre=2;
		}

		else if(event.motion.x> 570 && event.motion.x< 710 && event.motion.y> 485 && event.motion.y< 530 )
		{
			SDL_BlitSurface(image[9].screen,NULL,ecran,&image[8].position);entre=3;

		}
		break;


}



//SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,25,25,255));

SDL_BlitSurface(image[0].screen,NULL,ecran,&image[0].position);
SDL_Flip(ecran);





} //while continuer.




SDL_Quit();Mix_FreeMusic(music);SDL_FreeSurface(ecran);SDL_FreeSurface(icon);FREEimage(image);TTF_Quit();
return EXIT_SUCCESS;
}
