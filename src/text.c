#include "text.h"
#include "window.h"
#include "stopwatch.h"
#include <stdio.h>
#include <stdlib.h>

static struct Text text;

static SDL_Texture* loadText() {
  uint8_t len = snprintf(NULL, 0, "%02hu:%02hu:%02hu", Time.hour, Time.minute, Time.second);
  snprintf(text.txt, len+1, "%02hu:%02hu:%02hu", Time.hour, Time.minute, Time.second);

  SDL_Surface* surfaceTxt = TTF_RenderText_Solid(text.font, text.txt, text.color);
  SDL_Texture* textureTxt = SDL_CreateTextureFromSurface(window.renderer,surfaceTxt);
  SDL_FreeSurface(surfaceTxt);
  return textureTxt;
}

void updateText(void) {
  text.texture = loadText();
  Stopwatch();
}

void renderText(void) {
  SDL_SetRenderDrawColor(window.renderer, text.color.r, text.color.g, text.color.b, text.color.a);
  SDL_RenderCopy(window.renderer, text.texture, NULL, &text.rect);
}

void initText(void) {
  TTF_Init();
  text.font = TTF_OpenFont(FONT_PATH, FONT_SIZE);
  if (text.font == NULL) {
    fprintf(stderr, "Cannot load the font: %s\n", TTF_GetError());
    exit(EXIT_FAILURE);
  }
  text.color.r = 255;
  text.color.g = 255;
  text.color.b = 255;
  text.color.a = SDL_ALPHA_OPAQUE;
  text.rect.x = 15;
  text.rect.y = 10;
  text.rect.w = WIDTH-FONT_SIZE;
  text.rect.h = HEIGHT-15;

  initTime();
}

void destroyText(void) {
  cleanupStopwatch();
  SDL_DestroyTexture(text.texture);
  TTF_CloseFont(text.font);
  TTF_Quit();
}
