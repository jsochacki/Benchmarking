#include <stdio.h>

#//include <cstdlib>

#include "benchmarking_functions.h"

int main(int argc, char *argv[])
{
   if(argc < 2)
   {
      printf("Usage: main %s loop-iterations\n", argv[0]);
      return 0;
   }

   int n;

   int iterations = atoi(argv[1]);
   struct Timekeeper timekeeper;

   //Function to Benchmark Setup

   tick(&timekeeper);
   for(n = 0; n < iterations; n++)
   {
      //Function To Benchmark
   }
   tock_and_report(&timekeeper, iterations);
//   tock(&timekeeper);
//   average_execution_time(&timekeeper, iterations);
   //1ms less accuracy due to pre delta truncation to the ms
   //printf("%ld\n\n", timespec_to_ms(&end_time) - timespec_to_ms(&start_time));
   return 0;
}


