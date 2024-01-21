#include "window.h"
#include "text.h"

struct Window window;

static void updateWindow(void) {
  updateText();
}

static void renderWindow(void) {
  SDL_SetRenderDrawColor(window.renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(window.renderer);
  renderText();
  SDL_RenderPresent(window.renderer);
}

static void windowHandle(void) {
  while (!window.quit) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT)
        window.quit = true;
    }
    updateWindow();
    renderWindow();
  }
}

void initSDLWindow(void) {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    fprintf(stderr, "Error Initializing SDL: %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }
  window.window = SDL_CreateWindow(
      "Stopwatch",
      SCREENWIDTH-WIDTH,
      0,
      WIDTH,
      HEIGHT,
      SDL_WINDOW_BORDERLESS | SDL_WINDOW_POPUP_MENU);
  if (!window.window) {
    fprintf(stderr, "Could not create a window: %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }
  window.renderer = SDL_CreateRenderer(window.window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (!window.renderer) {
    fprintf(stderr, "Could not create a renderer: %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }
  window.quit = false;
  initText();
  windowHandle();
}

void destroyWindow(void) {
  SDL_DestroyRenderer(window.renderer);
  SDL_DestroyWindow(window.window);
  SDL_Quit();
}
