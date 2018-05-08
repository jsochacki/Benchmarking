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
   DIGITAL *binary_data, *golden_binary_data;

   Codec_Specification codec_info;
   BIT_NODES *bit_n;
   CHECK_NODES *check_n;
   codec_info.code_index = S2_NF_1_4;

   if (allocate_LDPC_encoder_memory(&bit_n, &check_n)) return (true);
   code_spec(&codec_info, bit_n, check_n);

   frame_size = codec_info.n;
   data_size = codec_info.k;

   binary_data = (DIGITAL*) calloc(frame_size, sizeof(DIGITAL));
   golden_binary_data = (DIGITAL*) calloc(frame_size, sizeof(DIGITAL));

   for(n = 0; n < data_size; n++)
   {
      binary_data[n] = random_bit_generator();
   }

   FILE *fpd;
   fpd = fopen("pre_encoded_bits.txt", "r");
   int bitnum;
   for(bitnum = 0; bitnum < data_size; bitnum++)
   {
      if (!fscanf(fpd, "%d", &binary_data[bitnum]))
      {
         printf("Failed reading in bit file \n");
      }
      //printf("%d\n",binary_data[bitnum]);
   }

   fclose(fpd);

   tick(&timekeeper);
   for(n = 0; n < iterations; n++)
   {
//      for(n = 0; n < data_size; n++)
//      {
//         binary_data[n] = random_bit_generator();
//      }
      //Function To Benchmark
      ldpc_encoder(codec_info, check_n, binary_data);
   }
   tock_and_report(&timekeeper, iterations);

   FILE *fpd2;
   fpd2 = fopen("post_encoded_bits.txt", "r");
   for(bitnum = 0; bitnum < frame_size; bitnum++)
   {
      if (!fscanf(fpd2, "%d", &golden_binary_data[bitnum]))
      {
         printf("Failed reading in bit file \n");
      }
   }
   fclose(fpd2);

   unsigned int bitcount = 0;

   for(bitnum = 0; bitnum < frame_size; bitnum++)
   {
      if(golden_binary_data[bitnum] == binary_data[bitnum]) bitcount++;
   }

   if(bitcount == frame_size) printf("encoder is good\n"); else printf("encoder is bad\n");

   return 0;
}


