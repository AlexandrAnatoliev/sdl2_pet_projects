// less2_get_image.cpp -  выводит картинку  hello world

#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>

const int SCREEN_WIDTH = 640; // размеры окна
const int SCREEN_HEIGHT = 480;

SDL_Window *win = NULL;       // окно
SDL_Surface *scr = NULL;      // экран
SDL_Surface *image = NULL;    // изображение

int init()                    // инициализация окна, экрана и изображения
{
  if (SDL_Init(SDL_INIT_VIDEO) != 0)
    return 1;

  win = SDL_CreateWindow("less2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if (win == NULL) 
    return 1;
    
  scr = SDL_GetWindowSurface(win);

  return 0;
}

int load()                    // загрузка медиафайла
{
  image = SDL_LoadBMP("hello_world.bmp");

  if (image == NULL)
    return 1;

  return 0;
}

void quit()                   // завершение приложения
{
  SDL_FreeSurface(image);     // функция очищает поверхность экрана
    
  SDL_DestroyWindow(win);

  SDL_Quit();
}

int main (int argc, char ** args)
{
  if (init() == 1)
    return 1;

  if (load() == 1)
        return 1;

  SDL_BlitSurface(image, NULL, scr, NULL); // отображаем катинку image внутри src
  // (поверхность для рисования,
  // прямоугольник, который следует вырезать из данной поверхности: NULL - ничего не вырезать,
  // поверхность на которой рисуют,
  // прямоугольник, координаты которого используются для рисования:NULL - нулевые координаты)

  SDL_UpdateWindowSurface(win);

  SDL_Delay(12000);

  quit();

  return 0;
}

