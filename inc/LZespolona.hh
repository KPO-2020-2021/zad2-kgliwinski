#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include<iostream>
#include <stdexcept>
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

LZespolona Sprzezenie() const;

double Modul2() const; 

LZespolona  operator - ( LZespolona Skl2) const;

LZespolona  operator * (LZespolona Skl2) const;

LZespolona  operator / (LZespolona Skl2) const;

bool  operator == (LZespolona Skl2) const ;

LZespolona  operator + (LZespolona  Skl2) const;

LZespolona operator / (double Skl2) const;

};

std::ostream & operator << ( std::ostream & stdwyj, LZespolona Skl);

std::istream & operator >> ( std::istream & stdwej, LZespolona & Skl);

void blad_wczyt (std::istream & stdwej);

bool czyt_sym (std::istream &stdwej, char znak);


#endif
