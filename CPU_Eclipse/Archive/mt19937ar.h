#ifndef _mt19937ar_h
#define _mt19937ar_h

void mt_init_urv(unsigned long);
unsigned long genrand_int32(void);
double mt_uniform(void);
void mt_gauss(double&, double&);

#endif
