#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH


#include<iostream>
#include "LZespolona.hh"



/*!
 * Modeluje zbior operatorow arytmetycznych.
 */
enum Operator { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel };



/*
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego
 */
struct WyrazenieZesp {
  LZespolona   Arg1;   // Pierwszy argument wyrazenia arytmetycznego
  Operator     Op;     // Opertor wyrazenia arytmetycznego
  LZespolona   Arg2;   // Drugi argument wyrazenia arytmetycznego
};


/*
 * Funkcje ponizej nalezy zdefiniowac w module.
 *
 */


std::ostream & operator << (std::ostream & stdwyj,   WyrazenieZesp  WyrZ);

Operator get_sym(char ope);

char read_sym(  Operator ope);

std::istream & operator >> (std::istream & stdwej, WyrazenieZesp & WyrZ);

LZespolona Oblicz(  WyrazenieZesp  WyrZ);

#endif
