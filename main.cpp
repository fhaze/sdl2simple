#include <iostream>
#include "SDL2/SDL.h"

using namespace std;

SDL_Window   *window;
SDL_Renderer *renderer;

int x = 50;
int y = 50;

void render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderClear(renderer);

    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.h = 50;
    r.w = 50;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderFillRect(renderer, &r);
    SDL_RenderPresent(renderer);
}

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
        cout << "SDL cannot init" << endl;

    window = SDL_CreateWindow("SDL2 Teste", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 400, 300,
                                          SDL_WINDOW_OPENGL);
    if (window == nullptr)
        cout << "Window cannot be created" << endl;

    renderer = SDL_CreateRenderer(window, -1, 0);

    if (renderer == nullptr)
        cout << "Renderer cannot init" << endl;

    bool mainLoop = true;
    SDL_Event event;
    while (mainLoop) {
        if (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    mainLoop = false;
                    break;

                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_ESCAPE:
                        case SDLK_q:
                            mainLoop = false;
                            break;
                        case SDLK_RIGHT:
                            x += 50;
                            break;
                        case SDLK_LEFT:
                            x -= 50;
                            break;
                        case SDLK_UP:
                            y -= 50;
                            break;
                        case SDLK_DOWN:
                            y += 50;
                            break;
                    }
                    break;
            }
        }
        render();
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}