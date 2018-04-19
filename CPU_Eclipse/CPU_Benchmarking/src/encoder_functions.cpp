#include "typedefs.h"
#include "encoder_functions.h"

bool code_spec(Codec_Specification *codec_info, BIT_NODES *bit_n, CHECK_NODES *check_n)//, BIT_NODES *bit_n, CHECK_NODES *check_n,  char **pp, int *address_table){   //Operates with global variables: codec_info, bit_n, check_n, pp
{

   int code_id;

   codec_info->repeat = 360; //default otherwise specify for individual modcod

   switch(codec_info->n)
   {
      case 16200:
         code_id = 100 + codec_info->code_index;
         break;
      case 64800:
         code_id = 200 + codec_info->code_index;
         break;
      default:
         printf("#E Selected block size:%d not supported\n", codec_info->n);
         return (true);
   }
   printf("#E Selected block size is :%d\n", codec_info->n);

   switch(code_id)
   {
      //16200 S2
      case 100: //16200 1/4  chk deg.   3.75/4
         codec_info->k = 3240;
         codec_info->elite_degree = 12;
         codec_info->elite_end = 1440;
         codec_info->max_chk_degree = 4;
         strcpy(codec_info->LDPC_dat,  "DVB_14_16.dat");
         codec_info->BCH.m = 14;
         codec_info->BCH.t = 12;
         break;
      case 101: //16200 1/3  chk deg.      5/5
         codec_info->k = 5400;
         codec_info->elite_degree = 12;
         codec_info->elite_end = 1800;
         codec_info->max_chk_degree = 5;
         strcpy(codec_info->LDPC_dat,  "DVB_13_16.dat");
         codec_info->BCH.m = 14;
         codec_info->BCH.t = 12;
         break;
      case 102: //16200 2/5  chk deg.      6/6
         codec_info->k = 6480;
         codec_info->elite_degree = 12;
         codec_info->elite_end = 2160;
         codec_info->max_chk_degree = 6;
         strcpy(codec_info->LDPC_dat,  "DVB_25_16.dat");
         codec_info->BCH.m = 14;
         codec_info->BCH.t = 12;
         break;
      case 103: //16200 1/2  chk deg.    5.4/7
         codec_info->k = 7200;
         codec_info->elite_degree = 8;
         codec_info->elite_end = 1800;
         codec_info->max_chk_degree = 7;
         strcpy(codec_info->LDPC_dat,  "DVB_12_16.dat");
         codec_info->BCH.m = 14;
         codec_info->BCH.t = 12;
         break;
      case 104: //16200 3/5  chk deg.     11/11
         codec_info->k = 9720;
         codec_info->elite_degree = 12;
         codec_info->elite_end = 3240;
         codec_info->max_chk_degree = 11;
         strcpy(codec_info->LDPC_dat,  "DVB_35_16.dat");
         codec_info->BCH.m = 14;
         codec_info->BCH.t = 12;
         break;
      case 105: //16200 2/3  chk deg.     10/10
         codec_info->k = 10800;
         codec_info->elite_degree = 13;
         codec_info->elite_end = 1080;
         codec_info->max_chk_degree = 10;
         strcpy(codec_info->LDPC_dat,  "DVB_23_16.dat");
         codec_info->BCH.m = 14;
         codec_info->BCH.t = 12;
         break;
      case 106: //16200 3/4  chk deg.     11/13
         codec_info->k = 11880;
         codec_info->elite_degree = 12;
         codec_info->elite_end = 360;
         codec_info->max_chk_degree = 13;
         strcpy(codec_info->LDPC_dat,  "DVB_34_16.dat");
         codec_info->BCH.m = 14;
         codec_info->BCH.t = 12;
         break;
      case 107: //16200 4/5  chk deg.   12.5/13
         codec_info->k = 12600;
         codec_info->elite_degree = 3;
         codec_info->elite_end = 360;
         codec_info->max_chk_degree = 13;
         strcpy(codec_info->LDPC_dat,  "DVB_45_16.dat");
         codec_info->BCH.m = 14;
         codec_info->BCH.t = 12;
         break;
      case 108: //16200 5/6  chk deg. 17.125/19
         codec_info->k = 13320;
         codec_info->elite_degree = 13;
         codec_info->elite_end = 360;
         codec_info->max_chk_degree = 19;
         strcpy(codec_info->LDPC_dat,  "DVB_56_16.dat");
         codec_info->BCH.m = 14;
         codec_info->BCH.t = 12;
         break;
      case 109: //16200 8/9  chk deg.     27/27
         codec_info->k = 14400;
         codec_info->elite_degree = 4;
         codec_info->elite_end = 1800;
         codec_info->max_chk_degree = 27;
         strcpy(codec_info->LDPC_dat,  "DVB_89_16.dat");
         codec_info->BCH.m = 14;
         codec_info->BCH.t = 12;
         break;

      //64800  S2
      case 200: //64800 1/4  chk deg.      4/4
         codec_info->k = 16200;
         codec_info->elite_degree = 12;
         codec_info->elite_end = 5400;
         codec_info->max_chk_degree = 4;
         strcpy(codec_info->LDPC_dat,  "DVB_14_64.dat");
         codec_info->BCH.m = 16;
         codec_info->BCH.t = 12;
         break;
      case 201: //64800 1/3  chk deg.      5/5
         codec_info->k = 21600;
         codec_info->elite_degree = 12;
         codec_info->elite_end = 7200;
         codec_info->max_chk_degree = 5;
         strcpy(codec_info->LDPC_dat,  "DVB_13_64.dat");
         codec_info->BCH.m = 16;
         codec_info->BCH.t = 12;
         break;
      case 202: //64800 2/5  chk deg.      6/6
         codec_info->k = 25920;
         codec_info->elite_degree = 12;
         codec_info->elite_end = 8640;
         codec_info->max_chk_degree = 6;
         strcpy(codec_info->LDPC_dat,  "DVB_25_64.dat");
         codec_info->BCH.m = 16;
         codec_info->BCH.t = 12;
         break;
      case 203: //64800 1/2  chk deg.      7/7
         codec_info->k = 32400;
         codec_info->elite_degree = 8;
         codec_info->elite_end = 12960;
         codec_info->max_chk_degree = 7;
         strcpy(codec_info->LDPC_dat,  "DVB_12_64.dat");
         codec_info->BCH.m = 16;
         codec_info->BCH.t = 12;
         break;
      case 204: //64800 3/5  chk deg.     11/11
         codec_info->k = 38880;
         codec_info->elite_degree = 12;
         codec_info->elite_end = 12960;
         codec_info->max_chk_degree = 11;
         strcpy(codec_info->LDPC_dat,  "DVB_35_64.dat");
         codec_info->BCH.m = 16;
         codec_info->BCH.t = 12;
         break;
      case 205: //64800 2/3  chk deg.     10/10
         codec_info->k = 43200;
         codec_info->elite_degree = 13;
         codec_info->elite_end = 4320;
         codec_info->max_chk_degree = 10;
         strcpy(codec_info->LDPC_dat,  "DVB_23_64.dat");
         codec_info->BCH.m = 16;
         codec_info->BCH.t = 10;
         break;
      case 206: //64800 3/4  chk deg.     14/14
         codec_info->k = 48600;
         codec_info->elite_degree = 12;
         codec_info->elite_end = 5400;
         codec_info->max_chk_degree = 14;
         strcpy(codec_info->LDPC_dat,  "DVB_34_64.dat");
         codec_info->BCH.m = 16;
         codec_info->BCH.t = 12;
         break;
      case 207: //64800 4/5  chk deg.     18/18
         codec_info->k = 51840;
         codec_info->elite_degree = 11;
         codec_info->elite_end = 6480;
         codec_info->max_chk_degree = 18;
         strcpy(codec_info->LDPC_dat,  "DVB_45_64.dat");
         codec_info->BCH.m = 16;
         codec_info->BCH.t = 12;
         break;
      case 208: //64800 5/6  chk deg.     22/22
         codec_info->k = 54000;
         codec_info->elite_degree = 13;
         codec_info->elite_end = 5400;
         codec_info->max_chk_degree = 22;
         strcpy(codec_info->LDPC_dat,  "DVB_56_64.dat");
         codec_info->BCH.m = 16;
         codec_info->BCH.t = 10;
         break;
      case 209: //64800 8/9  chk deg.     27/27
         codec_info->k = 57600;
         codec_info->elite_degree = 4;
         codec_info->elite_end = 7200;
         codec_info->max_chk_degree = 27;
         strcpy(codec_info->LDPC_dat,  "DVB_89_64.dat");
         codec_info->BCH.m = 16;
         codec_info->BCH.t = 8;
         break;
      case 210: //64800 9/10 chk deg.     30/30
         codec_info->k = 58320;
         codec_info->elite_degree = 4;
         codec_info->elite_end = 6480;
         codec_info->max_chk_degree = 30;
         strcpy(codec_info->LDPC_dat, "DVB_910_64.dat");
         codec_info->BCH.m = 16;
         codec_info->BCH.t = 8;
         break;

      default:
         printf("#E The code option:%d is not supported! n:%d code_index:%d\n",
                  code_id, codec_info->n, codec_info->code_index);
         return (true);
   }

   printf("#E The code option:%d is n:%d code_index:%d\n"
            "%d info bits\n"
            "%d elite degree\n"
            "%d elite end\n"
            "%d max check degree\n"
            "%s dat file name\n"
            "%d BCH m\n"
            "%d BCH t\n",
            code_id,
            codec_info->n,
            codec_info->code_index,
            codec_info->k,
            codec_info->elite_degree,
            codec_info->elite_end,
            codec_info->max_chk_degree,
            codec_info->LDPC_dat,
            codec_info->BCH.m,
            codec_info->BCH.t);
   //codec_info->k = 16200;   //Information Bits
   //codec_info->elite_degree = 12; //degrees in top portion of code
   //codec_info->elite_end = 5400;  //15 rows of check nodes * 360 repeats
   //codec_info->max_chk_degree = 4;   //
   //strcpy(codec_info->LDPC_dat,  "DVB_14_64.dat");  //
   //codec_info->BCH.m = 16;  //
   //codec_info->BCH.t = 12;  //

   codec_info->number_of_parity_bits = codec_info->n - codec_info->k;

   //1/4 64800 example numbers
   //12 * ( 15 * 360)
   //total number of parity bit connections from top portion of code
   //3 * (16200 - (15 * 30))
   //total number of parity bit connections from lower portion of code
   //((2 * 64800 - 16200)) - 1
   //Total number of parity bit connections from final xor of parity bits
   //(-1 is since p0 only has 1 connection)

   codec_info->total_edges =
            (codec_info->elite_degree * codec_info->elite_end) +
            3 * (codec_info->k - codec_info->elite_end) +
            (2 * codec_info->number_of_parity_bits) - 1;

   printf("num parity bits is %d and "
            "total_edges is %d\n",
            codec_info->number_of_parity_bits,
            codec_info->total_edges);

   if(ldpc_construct(*codec_info, bit_n, check_n))
   {
      return (true);
   }
/*   if (BCH_spec(codec_info)) return (true);
   codec_info->coderate=(double)codec_info->BCH.k/(double)codec_info->n;*/

   return(false);
}

bool ldpc_construct (Codec_Specification &codec_info, BIT_NODES *bit_n, CHECK_NODES *check_n)
{
   int j,i,k, temp_index;

   int count = 0;
   int countall = 0;

   unsigned short add_seed[1000], add_lut[MAX_BLOCK_SIZE*5];

   FILE *fp;

   //DVBS2 1/4 64800 example numbers
   // q is set in the DVBS2 Standard and defined but also able to be calculated in this way for flexibility
   // (total_bits - information_bits) = Parity Bits and q = Parity_Bits / repeat_rate
   // 64800 - 16200 = 48600  48600 / 360 = 135
   int q = codec_info.number_of_parity_bits / codec_info.repeat;
   // 12 * (5400 / 360) = 12 * 15 = 180
   int elite_seed = codec_info.elite_degree * (codec_info.elite_end / codec_info.repeat);
   //degree of first set of parity seeds, example here is 12 (i.e. number of seeds in a row of table B)
   int deg = codec_info.elite_degree;
   //degree of second set of parity seeds (i.e. number of seeds in a row of table B). It is constant in DVBS2
   int deg2 = 3;
   // 112 * 15 = 180 => 180 + (3 * (16200 - 5400) / 360)) = (12 * 15) + (3 * (16200 - 5400) / 360)
   // this is nodes (number of columns) * rows per each section of the code
   // 15 * 360 = 5400 so the 30 remaining that are 3 wide take up the rest
   int add_lut_size = elite_seed + deg2 * (codec_info.k - codec_info.elite_end) / codec_info.repeat; // 270


   // --------------------------- Read in the add_seed table -------------------------
      fp = fopen(codec_info.LDPC_dat,"r");
      if (!fp) { printf("#E fopen failed for file:%s\n", codec_info.LDPC_dat); }

      for (i = 0; i < add_lut_size; i++)
      {
             if (!fscanf(fp, "%hd", &add_seed[i]))
             {
                printf("#E Add LUT read failed i:%d add_lut_size:%d file:%s\n",
                       i, add_lut_size, codec_info.LDPC_dat);
             }
             printf("seed value is %d\n", add_seed[i]);
      }
      fclose(fp);


}
