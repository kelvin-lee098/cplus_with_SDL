#include <cmath>
#include <cstdlib>
#include <iostream>

#include "painter.h"
#include "SDL_utils.h"

using namespace std;

Painter::Painter(SDL_Window* window, SDL_Renderer* renderer_)
    : renderer(renderer_)
{
    SDL_RenderGetLogicalSize(renderer, &width, &height);
    if (width == 0 && height == 0)
        SDL_GetWindowSize(window, &width, &height);

    setPosition(width/2, height/2);
    setAngle(0);
    setColor(WHITE_COLOR);
    clearWithBgColor(GREY_COLOR);
}

void Painter::setPosition(float x, float y)
{
    this->x = x;
    this->y = y;
}

void Painter::setAngle(float angle)
{
    this->angle = angle - floor(angle/360)*360;
}

void Painter::setColor(SDL_Color color)
{
    this->color = color;
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 0);
}

void Painter::clearWithBgColor(SDL_Color bgColor)
{
    SDL_Color curColor = color;
    setColor(bgColor);
    SDL_RenderClear(renderer);
    setColor(curColor);
}

void Painter::setRandomColor()
{
    Uint8 r = rand() % 256;
    Uint8 g = rand() % 256;
    Uint8 b = rand() % 256;
    SDL_Color color = {r, g, b};
    setColor(color);
}

void refreshScreen(SDL_Window* &window, SDL_Renderer* &renderer, Painter painter, SDL_Texture* &background,SDL_Texture* &skull, int live) {
    painter.clearWithBgColor(BLACK_COLOR);
    painter.setColor(WHITE_COLOR);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    renderTexture1(background, renderer,0,0,800,600);

    for (int i = 1; i <= live; i++) {
        renderTexture1(skull, renderer, 20, 50 + i*25 , 22, 22);
        }
}
