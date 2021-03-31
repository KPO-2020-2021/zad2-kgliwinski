#ifndef STATYSTYKI_HH
#define STATYSTYKI_HH
#include <iostream>

struct statystyki{
double proc_popr;       /*% poprawnych odpowiedzi (liczy go funkcja licz_odp())*/
unsigned int popr;      /*liczba odpowiedzi poprawnych*/
unsigned int bled;      /*liczba odpowiedzi blednych*/

double licz_odp();      /*liczenie % poprawnych odpowiedzi*/

statystyki(){           /*inicjalizacja struktury z domyslnymi wartosciami (zawsze takie sa pozadane)*/
    popr=0; bled=0;
}
friend std::ostream & operator << ( std::ostream & stdwyj , statystyki stat);
};



#endif
