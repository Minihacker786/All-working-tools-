#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

int main(int argc, char* argv[]) {
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Surface* surface;
    SDL_Texture* texture;
    SDL_Rect rect;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init failed: %s\n", SDL_GetError());
        return 1;
    }

    // Create window and renderer
    window = SDL_CreateWindow("Minihack786", SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Create blue background
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderClear(renderer);

    // Create white text
    surface = SDL_CreateRGBSurface(0, 0, 0, 32, 0, 0, 0, 0);
    SDL_Color color = { 255, 255, 255 };
    SDL_Surface* textSurface = TTF_RenderText_Solid(TTF_OpenFont("DejaVuSans.ttf", 24), "Minihack786", color);
    texture = SDL_CreateTextureFromSurface(renderer, textSurface);
    rect.x = 200;
    rect.y = 200;
    rect.w = textSurface->w;
    rect.h = textSurface->h;
    SDL_RenderCopy(renderer, texture, NULL, &rect);

    // Show window
    SDL_RenderPresent(renderer);

    // Wait for user to close window
    SDL_Event event;
    while (SDL_WaitEvent(&event)) {
        if (event.type == SDL_QUIT) {
            break;
        }
    }

    // Cleanup and exit
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
