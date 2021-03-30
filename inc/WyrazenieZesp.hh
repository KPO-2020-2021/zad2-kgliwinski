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


  LZespolona Oblicz();
};


/*
 * Funkcje ponizej nalezy zdefiniowac w module.
 *
 */


std::ostream & operator << (std::ostream & stdwyj,   WyrazenieZesp  WyrZ);  /*przeciazenie operatora wyjscia dla WyrazeniaZesp*/

char read_sym(Operator ope);      /*funkcja czytajaca operator*/
Operator get_sym(char ope);       /*funkcja zapisujaca operator*/

std::istream & operator >> (std::istream & stdwej, WyrazenieZesp & WyrZ);   /*przeciazenie operatora czytania dla WyrazeniaZesp */



#endif
