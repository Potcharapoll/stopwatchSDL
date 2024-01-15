#ifndef WINDOW_H
#define WINDOW_H
#define SCREENWIDTH 1920
#define WIDTH  175
#define HEIGHT 50
#include <SDL2/SDL.h>
#include <stdbool.h>

struct Window {
  SDL_Window *win;
  SDL_Renderer *renderer;
  bool quit;
};

void initSDLWindow(void);
void destroyWindow(void);

extern struct Window window;
#endif
