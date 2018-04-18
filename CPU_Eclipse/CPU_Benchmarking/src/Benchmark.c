#include <stdio.h>
//Houses timespec and timeval, not part of C and does not work on windows
//just part of unix / posix
#include <time.h>
//#include <sys/time.h>  //Houses timespec as well but not part of C either

__time_t timespec_to_ms(struct timespec *);
__time_t timespec_time_delta_ms(struct timespec *, struct timespec *);

void main(int argc, char *argv[])
{
   if(argc < 2)
   {
      printf("Usage: main %s loop-iterations\n", argv[0]);
      return;
   }

   int n;

   int iterations = atoi(argv[1]);
   struct timespec start_time, end_time;

   //Function to Benchmark Setup

   clock_gettime(CLOCK_MONOTONIC, &start_time);
   for(n = 0; n < iterations; n++)
   {
      //Function To Benchmark
   }
   clock_gettime(CLOCK_MONOTONIC, &end_time);

   printf("The function took %ldms to run on average per %d iterations \n", timespec_time_delta_ms(&start_time, &end_time) / iterations, iterations);
   //1ms less accuracy due to pre delta truncation to the ms
   //printf("%ld\n\n", timespec_to_ms(&end_time) - timespec_to_ms(&start_time));
}

__time_t timespec_to_ms(struct timespec *t)
{
   return (((t->tv_sec) * 1e3) + ((t->tv_nsec) / 1e6));
}

__time_t timespec_time_delta_ms(struct timespec *tstart, struct timespec *tend)
{
   return (((tend->tv_sec - tstart->tv_sec) * 1e3) + ((tend->tv_nsec - tstart->tv_nsec) / 1e6));
}
