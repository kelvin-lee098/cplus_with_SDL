#ifndef SDL_UTILS_H
#define SDL_UTILS_H

#include <iostream>
#include <SDL.h>
#include <string>

void logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal = false);

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer) ;

void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

void waitUntilKeyPressed();

SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren);

// Hàm đưa texture ra renderer (để hiển thị ra màn hình) tại toạ độ (x,y) và giữ nguyên kích cỡ ban đầu của ảnh
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y);

void renderTexture1(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h);
std::string numberToString(int Number);

#endif // SDL_UTILS_H
