
#ifndef ENCODER_FUNCTIONS_H_
#define ENCODER_FUNCTIONS_H_

#include "typedefs.h"

#define MAX_CHECK_NODES 48600 // rate 1/4 64K code

#define MAX_BIT_DEGREE 14       //sufficient for DVBS2
#define CHECK_DEGREE 30

//There will be a maximum of 64800 in reality if everything is done right
#define MAX_BLOCK_SIZE 65536    // !!! caution! to allow the use of unsigned short

struct BCH_SPEC
{
   unsigned char  t;
   unsigned char  m;
   unsigned short n;
   unsigned short k;
   bool           *gen;       // pointer to the generator metrics
};

struct Codec_Specification
{
   CODEINDEX code_index; //Code index to select code rate
   unsigned short n;    // Total code block size
   unsigned short k;    // Information bits
   unsigned short number_of_parity_bits;    // number_of_parity_bits
   unsigned char  elite_degree;  // Guide code construction from *.dat
   unsigned short elite_end;  // Guide code construction from *.dat
   int            repeat;  // Guide code construction from *.dat and for LDA
   int            max_chk_degree; // Only used for LDA
   char           LDPC_dat[20]; // File name for the address seed table
   int            total_edges;
   BCH_SPEC       BCH;     // BCH code spec
   double         coderate;   // Code rate
};

struct CHECKS_ON_BIT
{
    unsigned short index;   // The index of the check nodes connected to bit node
    unsigned char bit_loc;        // The bit node is the "bit_loc"th connection to check node
};

struct BIT_TO_CHECK
{
    unsigned short index;  // The index of the bit nodes connected to the check node
    char w;                    // The soft information from check node to bit node
};

struct BIT_NODES
{
    unsigned char degree;
    CHECKS_ON_BIT cob[MAX_BIT_DEGREE];
};

struct CHECK_NODES
{
    unsigned char degree;
    BIT_TO_CHECK btc[CHECK_DEGREE];
};

bool code_spec(Codec_Specification *, BIT_NODES *, CHECK_NODES *);

bool ldpc_construct (Codec_Specification &, BIT_NODES *, CHECK_NODES *);

void bit_checks(int , int , int , unsigned short *, int &, BIT_NODES *);

bool allocate_LDPC_encoder_memory(BIT_NODES **, CHECK_NODES **);

void ldpc_encoder(Codec_Specification &, CHECK_NODES *, DIGITAL *);

#endif /* ENCODER_FUNCTIONS_H_ */
