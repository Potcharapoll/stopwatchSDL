#ifndef STOPWATCH_H
#define STOPWATCH_H
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#define PATH "time"

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
