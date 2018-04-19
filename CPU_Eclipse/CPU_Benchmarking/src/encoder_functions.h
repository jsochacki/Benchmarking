
#ifndef ENCODER_FUNCTIONS_H_
#define ENCODER_FUNCTIONS_H_

#define MAX_BIT_DEGREE 14
#define CHECK_DEGREE 30

#define MAX_BLOCK_SIZE 65536    // !!! caution! to allow the use of unsigned short

struct BCH_SPEC
{
   unsigned char  t;
   unsigned char  m;
   unsigned short n;
   unsigned short k;
   bool           *gen;       // pointer to the appro. generator metrics
};

struct Codec_Specification
{
   unsigned short code_index; //Code index to select code rate
   unsigned short n;    // Total code block size
   unsigned short k;    // Information bits
   unsigned short number_of_parity_bits;    // number_of_parity_bits
   unsigned char  elite_degree;  // Guide code construction from LDPC_*.dat
   unsigned short elite_end;  // Guide code construction from LDPC_*.dat
   int            repeat;  // mostly used for LDA
   int            max_chk_degree; // Only used for LDA
   char           LDPC_dat[25]; // File name for the address seed table
   int            total_edges;
   BCH_SPEC       BCH;     // BCH code spec
   double         coderate;   // Code rate
};

struct BITS_ON_CHECK
{
    unsigned short index;   // The index of the check nodes connected to bit node
    unsigned char bit_loc;        // The bit node is the "bit_loc"th connection to check node
};

struct CHECK_TO_BIT
{
    unsigned short index;  // The index of the bit nodes connected to the check node
    char w;                    // The soft information from check node to bit node
};

struct BIT_NODES
{
    unsigned char degree;
    BITS_ON_CHECK boc[MAX_BIT_DEGREE];
};

struct CHECK_NODES
{
    unsigned char degree;
    CHECK_TO_BIT ctb[CHECK_DEGREE];
};

bool code_spec(Codec_Specification *, BIT_NODES *, CHECK_NODES *);

bool ldpc_construct (Codec_Specification &, BIT_NODES *, CHECK_NODES *);

#endif /* ENCODER_FUNCTIONS_H_ */
