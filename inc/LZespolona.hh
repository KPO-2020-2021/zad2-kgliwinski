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

LZespolona Sprzezenie(  LZespolona Skl);

double Modul2(  LZespolona Skl);










};

std::ostream & operator << ( std::ostream & stdout ,   LZespolona Skl);

std::istream & operator >> ( std::istream & stdin,  LZespolona & Skl);

LZespolona  operator - (  LZespolona Skl1,   LZespolona Skl2);


LZespolona  operator * (  LZespolona Skl1,   LZespolona Skl2);


LZespolona  operator / (  LZespolona Skl1,   LZespolona Skl2);

bool  operator == (  LZespolona  Skl1,    LZespolona  Skl2);

LZespolona  operator + (  LZespolona  Skl1,    LZespolona  Skl2);

LZespolona operator / (  LZespolona Skl1,   double Skl2);
#endif
