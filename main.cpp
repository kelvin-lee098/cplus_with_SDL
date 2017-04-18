#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cctype>
#include <vector>
#include <fstream>
#include <chrono>

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include "SDL_utils.h"
#include "painter.h"
#include "hangman.h"

using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const string WINDOW_TITLE = "Hang Man";

int main(int argc, char* argv[])
{
      //srand(time(0));
    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer);

    SDL_Texture* image = loadTexture("nen.bmp", renderer);
    renderTexture1(image, renderer, 0,0,800,600);

    TTF_Font* font = NULL;
    font = TTF_OpenFont("dc_s.ttf", 21);

    TTF_Font* font1 = NULL;
    font1 = TTF_OpenFont("ULTRA9.ttf",21);

    if (font == NULL && font1 == NULL)
    {
        cout << "font error !" << endl;
    }

    SDL_Surface* name = TTF_RenderText_Solid(font, "Hang Man", RED_COLOR);
    SDL_Texture* title_name = SDL_CreateTextureFromSurface(renderer, name);

    SDL_Surface* start_game = TTF_RenderText_Solid(font1, "Start", CYAN_COLOR);
    SDL_Texture* title_startgame = SDL_CreateTextureFromSurface(renderer, start_game);

    SDL_Surface* exit_game = TTF_RenderText_Solid(font1, "Exit", CYAN_COLOR);
    SDL_Texture* title_exitgame = SDL_CreateTextureFromSurface(renderer, exit_game);

    renderTexture1(title_name, renderer, 200, 50, 390, 130);
    renderTexture1(title_startgame, renderer, 350, 290, 100, 30);
    renderTexture1(title_exitgame, renderer, 370, 370, 50, 30);

    SDL_RenderPresent(renderer);

    SDL_Event e;

    while (true) {

        SDL_Delay(0);

        if ( SDL_WaitEvent(&e) == 0) continue;

        if (e.type == SDL_QUIT) break;

        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) break;

        if (e.type == SDL_MOUSEBUTTONDOWN) {

            if (e.button.x >= 350 && e.button.x <= 450 && e.button.y >= 290 && e.button.y <= 320)
                {
                    SDL_Texture* background = loadTexture("rope2.bmp", renderer);
                    SDL_Texture* skull = loadTexture("red-skull.bmp", renderer);
                    SDL_Texture* gameover = loadTexture("game_over.bmp", renderer);
                    SDL_Texture* cot = loadTexture("(7).bmp", renderer);

                    if (background == nullptr || gameover == nullptr || skull == nullptr) {
                            SDL_DestroyTexture(background);
                            SDL_DestroyTexture(gameover);
                            SDL_DestroyTexture(skull);
                            quitSDL(window, renderer);
                        }

// annoy application action bamboo ban background beat control car desk doll double engineer england egg employment facebook funny finger friday food hello help house hidden kitchen kicker kill ill information jacket job lemon lol link mom mention man music night open orange park pull quick quiet ring run soccer success talent thill tell university unions usually vest vietnam xyz wonder walk winter young yard zizax

                    SDL_Surface* lives = TTF_RenderText_Solid(font1, "Lives", WHITE_COLOR);
                    SDL_Texture* title_live = SDL_CreateTextureFromSurface(renderer, lives);

                    SDL_Surface* vach = TTF_RenderText_Solid(font1, "-", CYAN_COLOR);
                    SDL_Texture* ve_vach = SDL_CreateTextureFromSurface(renderer, vach);

                    SDL_RenderPresent(renderer);

                    Painter painter(window, renderer);
                    int live = 7 ;

                    refreshScreen(window, renderer, painter, background, skull, live);

                    renderTexture1(title_live,renderer, 8, 20, 43, 20);
                    renderTexture1(cot, renderer, 200, 0, 200, 300);

///////////////////////////////////////////////////////////////////////////////////
                    string word = chooseWord(dataFile);
                    string GuessWord = string(word.length(),'-');
                    string badguess = "";
                    srand(time(0));

                    if(e.type == SDLK_0){
                            SDL_Texture* man = loadTexture("(2).bmp", renderer);
                            renderTexture1(man, renderer, 200, 50, 100,200);
                            SDL_RenderPresent(renderer);
                    }
   //........................//chay hangman .........................................................................
                    int j;
                    for (j = 1; j <= (word.length()); j++) {
                            renderTexture1(ve_vach, renderer, 50 + j*55 , 450 , 60, 100);
                        }

//*****************************************************************************************************
                        SDL_DestroyTexture(background);
                        SDL_DestroyTexture(gameover);
                        SDL_DestroyTexture(skull);
                        SDL_DestroyTexture(title_live);

                        SDL_FreeSurface(lives);
                    }


            else if (e.button.x >= 370 && e.button.x <= 420 && e.button.y >= 370 && e.button.y <= 420)
                     quitSDL(window, renderer);
            }
        }
    waitUntilKeyPressed();
    quitSDL(window, renderer);
    return 0;
}

// DONE !!!

