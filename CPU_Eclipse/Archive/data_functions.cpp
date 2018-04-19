#include "mt19937ar.h"

bool random_bit_generator(void)
{
    //generates a random integer from 0x0 to 0xffffffff and and with 1 to get
    //1 or 0 out of it
    return (bool)(genrand_int32() & 0x01);
}
