#ifndef TYPEDEFS_H_
#define TYPEDEFS_H_

#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string.h>
#include "data_functions.h"

typedef bool DIGITAL;

typedef enum CODEINDEX
{
   S2_SF_1_4 = 0,
   S2_SF_1_3 = 1,
   S2_SF_2_5 = 2,
   S2_SF_1_2 = 3,
   S2_SF_3_5 = 4,
   S2_SF_2_3 = 5,
   S2_SF_3_4 = 6,
   S2_SF_4_5 = 7,
   S2_SF_5_6 = 8,
   S2_SF_8_9 = 9,

   S2_NF_1_4 = 10,
   S2_NF_1_3 = 11,
   S2_NF_2_5 = 12,
   S2_NF_1_2 = 13,
   S2_NF_3_5 = 14,
   S2_NF_2_3 = 15,
   S2_NF_3_4 = 16,
   S2_NF_4_5 = 17,
   S2_NF_5_6 = 18,
   S2_NF_8_9 = 19,
   S2_NF_9_10 = 20,

   AB_x6_1_3 = 30,
   AB_x4_1_3 = 31,
   AB_x3_1_3 = 32,
   AB_x2_1_3 = 33,
   AB_x1_1_5 = 34,
   AB_x1_4_15 = 35,
   AB_x1_1_3 = 36,

   AB_SF_1_4 = 40,
   AB_SF_4_15 = 41,
   AB_SF_1_3 = 42,
   AB_SF_2_5 = 43,
   AB_SF_1_2 = 44, //there may be an error in the .dat file for this one
   AB_SF_8_15 = 45,
   AB_SF_3_5 = 46,
   AB_SF_2_3 = 47,
   AB_SF_3_4 = 48,

   AB_MF_2_5 = 50,
   AB_MF_7_15 = 51,
   AB_MF_8_15 = 52,
   AB_MF_3_5 = 53,
   AB_MF_2_3 = 54,
   AB_MF_3_4 = 55,
   AB_MF_4_5 = 56,

   AB_LF_7_10 = 60,
   AB_LF_3_4 = 61,
   AB_LF_4_5 = 62,
   AB_LF_5_6 = 63,
   AB_LF_8_9 = 64,
   AB_LF_9_10 = 65

};

#endif /* TYPEDEFS_H_ */
