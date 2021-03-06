#include <SDL.h>
#include <SDL_image.h>



SDL_Window* g_windows = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* g_background = NULL;


bool loadMedia()
{
    bool success = true;
    g_background = IMG_Load("background.png");
    if (g_background == NULL)
    {
        success = false;
    }

    return success;
}


void close()
{
    SDL_FreeSurface(g_background);
    g_background = NULL;
    SDL_DestroyWindow(g_windows);
    g_windows = NULL;
    SDL_Quit();
}

bool init()
{
    bool success = true;
    if (SDL_Init(SDL_INIT_VIDEO) >= 0)
    {
        g_windows = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1200, 600, SDL_WINDOW_SHOWN);
        if (g_windows != NULL)
        {
            gScreenSurface = SDL_GetWindowSurface(g_windows);
        }
    }
    return success;
}


int main(int argc, char* argv[])
{
    if (init() == true)
    {
        if (loadMedia())
        {
            bool is_quit = true;
            SDL_Event e;
            while (is_quit)
            {
                while (SDL_PollEvent(&e) != 0)
                {
                    if (e.type == SDL_QUIT)
                    {
                        is_quit = false;
                    }
                    SDL_BlitSurface(g_background, NULL, gScreenSurface, NULL);
                    SDL_UpdateWindowSurface(g_windows);
                    SDL_RenderPresent;
                }
            }
        }
    }

    close();
    return 0;
}