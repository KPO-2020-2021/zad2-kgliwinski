#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include<iostream>
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

bool  operator == (const LZespolona  Skl1,  const LZespolona  Skl2);

LZespolona  operator + (const LZespolona  Skl1, const  LZespolona  Skl2);

LZespolona operator / (const LZespolona Skl1, const double Skl2);

LZespolona Sprzezenie(const LZespolona Skl);


double Modul2(const LZespolona Skl);


LZespolona  operator - (const LZespolona Skl1, const LZespolona Skl2);


LZespolona  operator * (const LZespolona Skl1, const LZespolona Skl2);


LZespolona  operator / (const LZespolona Skl1,const  LZespolona Skl2);


std::ostream & operator << ( std::ostream & stdout , const LZespolona Skl);

std::istream & operator >> ( std::istream & stdin,  LZespolona & Skl);

#endif
