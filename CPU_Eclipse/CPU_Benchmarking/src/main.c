#include <stdio.h>
#include <time.h>  //Houses timespec and timeval
//#include <sys/time.h>  //Houses timespec as well but not part of C

double timespec_to_ms(struct timespec *);

void main(int argc, char *argv)
{
   if(argc < 2)
   {
      printf("Usage: main %s loop-iterations\n", argv[0]);
      return;
   }

   int n;

   int iterations = atoi(argv[1]);
   struct timespec start_time, end_time;
   clock_gettime(CLOCK_MONOTONIC, &start_time);

   for(n = 0; n < iterations; n++)
   {

   }
   clock_gettime(CLOCK_MONOTONIC, &end_time);
/*
   printf("%ld", timespec_to_ms(end_time) - timespec_to_ms(start_time));*/
}

double timespec_to_ms(struct timespec *t)
{
   return ((((double) t->tv_sec) * 1e3) + (((double) t->tv_nsec) / 1e6));
}
