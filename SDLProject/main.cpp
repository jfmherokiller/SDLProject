///Follow the North Star///
///Written by Alec Roberts... made possible using SDL, Code::Blocks, and the ability to live and breathe on this planet.
/***
A game written out of love and passion for my craft.
I hope you enjoyed it enough to peruse the source code.
Thank you.  Thank you so much.
***/

///include SDL and other graphical plugins/layers
#include <cstdlib>
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

///functions
void CheckQuit();
void UpdateScreen();
bool SetupVideo();
void Draw();

///variables
bool running=true;

///window and renderer variables
SDL_Window* MainWindow = NULL;
SDL_Renderer* MainRenderer = NULL;


int main(int arc, char*argvs[])
{

    ///Build Window and
    SetupVideo();

    ///Main Loop
    while(running)
    {
        ///check for SDL being quit
        CheckQuit();

        ///game code


        ///Update the screen
        UpdateScreen();

    }
	return 0;
}

void CheckQuit()
{
        ///check if user has quit
        SDL_Event event;

        if (SDL_PollEvent(&event))
        {
            if(event.type==SDL_QUIT)
            {
                running=false;
            }
        }
}

bool SetupVideo()
{
    ///initialize
    if(SDL_Init(SDL_INIT_EVERYTHING)==-1)
    {
        return false;
    }

    ///create window
    MainWindow=SDL_CreateWindow("Follow the North Star",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,640,480,SDL_WINDOW_RESIZABLE);

    ///check for errors
    if (MainWindow==NULL)
    {
        SDL_Quit();
        return false;
    }

    MainRenderer=SDL_CreateRenderer(MainWindow,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_RenderSetLogicalSize(MainRenderer,640,480);

}

void UpdateScreen()
{
        SDL_SetRenderDrawColor(MainRenderer,0,0,0,0);
        SDL_RenderPresent(MainRenderer);
        SDL_RenderClear(MainRenderer);
}

void Draw()
{
        SDL_SetRenderDrawColor(MainRenderer,0,255,255,0);
        SDL_RenderDrawPoint(MainRenderer,255,255);
}
