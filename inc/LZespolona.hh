#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include<iostream>
using namespace std;
/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};


/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */

bool  operator == (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona operator / (LZespolona Skl1, double Skl2);

LZespolona Sprzezenie(LZespolona Skl);


double Modul2(LZespolona Skl);


LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);


LZespolona  operator - (LZespolona Skl1, LZespolona Skl2);


LZespolona  operator * (LZespolona Skl1, LZespolona Skl2);


LZespolona  operator / (LZespolona Skl1, LZespolona Skl2);


ostream & operator << ( ostream & stdout , LZespolona Skl);

istream & operator >> ( istream & stdin,  LZespolona & Skl);

#endif
