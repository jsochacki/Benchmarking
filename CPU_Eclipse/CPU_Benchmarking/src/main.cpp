
#include "typedefs.h"
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
   int frame_size, data_size, pa;
   DIGITAL *binary_data;

   frame_size = 64800;
   data_size = 16200;

   binary_data = (DIGITAL*) calloc(frame_size, sizeof(DIGITAL));

   for(n = 0; n < data_size; n++)
   {
      binary_data[n] = random_bit_generator();
   }

   tick(&timekeeper);
   for(n = 0; n < iterations; n++)
   {
      //Function To Benchmark
      for(n = 0; n < data_size; n++)
      {
         printf("value is %d\n", binary_data[n]);
      }
   }
   tock_and_report(&timekeeper, iterations);
   return 0;
}


