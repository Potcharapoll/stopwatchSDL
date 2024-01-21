#ifndef STOPWATCH_H
#define STOPWATCH_H
#define PATH "time"
#include <stdint.h>

struct Time {
  uint16_t hour;
  uint16_t minute;
  uint16_t second;
};

void initTime(void);
void Stopwatch(void);
void saveTime(void);
void loadTime(void);
void cleanupStopwatch(void);

extern struct Time Time;
#endif
