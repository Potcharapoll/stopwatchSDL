#ifndef TEXT_H
#define TEXT_H
#include <SDL2/SDL_ttf.h>
#define FONT_SIZE 40
#define FONT_PATH "res/fonts/JetBrainsMonoNerdFont-Regular.ttf"

struct Text {
  char txt[9];
  SDL_Texture *texture;
  TTF_Font *font;
  SDL_Rect rect;
  SDL_Color color;
};

void initText(void);
void updateText(void);
void renderText(void);
void destroyText(void);
#endif
