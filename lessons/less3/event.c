// event.c - появляется окно, исчезает по нажатию кнопки

#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>

const int SCREEN_WIDTH = 640;//Screen dimension constants
const int SCREEN_HEIGHT = 480;

SDL_Window* gWindow = NULL;        //The window we'll be rendering to
SDL_Surface* gScreenSurface = NULL;//The surface contained by the window
SDL_Surface* gXOut = NULL;         //The image we will load and show on the screen

bool init()
{
  //Initialize SDL
  if( SDL_Init( SDL_INIT_VIDEO ) != 0 )
    return false;

  //Create window
  gWindow = SDL_CreateWindow( "less3", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

  if( gWindow == NULL )
    return false;

  //Get window surface
  gScreenSurface = SDL_GetWindowSurface( gWindow );
    
  return true;
}

bool loadMedia()
{
  //Load splash image
  gXOut = SDL_LoadBMP( "x.bmp" );

  if( gXOut == NULL )
    return false;

  return true;
}

void close()
{
  //Deallocate surface
  SDL_FreeSurface( gXOut );

  //Destroy window
  SDL_DestroyWindow( gWindow );

  //Quit SDL subsystems
  SDL_Quit();
}

int main( int argc, char* args[] )
{
  printf("hello world");
  //Start up SDL and create window

  /*if( !init() )
    return 1;

    //Load media
  if( !loadMedia() )
    return 1;
  			
  //Main loop flag
  bool quit = false;

  //Event handler
  SDL_Event e;

  //While application is running
  while( !quit )
  {
    //Handle events on queue
    while( SDL_PollEvent( &e ) != 0 )
    {
      //User requests quit
      if( e.type == SDL_QUIT )
      {
	quit = true;
      }
    }

  //Apply the image
  SDL_BlitSurface( gXOut, NULL, gScreenSurface, NULL );
			
  //Update the surface
  SDL_UpdateWindowSurface( gWindow );
  }
 
  //Free resources and close SDL

  close();
  */
  return 0;
}
