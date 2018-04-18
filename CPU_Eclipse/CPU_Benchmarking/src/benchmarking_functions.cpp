#include <time.h>
#include "benchmarking_functions.h"
#include <stdio.h>

__time_t timespec_to_ms(struct timespec *t)
{
   return (((t->tv_sec) * 1e3) + ((t->tv_nsec) / 1e6));
}

__time_t timespec_time_delta_ms(struct timespec *tstart, struct timespec *tend)
{
   return (((tend->tv_sec - tstart->tv_sec) * 1e3) + ((tend->tv_nsec - tstart->tv_nsec) / 1e6));
}

__time_t timespec_time_delta_ms(struct Timekeeper *t)
{
   return (((t->end_time.tv_sec - t->start_time.tv_sec) * 1e3) + ((t->end_time.tv_nsec - t->start_time.tv_nsec) / 1e6));
}

void tick(struct Timekeeper *t)
{
   clock_gettime(CLOCK_MONOTONIC, &(t->start_time));
}

void tock(struct Timekeeper *t)
{
   clock_gettime(CLOCK_MONOTONIC, &(t->end_time));
}

void tock_and_report(struct Timekeeper *t, int iterations)
{
   tock(t);
   average_execution_time(t, iterations);
}

void average_execution_time(struct Timekeeper *t, int iterations)
{
   printf("The function took %ldms to run on average for %d test iterations \n", timespec_time_delta_ms(t) / iterations, iterations);
}
