#ifndef BENCHMARKING_FUNCTIONS_H_
#define BENCHMARKING_FUNCTIONS_H_

//Houses timespec and timeval, not part of C and does not work on windows
//just part of unix / posix
#include <time.h>        // Defines time(), ctime(), difftime(), clock()
//#include <sys/time.h>  //Houses timespec as well but not part of C either

struct Timekeeper
{
   struct timespec start_time;
   struct timespec end_time;
};

__time_t timespec_to_ms(struct timespec *t);

__time_t timespec_time_delta_ms(struct timespec *tstart, struct timespec *tend);

__time_t timespec_time_delta_ms(struct Timekeeper *t);

void tick(struct Timekeeper *);

void tock(struct Timekeeper *);

void tock_and_report(struct Timekeeper *t, int iterations);

void average_execution_time(struct Timekeeper *, int);

#endif /* BENCHMARKING_FUNCTIONS_H_ */
