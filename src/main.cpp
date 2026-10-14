#include <iostream>
#include <string>
#include <vector>
using namespace std;
// #include <algorithm>

/* GRAPHICAL LIBRARIES */
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>

/* CUSTOM TYPES */

typedef struct
{
    SDL_Window *s;            // s like screen
    SDL_Renderer *r;          // r like renderer
    const SDL_DisplayMode *m; // m like mode.
} GUI;

/** @brief Initializes the GUI for the game.
 *  @param g The GUI structure to be initialized.
 *  @return The initialized GUI structure.
 *  @details GUI_Init takes in a declared GUI structure. It then initializes a window and it's renderer while setting a logical size for the screen.
 * */
int GUI_Init(GUI &g, int width, int height);

int main()
{
    cout << "Hello, World!" << endl;

    GUI gui;
    int height = 900;
    int width = 1600;

    if (GUI_Init(gui, width, height) != 0) return -1;

    /* Load all sprites required. */
    SDL_Surface *surface = IMG_Load("../assets/entities/User-sheet.png");
    if (surface == NULL)
    {
        cerr << "Loading Sprite Failed: " << SDL_GetError() << endl;
        surface = IMG_Load("../assets/missing-sprite.png");
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(gui.r, surface);

    int k = 0, x = 0, y = 0; // keyframe, x, y
    const SDL_FRect src = {k * 32, 0, 32.0, 32.0};
    const SDL_FRect dest = {x, y, 100.0, 100.0};

    SDL_RenderTexture(gui.r, texture, &src, &dest);

    /* Graphics Rendering */
    SDL_Event event;
    bool running = true;
    while (running)
    {

        /* Event Managment */
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_EVENT_QUIT:
                running = false;
                break;
            case SDL_EVENT_WINDOW_RESIZED:
                
            }
        }
        /* Update the rendering on window. */
        SDL_Delay(10);
    }

    SDL_Delay(1000);
    SDL_DestroyWindow(gui.s);
    SDL_Quit();
    return 0;
}

int GUI_Init(GUI &g, int width, int height)
{

    bool Init = SDL_Init(SDL_INIT_VIDEO);
    if (Init == false)
    {
        cerr << "Initialization error: " << SDL_GetError() << endl;
        return -1;
    }

    /* Acquiring Device's screen size */
    SDL_DisplayID display = SDL_GetPrimaryDisplay();
    if (display == 0)
    {
        cerr << "Error: Could not get Display ID: " << SDL_GetError() << endl;
        return -2;
    }
    g.m = SDL_GetCurrentDisplayMode(display);

    /* Attempt to create a window. */
    g.s = SDL_CreateWindow("MazeFall", g.m->w, g.m->h, SDL_WINDOW_RESIZABLE);
    if (g.s == NULL)
    {
        cerr << "Window Creation Failed: " << SDL_GetError() << endl;
        SDL_Quit();
        return -3;
    }

    /* Attempt to create a window */
    g.r = SDL_CreateRenderer(g.s, NULL);
    if (g.r == NULL)
    {
        cerr << "Renderer Creation Failed: " << SDL_GetError() << endl;
        SDL_DestroyWindow(g.s);
        SDL_Quit();
        return -4;
    }

    /* Set a logical size for rendering */
    SDL_SetRenderLogicalPresentation(g.r, width, height, SDL_LOGICAL_PRESENTATION_LETTERBOX);

    return 0;
}
