#include "text.h"
#include "window.h"
#include <stdlib.h>

void cleanup(void) {
  destroyText();
  destroyWindow();
}

int main(void) {
  atexit(cleanup);
  initSDLWindow();
  return 0;
}
