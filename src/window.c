#include "window.h"
#include "text.h"

struct Window window;

static void update(void) {
  updateText();
}

static void render(void) {
  SDL_SetRenderDrawColor(window.renderer, 0, 0, 0, 255);
  SDL_RenderClear(window.renderer);
  renderText();
  SDL_RenderPresent(window.renderer);
}

static void windowHandle(void) {
  SDL_Event e;
  while (!window.quit) {
    while (SDL_PollEvent(&e)) {
      switch(e.type) {
        case SDL_QUIT:
          window.quit = true;
          break;
        default:
          break;
      }
    }
    update();
    render();
  }
}

void initSDLWindow(void) {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    fprintf(stderr, "Error Initializing SDL: %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }
  window.win = SDL_CreateWindow(
      "Stopwatch",
      SCREENWIDTH-WIDTH,
      0,
      WIDTH,
      HEIGHT,
      SDL_WINDOW_BORDERLESS | SDL_WINDOW_POPUP_MENU);
  if (!window.win) {
    fprintf(stderr, "Error Creating SDL_Window: %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }
  window.renderer = SDL_CreateRenderer(window.win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (!window.renderer) {
    fprintf(stderr, "Error Creating SDL_Renderer: %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }
  window.quit = false;
  initText();
  windowHandle();
}

void destroyWindow(void) {
  SDL_DestroyRenderer(window.renderer);
  SDL_DestroyWindow(window.win);
  SDL_Quit();
}
