#ifndef STATYSTYKI_HH
#define STATYSTYKI_HH
#include <iostream>

struct statystyki{
double proc_popr;
unsigned int popr;
unsigned int bled;

double licz_odp();
};

std::ostream & operator << ( std::ostream & stdwyj , statystyki stat);

#endif
