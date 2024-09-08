// less1_window.c - первый урок, вывод окна на экран

#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>

const int SCREEN_WIDTH = 640;          // размеры экрана
const int SCREEN_HEIGHT = 480;

int main( int argc, char* args[] )     // SDL требует именно такие аргументы функции main() для корректной работы
{
  SDL_Window* window = NULL;           // объявляем окно, которое будем создавать
  SDL_Surface* screenSurface = NULL;   // поверхность экрана внутри окна 

  // инициализация SDL
  if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) // ошибка инициализации - вернет -1
    printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
  // флаг SDL_INIT_VIDEO - использование видео-подсистемы
  // SDL_GetError() - возвращает описание ошибки

  else                                 // создаем окно 
  {
    window = SDL_CreateWindow( "HELLO SDL2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    // "HELLO SDL2" - первый аргумент-  заголовок окна
    // следующие два аргумента - кооринаты x и y в которых создается окно
    // SDL_WINDOWPOS_UNDEFINED - если координаты не важны
    // следующие два аргумента ширина и высота окна
    // флаг SDL_WINDOW_SHOWN- показать окно при его создании

    if( window == NULL ) // в случае ошибки  SDL_CreateWindow возвращает NULL
      printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
    
    else
    {
      screenSurface = SDL_GetWindowSurface( window ); // выводит поверхность экрана внутри окна
      // заполняет поверхность экрана белым цветом
      SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
      SDL_UpdateWindowSurface( window );// обновить поверхноть экрана, чтобы отобразить на нем изменения
      // загадочная строчка позволяющая окну не пропадать сразу же
      SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true;}}
    }
  }
  
  SDL_DestroyWindow( window );         // уничтожаем окно
  SDL_Quit();                          // выходим из SDL

  return 0;
}
