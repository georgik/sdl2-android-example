#include "SDL.h"
#include <stdio.h>

int main(int argc, char* argv[]) {

    SDL_Window *window;                    // Declare a pointer
    SDL_Surface *surface;
    SDL_Texture *texture;
    SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

    // Create an application window with the following settings:
    window = SDL_CreateWindow(
        "An SDL2 window",                  // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        640,                               // width, in pixels
        480,                               // height, in pixels
        SDL_WINDOW_OPENGL                  // flags - see below
    );

    // Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    // The window is open: could enter program loop here (see SDL_PollEvent())
    // Setup renderer
    SDL_Renderer* renderer = NULL;
    renderer =  SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);


    // Set render color to red ( background will be rendered in this color )
    SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255 );

    // Clear winow
    SDL_RenderClear( renderer );

    // Creat a rect at pos ( 50, 50 ) that's 50 pixels wide and 50 pixels high.
    SDL_Rect r;
    r.x = 50;
    if (surface == NULL) {
        r.x=150;
    }
    r.y = 50;
    r.w = 100;
    r.h = 50;

    // Set render color to blue ( rect will be rendered in this color )
    SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );

    // Render rect
    SDL_RenderFillRect( renderer, &r );

    // Display image
    SDL_RenderCopy(renderer, texture, NULL, NULL);

    // Render the rect to the screen
    SDL_RenderPresent(renderer);

    // Render the rect to the screen
    SDL_RenderPresent(renderer);
    SDL_Delay(4000);

    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
    return 0;
}
