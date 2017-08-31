#include "SDL.h"
#include "SDL_image.h"
#include <stdio.h>

static char * icon_xpm[] = {
        "32 23 3 1",
        "     c #FFFFFF",
        ".    c #000000",
        "+    c #FFFF00",
        "                                ",
        "            ........            ",
        "          ..++++++++..          ",
        "         .++++++++++++.         ",
        "        .++++++++++++++.        ",
        "       .++++++++++++++++.       ",
        "      .++++++++++++++++++.      ",
        "      .+++....++++....+++.      ",
        "     .++++.. .++++.. .++++.     ",
        "     .++++....++++....++++.     ",
        "     .++++++++++++++++++++.     ",
        "     .++++++++++++++++++++.     ",
        "     .+++++++++..+++++++++.     ",
        "     .+++++++++..+++++++++.     ",
        "     .++++++++++++++++++++.     ",
        "      .++++++++++++++++++.      ",
        "      .++...++++++++...++.      ",
        "       .++............++.       ",
        "        .++..........++.        ",
        "         .+++......+++.         ",
        "          ..++++++++..          ",
        "            ........            ",
        "                                "};

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

    surface = IMG_ReadXPMFromArray(icon_xpm);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                     "Couldn't load texture: %s", SDL_GetError());
        return(2);
    }

    // Set render color to red ( background will be rendered in this color )
    SDL_SetRenderDrawColor( renderer, 220, 220, 220, 255 );

    // Clear winow
    SDL_RenderClear( renderer );

    // Display image
    SDL_Rect dstrect;


    // Load smiley.png and display it.
    // Location of image files for Android is: app/src/main/assets
    SDL_Surface *loadedSurface = IMG_Load("smiley.png");
    if (!loadedSurface) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                     "Couldn't load PNG image: %s", SDL_GetError());
        return(3);
    }

    SDL_Surface *backgroundSurface = IMG_Load("brno-snow.jpg");
    if (!backgroundSurface) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                     "Couldn't load JPG image: %s", SDL_GetError());
        return(4);
    }


    dstrect.x = 0;
    dstrect.y = 0;
    dstrect.w = backgroundSurface->w;
    dstrect.h = backgroundSurface->h;
    SDL_Texture *backgroundTexture = SDL_CreateTextureFromSurface(renderer, backgroundSurface);
    SDL_RenderCopy(renderer, backgroundTexture, NULL, &dstrect);

    dstrect.x = 130;
    dstrect.y = 130;
    dstrect.w = loadedSurface->w;
    dstrect.h = loadedSurface->h;
    SDL_Texture *smileyTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    SDL_RenderCopy(renderer, smileyTexture, NULL, &dstrect);

    dstrect.x = 0;
    dstrect.y = 0;
    dstrect.w = 128;
    dstrect.h = 128;
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);

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
