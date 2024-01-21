#include "stopwatch.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

static FILE *file;
struct Time Time;

void Stopwatch(void) {
  if (Time.second == 60) {
    Time.second %= 60;
    Time.minute++;
  }
  if (Time.minute == 60) {
    Time.minute %= 60;
    Time.hour++;
  }
  usleep(1000000);
  Time.second++;
}

void initTime(void) {
  Time.hour = 0;
  Time.minute = 0;
  Time.second = 0;
  loadTime();
}

void loadTime(void) {
  if ((file = fopen(PATH, "r")) == NULL) {
    printf("Cannot open file '%s'\nProgram will start from 00:00:00\n", PATH);
  }
  fscanf(file, "%hu:%hu:%hu",&Time.hour, &Time.minute, &Time.second);
  printf("File loaded successfully!\n");
  fclose(file);
}

void saveTime(void) {
  if ((file = fopen(PATH, "w")) == NULL) {
    fprintf(stderr, "Cannot open file '%s'\n", PATH);
    exit(EXIT_FAILURE);
  }
  fprintf(file, "%02hu:%02hu:%02hu", Time.hour, Time.minute, Time.second);
  fflush(file);
  printf("file Saved! [%s]\n", PATH);
  fclose(file);
}

void cleanupStopwatch(void) {
  printf("Cleaning up stopwatch!\n");
  saveTime();
}
