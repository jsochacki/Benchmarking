#include "typedefs.h"
#include "encoder_functions.h"

bool code_spec(Codec_Specification *codec_info,
               BIT_NODES *bit_n,
               CHECK_NODES *check_n)
{

/*   switch(codec_info->code_index)
   {
      case AB_x6_1_3:
         codec_info->k = 420;
         codec_info->n = 1260;
         codec_info->repeat = 42;
         codec_info->elite_degree = 12;
         codec_info->elite_end = 126;
         codec_info->max_chk_degree = 11111;
         strcpy(codec_info->LDPC_dat,  "AB_x6_13.dat");
         codec_info->BCH.m = 12;
         codec_info->BCH.t = 12;
         break;
      case AB_x4_1_3:
         codec_info->n = 1890;
         codec_info->repeat = 42;
         break;
      case AB_x3_1_3:
         codec_info->n = 2520;
         codec_info->repeat = 42;
         break;
      case AB_x2_1_3:
         codec_info->n = 3780;
         codec_info->repeat = 42;
         break;
      case AB_x1_1_5:
         codec_info->n = 7560;
         codec_info->repeat = 84;
         break;
      case AB_x1_4_15:
         codec_info->n = 7560;
         codec_info->repeat = 84;
         break;
      case AB_x1_1_3:
         codec_info->n = 7560;
         codec_info->repeat = 168;
         break;
      case AB_SF_1_4 ... AB_SF_3_4:
         codec_info->n = 16200;
         codec_info->repeat = 360;
         break;
      case AB_MF_2_5 ... AB_MF_4_5:
         codec_info->n = 32400;
         codec_info->repeat = 360;
         break;
      case AB_LF_7_10 ... AB_LF_9_10:
         codec_info->n = 40500;
         codec_info->repeat = 405;
         break;
      default:
         printf("#E Code Index not supported\n");
         return (true);
   }
   printf("#E Selected block size is :%d\n", codec_info->n);*/

   switch(codec_info->code_index)
   {
      //16200 S2
      case S2_SF_1_4: //16200 1/4  chk deg.   3.75/4
         codec_info->k = 3240;
         codec_info->n = 16200;
         codec_info->repeat = 360;
         codec_info->elite_degree = 12;
         codec_info->elite_end = 1440;
         codec_info->max_chk_degree = 4;
         strcpy(codec_info->LDPC_dat,  "DVB_14_16.dat");
         codec_info->BCH.m = 14;
         codec_info->BCH.t = 12;
         break;
      case S2_SF_1_3: //16200 1/3  chk deg.      5/5
         codec_info->k = 5400;
         codec_info->n = 16200;
         codec_info->repeat = 360;
         codec_info->elite_degree = 12;
         codec_info->elite_end = 1800;
         codec_info->max_chk_degree = 5;
         strcpy(codec_info->LDPC_dat,  "DVB_13_16.dat");
         codec_info->BCH.m = 14;
         codec_info->BCH.t = 12;
         break;
      case S2_SF_2_5: //16200 2/5  chk deg.      6/6
         codec_info->k = 6480;
         codec_info->n = 16200;
         codec_info->repeat = 360;
         codec_info->elite_degree = 12;
         codec_info->elite_end = 2160;
         codec_info->max_chk_degree = 6;
         strcpy(codec_info->LDPC_dat,  "DVB_25_16.dat");
         codec_info->BCH.m = 14;
         codec_info->BCH.t = 12;
         break;
      case S2_SF_1_2: //16200 1/2  chk deg.    5.4/7
         codec_info->k = 7200;
         codec_info->n = 16200;
         codec_info->repeat = 360;
         codec_info->elite_degree = 8;
         codec_info->elite_end = 1800;
         codec_info->max_chk_degree = 7;
         strcpy(codec_info->LDPC_dat,  "DVB_12_16.dat");
         codec_info->BCH.m = 14;
         codec_info->BCH.t = 12;
         break;
      case S2_SF_3_5: //16200 3/5  chk deg.     11/11
         codec_info->k = 9720;
         codec_info->n = 16200;
         codec_info->repeat = 360;
         codec_info->elite_degree = 12;
         codec_info->elite_end = 3240;
         codec_info->max_chk_degree = 11;
         strcpy(codec_info->LDPC_dat,  "DVB_35_16.dat");
         codec_info->BCH.m = 14;
         codec_info->BCH.t = 12;
         break;
      case S2_SF_2_3: //16200 2/3  chk deg.     10/10
         codec_info->k = 10800;
         codec_info->n = 16200;
         codec_info->repeat = 360;
         codec_info->elite_degree = 13;
         codec_info->elite_end = 1080;
         codec_info->max_chk_degree = 10;
         strcpy(codec_info->LDPC_dat,  "DVB_23_16.dat");
         codec_info->BCH.m = 14;
         codec_info->BCH.t = 12;
         break;
      case S2_SF_3_4: //16200 3/4  chk deg.     11/13
         codec_info->k = 11880;
         codec_info->n = 16200;
         codec_info->repeat = 360;
         codec_info->elite_degree = 12;
         codec_info->elite_end = 360;
         codec_info->max_chk_degree = 13;
         strcpy(codec_info->LDPC_dat,  "DVB_34_16.dat");
         codec_info->BCH.m = 14;
         codec_info->BCH.t = 12;
         break;
      case S2_SF_4_5: //16200 4/5  chk deg.   12.5/13
         codec_info->k = 12600;
         codec_info->n = 16200;
         codec_info->repeat = 360;
         codec_info->elite_degree = 3;
         codec_info->elite_end = 360;
         codec_info->max_chk_degree = 13;
         strcpy(codec_info->LDPC_dat,  "DVB_45_16.dat");
         codec_info->BCH.m = 14;
         codec_info->BCH.t = 12;
         break;
      case S2_SF_5_6: //16200 5/6  chk deg. 17.125/19
         codec_info->k = 13320;
         codec_info->n = 16200;
         codec_info->repeat = 360;
         codec_info->elite_degree = 13;
         codec_info->elite_end = 360;
         codec_info->max_chk_degree = 19;
         strcpy(codec_info->LDPC_dat,  "DVB_56_16.dat");
         codec_info->BCH.m = 14;
         codec_info->BCH.t = 12;
         break;
      case S2_SF_8_9: //16200 8/9  chk deg.     27/27
         codec_info->k = 14400;
         codec_info->n = 16200;
         codec_info->repeat = 360;
         codec_info->elite_degree = 4;
         codec_info->elite_end = 1800;
         codec_info->max_chk_degree = 27;
         strcpy(codec_info->LDPC_dat,  "DVB_89_16.dat");
         codec_info->BCH.m = 14;
         codec_info->BCH.t = 12;
         break;

      //64800  S2
      case S2_NF_1_4: //64800 1/4  chk deg.      4/4
         codec_info->k = 16200;
         codec_info->n = 64800;
         codec_info->repeat = 360;
         codec_info->elite_degree = 12;
         codec_info->elite_end = 5400;
         codec_info->max_chk_degree = 4;
         strcpy(codec_info->LDPC_dat,  "DVB_14_64.dat");
         codec_info->BCH.m = 16;
         codec_info->BCH.t = 12;
         break;
      case S2_NF_1_3: //64800 1/3  chk deg.      5/5
         codec_info->k = 21600;
         codec_info->n = 64800;
         codec_info->repeat = 360;
         codec_info->elite_degree = 12;
         codec_info->elite_end = 7200;
         codec_info->max_chk_degree = 5;
         strcpy(codec_info->LDPC_dat,  "DVB_13_64.dat");
         codec_info->BCH.m = 16;
         codec_info->BCH.t = 12;
         break;
      case S2_NF_2_5: //64800 2/5  chk deg.      6/6
         codec_info->k = 25920;
         codec_info->n = 64800;
         codec_info->repeat = 360;
         codec_info->elite_degree = 12;
         codec_info->elite_end = 8640;
         codec_info->max_chk_degree = 6;
         strcpy(codec_info->LDPC_dat,  "DVB_25_64.dat");
         codec_info->BCH.m = 16;
         codec_info->BCH.t = 12;
         break;
      case S2_NF_1_2: //64800 1/2  chk deg.      7/7
         codec_info->k = 32400;
         codec_info->n = 64800;
         codec_info->repeat = 360;
         codec_info->elite_degree = 8;
         codec_info->elite_end = 12960;
         codec_info->max_chk_degree = 7;
         strcpy(codec_info->LDPC_dat,  "DVB_12_64.dat");
         codec_info->BCH.m = 16;
         codec_info->BCH.t = 12;
         break;
      case S2_NF_3_5: //64800 3/5  chk deg.     11/11
         codec_info->k = 38880;
         codec_info->n = 64800;
         codec_info->repeat = 360;
         codec_info->elite_degree = 12;
         codec_info->elite_end = 12960;
         codec_info->max_chk_degree = 11;
         strcpy(codec_info->LDPC_dat,  "DVB_35_64.dat");
         codec_info->BCH.m = 16;
         codec_info->BCH.t = 12;
         break;
      case S2_NF_2_3: //64800 2/3  chk deg.     10/10
         codec_info->k = 43200;
         codec_info->n = 64800;
         codec_info->repeat = 360;
         codec_info->elite_degree = 13;
         codec_info->elite_end = 4320;
         codec_info->max_chk_degree = 10;
         strcpy(codec_info->LDPC_dat,  "DVB_23_64.dat");
         codec_info->BCH.m = 16;
         codec_info->BCH.t = 10;
         break;
      case S2_NF_3_4: //64800 3/4  chk deg.     14/14
         codec_info->k = 48600;
         codec_info->n = 64800;
         codec_info->repeat = 360;
         codec_info->elite_degree = 12;
         codec_info->elite_end = 5400;
         codec_info->max_chk_degree = 14;
         strcpy(codec_info->LDPC_dat,  "DVB_34_64.dat");
         codec_info->BCH.m = 16;
         codec_info->BCH.t = 12;
         break;
      case S2_NF_4_5: //64800 4/5  chk deg.     18/18
         codec_info->k = 51840;
         codec_info->n = 64800;
         codec_info->repeat = 360;
         codec_info->elite_degree = 11;
         codec_info->elite_end = 6480;
         codec_info->max_chk_degree = 18;
         strcpy(codec_info->LDPC_dat,  "DVB_45_64.dat");
         codec_info->BCH.m = 16;
         codec_info->BCH.t = 12;
         break;
      case S2_NF_5_6: //64800 5/6  chk deg.     22/22
         codec_info->k = 54000;
         codec_info->n = 64800;
         codec_info->repeat = 360;
         codec_info->elite_degree = 13;
         codec_info->elite_end = 5400;
         codec_info->max_chk_degree = 22;
         strcpy(codec_info->LDPC_dat,  "DVB_56_64.dat");
         codec_info->BCH.m = 16;
         codec_info->BCH.t = 10;
         break;
      case S2_NF_8_9: //64800 8/9  chk deg.     27/27
         codec_info->k = 57600;
         codec_info->n = 64800;
         codec_info->repeat = 360;
         codec_info->elite_degree = 4;
         codec_info->elite_end = 7200;
         codec_info->max_chk_degree = 27;
         strcpy(codec_info->LDPC_dat,  "DVB_89_64.dat");
         codec_info->BCH.m = 16;
         codec_info->BCH.t = 8;
         break;
      case S2_NF_9_10: //64800 9/10 chk deg.     30/30
         codec_info->k = 58320;
         codec_info->n = 64800;
         codec_info->repeat = 360;
         codec_info->elite_degree = 4;
         codec_info->elite_end = 6480;
         codec_info->max_chk_degree = 30;
         strcpy(codec_info->LDPC_dat, "DVB_910_64.dat");
         codec_info->BCH.m = 16;
         codec_info->BCH.t = 8;
         break;

      default:
         printf("#E The code option is not supported!\n");
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
            codec_info->code_index,
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
   //12 * ( 15 * 360) = (codec_info->elite_degree * codec_info->elite_end)
   //total number of parity bit connections from top portion of code
   //3 * (16200 - (15 * 360)) = 3 * (codec_info->k - codec_info->elite_end)
   //total number of parity bit connections from lower portion of code
   //((2 * (64800 - 16200))) - 1 = (2 * codec_info->number_of_parity_bits) - 1
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

bool ldpc_construct (Codec_Specification &codec_info,
                     BIT_NODES *bit_n,
                     CHECK_NODES *check_n)
{
   int i, j, k, parity_node_index;

   int bit_count;

   unsigned short add_seed[1000], add_lut[MAX_BLOCK_SIZE*5];

   FILE *fp;

   //DVBS2 1/4 64800 example numbers
   // q is set in the DVBS2 Standard and defined but also able to be calculated in this way for flexibility
   // (total_bits - information_bits) = Parity Bits and q = Parity_Bits / repeat_rate
   // 64800 - 16200 = 48600  48600 / 360 = 135
   int q = codec_info.number_of_parity_bits / codec_info.repeat;
   // 12 * (5400 / 360) = 12 * 15 = 180
   int elite_seed = codec_info.elite_degree *
            (codec_info.elite_end / codec_info.repeat);
   //degree of first set of parity seeds, example here is 12 (i.e. number of seeds in a row of table B)
   int deg = codec_info.elite_degree;
   //degree of second set of parity seeds (i.e. number of seeds in a row of table B). It is constant in DVBS2
   int deg2 = 3;
   // 112 * 15 = 180 => 180 + (3 * (16200 - 5400) / 360)) = (12 * 15) + (3 * (16200 - 5400) / 360)
   // this is nodes (number of columns) * rows per each section of the code
   // 15 * 360 = 5400 so the 30 remaining that are 3 wide take up the rest
   int add_lut_size = elite_seed + deg2 *
            (codec_info.k - codec_info.elite_end) / codec_info.repeat; // 270


   //Read in the add_seed table
   fp = fopen(codec_info.LDPC_dat,"r");
   if (!fp) { printf("#E fopen failed for file:%s\n", codec_info.LDPC_dat); }

   for (i = 0; i < add_lut_size; i++)
   {
          if (!fscanf(fp, "%hd", &add_seed[i]))
          {
             printf("#E Add LUT read failed i:%d add_lut_size:%d file:%s\n",
                    i, add_lut_size, codec_info.LDPC_dat);
          }
   }
   fclose(fp);

   for (j = 0; j < codec_info.number_of_parity_bits; j++)
   {
      check_n[j].degree = 0;
   }

   //Do the top tier of parity seeds
   bit_count = 0;
   for (i = (deg - 1); i < elite_seed; i += deg)
   {
      for (j = 0; j < codec_info.repeat; j++)
      {
         for (k = 0; k < deg; k++)
         {
            parity_node_index =
                  (add_seed[i+1-deg+k]+j*q)%codec_info.number_of_parity_bits;
            check_n[parity_node_index].
               btc[check_n[parity_node_index].degree].index = bit_count;
            check_n[parity_node_index].degree =
                     check_n[parity_node_index].degree + 1;
         }
         bit_count++;
      }
   }

   //Do the second tier of parity seeds
   deg = deg2;

   //for (i = (elite_seed + (deg - 1)); i < add_lut_size; i += deg)
   for (i = ((elite_seed - 1) + deg); i < add_lut_size; i += deg)
   {
      for (j = 0; j < codec_info.repeat; j++)
      {
         for (k = 0; k < deg; k++)
         {
            parity_node_index =
                  (add_seed[i+1-deg+k]+j*q)%codec_info.number_of_parity_bits;
            check_n[parity_node_index].
               btc[check_n[parity_node_index].degree].index = bit_count;
            check_n[parity_node_index].degree =
                     check_n[parity_node_index].degree + 1;
         }
         bit_count++;
      }
   }

   //connect the next parity node to the current bit node (which is the same
   // as the current parity node so you are connecting the next parity
   // node to the current parity node)
   //last node has no forward connection so stop 1 early
   for (i = 0; i < (codec_info.number_of_parity_bits - 1); i++)
   {
      parity_node_index = i + 1;
      check_n[parity_node_index].
         btc[check_n[parity_node_index].degree].index = bit_count;
      check_n[parity_node_index].degree =
               check_n[parity_node_index].degree + 1;
      bit_count++;
   }


   //This is just added so that you can easily figure out what value to put in
   //codec_info->max_chk_degree when running a new code
   //Note that the ++ on max_connections from what it actually is
   //comes from it's legacy implementation where the degree's were all 1 larger
   //than they are now because I pulled the self parity bit out of the check_n
   //table as it was pointless to have in there for the encoder BUT
   //It makes a difference for the decoder as it is technically part of the
   //calculation i think so make sure to keep the values as they are for now
   //until you investigate and learn otherwise

   //You can just comment this out if you are not using it
   int max_connections = 0;
   for(j = 0; j < codec_info.number_of_parity_bits; j++)
   {
      if(max_connections < check_n[j].degree)
      {
         max_connections = check_n[j].degree;
      }
   }
   max_connections++;
   printf("max connections is %d\n", max_connections);
}

bool allocate_LDPC_encoder_memory(BIT_NODES **bit_n, CHECK_NODES **check_n)
{
      if(
         ((*bit_n = (BIT_NODES *)
                  calloc(MAX_BLOCK_SIZE, sizeof(BIT_NODES))) == NULL) ||
         ((*check_n = (CHECK_NODES *)
                  calloc(MAX_CHECK_NODES, sizeof(CHECK_NODES))) == NULL)
        )
      {
         printf("Insufficient memory available for encoder construction\n");
         return(true);
      }
      return(false);
}

void ldpc_encoder(Codec_Specification &codec_info,
                  CHECK_NODES *check_n,
                  DIGITAL *encoded_bits)
{

   int i, j, pa;

   for(j = 0; j < codec_info.number_of_parity_bits; j++)
   {
      pa = 0;
      //iterate over the number of bits connected to a parity node
      for(i = 0; i < check_n[j].degree; i++)
      {
         pa += encoded_bits[check_n[j].btc[i].index];
      }
      //Once all the parity bits have been accumulated set the corresponding
      //parity bit appropriately by doing a bitwise and by 0001 to see what the
      //parity bit is (if it were xor accumulated)
      if(pa & 1)
      {
         encoded_bits[codec_info.k + j] = 1;
      }
      else
      {
         encoded_bits[codec_info.k + j] = 0;
      }
   }
}
