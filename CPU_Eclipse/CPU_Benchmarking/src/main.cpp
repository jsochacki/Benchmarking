#include "typedefs.h"
#include "benchmarking_functions.h"
#include "encoder_functions.h"

int main(int argc, char *argv[])
{
   if(argc < 2)
   {
      printf("Usage: main %s loop-iterations\n", argv[0]);
      return 0;
   }

   int n, nn;

   int iterations = atoi(argv[1]);
   struct Timekeeper timekeeper;


   //Function to Benchmark Setup
   int frame_size, data_size, pa;
   DIGITAL *binary_data;

   frame_size = 64800;
   data_size = 16200;

   Codec_Specification codec_info;
   BIT_NODES *bit_n;
   CHECK_NODES *check_n;
   codec_info.n = frame_size;
   codec_info.code_index = 0;

   if (allocate_LDPC_encoder_memory(&bit_n, &check_n)) return (true);
   code_spec(&codec_info, bit_n, check_n);

   binary_data = (DIGITAL*) calloc(frame_size, sizeof(DIGITAL));

   for(n = 0; n < data_size; n++)
   {
      binary_data[n] = random_bit_generator();
   }

   tick(&timekeeper);
   for(n = 0; n < iterations; n++)
   {
      //Function To Benchmark
      ldpc_encoder(codec_info, check_n, binary_data);
   }
   tock_and_report(&timekeeper, iterations);
   return 0;
}


