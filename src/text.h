#ifndef TEXT_H
#define TEXT_H
#define MAX_LEN   100
#define FONT_SIZE 40
#define FONT_PATH "res/fonts/JetBrainsMonoNerdFont-Regular.ttf"
#include <SDL2/SDL_ttf.h>

struct Text {
  char txt[MAX_LEN];
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
