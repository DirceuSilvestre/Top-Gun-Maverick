//gcc screen.c -o s -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lm  

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

const int WIDTH = 1280;
const int HEIGHT = 800;
//const int WIDTH = 1280; 1369
//const int HEIGHT = 800;  850

// 1 segundo = 1000
// 1 minuto = 60000
#define fps 90
#define newEnemies 800             //tempo para surgir novos inimigos
#define newEnemies1 3000            //tempo para surgir novos inimigos no simulador
#define newBombs 3500               //tempo para surgir novas bombas
#define fpsEmergeLifeComb 20000     //tempo para surgir tanques de gasolina
#define fpsEmergespecialStar 55000  //tempo para surgir estrelas do laser especial
#define fpsspecialLaser 20000       //tempo que dura enquanto está com o laser especial
#define fpsEnemieBossShooting 5000  //tempo para o Chefão começar a atirar
#define fpsEnemieBossWhileShoot 600 //tempo de duração dos tiros do Chefão (tem que ser menor que o fpsEnemieBossShooting)

SDL_Window *window;
SDL_Renderer *renderer;

SDL_Color color = {255,255,255};
SDL_Color color_blue = {10,10,255};
SDL_Color color_red = {255,10,10};
SDL_Color color_black = {10,10,10};


TTF_Font *fonte;
TTF_Font *fonte1;

SDL_Surface *surface_musicas;
SDL_Surface *surface_volume_musicas;
SDL_Surface *surface_efeitos;
SDL_Surface *surface_volume_efeitos;
SDL_Surface *surface_continues;
SDL_Surface *surface_radio;

SDL_Surface *surface_musicas2;
SDL_Surface *surface_volume_musicas2;
SDL_Surface *surface_efeitos2;
SDL_Surface *surface_volume_efeitos2;
SDL_Surface *surface_continues2;
SDL_Surface *surface_radio2;

SDL_Texture *texture_musicas;
SDL_Texture *texture_volume_musicas;
SDL_Texture *texture_efeitos;
SDL_Texture *texture_volume_efeitos;
SDL_Texture *texture_continues;
SDL_Texture *texture_radio;

SDL_Texture *texture_musicas2;
SDL_Texture *texture_volume_musicas2;
SDL_Texture *texture_efeitos2;
SDL_Texture *texture_volume_efeitos2;
SDL_Texture *texture_continues2;
SDL_Texture *texture_radio2;

SDL_Rect cut_musicas;
SDL_Rect sizeImg_musicas;
SDL_Rect cut_volume_musicas;
SDL_Rect sizeImg_volume_musicas;
SDL_Rect cut_efeitos;
SDL_Rect sizeImg_efeitos;
SDL_Rect cut_volume_efeitos;
SDL_Rect sizeImg_volume_efeitos;
SDL_Rect cut_continues;
SDL_Rect sizeImg_continues;
SDL_Rect cut_radio;
SDL_Rect sizeImg_radio;

SDL_Rect cut_musicas2;
SDL_Rect sizeImg_musicas2;
SDL_Rect cut_volume_musicas2;
SDL_Rect sizeImg_volume_musicas2;
SDL_Rect cut_efeitos2;
SDL_Rect sizeImg_efeitos2;
SDL_Rect cut_volume_efeitos2;
SDL_Rect sizeImg_volume_efeitos2;
SDL_Rect cut_continues2;
SDL_Rect sizeImg_continues2;
SDL_Rect cut_radio2;
SDL_Rect sizeImg_radio2;

typedef struct Element {
    char name[50];
    SDL_Surface *Surface;
    SDL_Texture *Texture;
    SDL_Rect cut;
    SDL_Rect sizeImg;
    int status;
} Element;

Element setElement(char name[50], SDL_Surface *Surface, SDL_Rect cut, SDL_Rect sizeImg){
    Element element = {
        .Surface = Surface,
        .cut = cut,
        .sizeImg = sizeImg,
        .status = 0
    };    
    strcpy(element.name,name);
    element.Texture = SDL_CreateTextureFromSurface(renderer, element.Surface);
    return element;
};

SDL_Rect createRect(float x, float y, float w, float h){
    SDL_Rect rect = {
        .x = x,
        .y = y,
        .w = w,
        .h = h
    };
    return rect;
}

//playSong.c
Mix_Music *music;
Mix_Chunk *sound;
Mix_Chunk *shot;
Mix_Chunk *explosion;
#include "playSong.c"

Element credits;
#include "credits.c"

//options.c
Element options_image;
Element star_options[6];
#include "options.c"

Element historia1[44];
Element historia2[53];
Element plane;
Element letra1;
Element letra2;
#include "history.c"

Element primeiro;
Element primeiro_ponto;
Element segundo;
Element segundo_ponto;
Element terceiro;
Element terceiro_ponto;
Element quarto;
Element quarto_ponto;
Element quinto;
Element quinto_ponto;
Element sexto;
Element sexto_ponto;
#include "topguns.c"


typedef struct Ship{
    Element element;
    int life;
    int specialLaser;
} Ship;

Ship setShip(Element element, int life){
    Ship ship = {
        .element = element,
        .life = life,
        .specialLaser = 0
    };
    return ship;
};

typedef struct DestructiveObject{
    Element element;
    int lifeTaken;
    int status;
} DestructiveObject;

DestructiveObject setDestructiveObject(Element element, int lifeTaken){
    DestructiveObject destructiveObject = {
        .element = element,
        .lifeTaken = lifeTaken,
        .status = 0
    };
    return destructiveObject;
};

typedef struct Enemie{
    Element element;
    int heart;
    int status;
    int directionX;
    int directionY;
} Enemie;

Enemie setEnemie(Element element, int heart, int directionX,  int directionY){
    Enemie enemie = {
        .element = element,
        .heart = heart,
        .status = 0,
        .directionX = directionX,
        .directionY = directionY,
    };
    return enemie;
};

void gameover(SDL_Window *, SDL_Renderer *);

Element scenery;
Element up_ship1;
Element aircraft_carrier;
Ship ship1;
Element midShip1;
int MAX_LASERS = 50;
DestructiveObject lasers[50];
Element life;
Element score;
int MAX_ENEMIES = 4;
Enemie enemies[4];
int MAX_EXPLOSIONS = 50;
Element explosions[50];
Element lifeComb;
Element specialStar;
Enemie enemieBoss;
int MAX_ENEMIEBOSSLASERS = 50;
DestructiveObject enemieBossLasers[50];
SDL_Rect explosionPoint;
int MAX_BOMBS = 2;
Enemie bombs[2];
Element decolar[26];
#include "game.c"

//menu.c
Element title;
Element star;
Element press_enter;
Element history_name[2];
Element fly_name[2];
Element topguns_name[2];
Element simulator_name[2];
Element options_name[2];
Element credits_name[2];
#include "menu.c"

//opening.c
Element openingElement;
#include "opening.c"

Element texto1;
Element texto2;
Element texto3;
Element texto4;
#include "gameover.c"

Element retorno[40];
#include "tribunal.c"

SDL_Surface *text_surface;

SDL_Texture *texture_palavra;

SDL_Rect corte_img_simulador;
SDL_Rect tamanho_img_simulador;
Element parabens;
Element novoRecorde;
#include "gravarRecorde.c"

#include "fotoRecorde.c"

int MAX_LASERS1 = 50;
int MAX_ENEMIES1 = 4;
int MAX_EXPLOSIONS1 = 50;
int MAX_ENEMIEBOSSLASERS1 = 50;
int MAX_BOMBS1 = 2;
Element mensagem1;
Element mensagem2;
Element mensagem3;
Element mensagem4;
Element mensagem5;
#include "simulador.c"

Element final[45];
#include "endgame.c"

int main( )
{
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow(
        "TOP GUN 2 MAVERICK", 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, 
        WIDTH, 
        HEIGHT, 
        0);
    renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

    TTF_Init();

    fonte = TTF_OpenFont("TOP-GUN.ttf", 48);
    fonte1 = TTF_OpenFont("/usr/share/fonts/truetype/dejavu/DejaVuSerif-Bold.ttf", 48);

    Mix_Init(MIX_INIT_MP3);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);
    Mix_VolumeMusic(128);


    playSound(1);

    while( 1 )
    {
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    Mix_Quit();
                    TTF_Quit();
                    SDL_DestroyRenderer(renderer);
                    SDL_DestroyWindow(window);
                    SDL_Quit();
                    return 0;
                    break;
            }
        }

        opening(window, renderer);
        break;

        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
        SDL_Delay(fps);
    }

    return 0;
}