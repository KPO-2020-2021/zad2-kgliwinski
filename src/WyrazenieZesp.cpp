#include "WyrazenieZesp.hh"


/************************************************************/
/* Definiuje w jaki sposob wyswietlac wyrazenia zespolone   */
/* Argumenty:                                               */
/*    stdwyj - operator strumienia wyjsciowego              */
/*    WyrZ - wyswietlane wyrazenie zespolone                */
/* Zwraca:                                                  */
/*    wyswietlone odpowienio wyrazenie WyrZ                 */
/************************************************************/
std::ostream &operator<<(std::ostream &stdwyj,   WyrazenieZesp WyrZ)
{
    stdwyj<<'('<<WyrZ.Arg1.re<<std::showpos<<WyrZ.Arg1.im<<std::noshowpos<<'i'<<')';
    stdwyj<<read_sym(WyrZ.Op);
    stdwyj<<'('<<WyrZ.Arg2.re<<std::showpos<<WyrZ.Arg2.im<<std::noshowpos<<'i'<<')';
    return stdwyj;
}
/************************************************************/
/* Definiuje w jaki sposob wczytywac znak do operatora      */
/* Argumenty:                                               */
/*    ope - tablica znakow ze znakiem +,-,* lub /           */
/* Zwraca:                                                  */
/*    Operator oper                                         */
/************************************************************/
Operator get_sym(char ope)
{
    Operator oper;
    switch (ope){
        case '+':
            oper = Op_Dodaj;
            break;
        case '-':
            oper = Op_Odejmij;
            break;
        case '*':
            oper = Op_Mnoz;
            break;
        case '/':
            oper = Op_Dziel;
            break;
        default:
            std::cerr<<"Bledny operator matematyczny";
            break;
    }
    return oper;
}
/************************************************************/
/* Definiuje w jaki sposob wyswietlac znak z operatora      */
/* Argumenty:                                               */
/*    ope - operator okreslajacy znak +,-,* lub /           */
/* Zwraca:                                                  */
/*    tablice znakow sym z symbolem +,-,*,/                 */
/************************************************************/
char read_sym(  Operator ope){
    char sym;
    switch (ope){
        case Op_Dodaj:
            sym='+';
            break;
        case Op_Odejmij:
            sym='-';
            break;
        case Op_Mnoz:
            sym='*';
            break;
        case Op_Dziel:
            sym='/';
            break;
        default:
            std::cerr<<"Nie podano operatora";
            sym='\0';
            break;
    }
    return sym;
}
/************************************************************/
/* Definiuje w jaki sposob wczytywac wyrazenia zespolone    */
/* Argumenty:                                               */
/*    stdwej - operator strumienia wyjsciowego              */
/*    WyrZ - wczytywane wyrazenie zespolone                 */
/* Zwraca:                                                  */
/*    wczytane odpowiednio wyrazenie zespolone WyrZ         */
/************************************************************/
std::istream &operator>>(std::istream &stdwej, WyrazenieZesp & WyrZ)
{
    char znak;
	stdwej >> WyrZ.Arg1;
	stdwej >> znak;
	WyrZ.Op = get_sym(znak);
	stdwej >> WyrZ.Arg2;
	return stdwej;
}


/************************************************************/
/* Definiuje w jaki sposob obliczyc wyrazenia zespolone     */
/* Argumenty:                                               */
/*    WyrZ - obliczane wyrazenie zespolone                  */
/* Zwraca:                                                  */
/*    LZespolona bedaca wynikiem obliczonego wyrazenia      */
/************************************************************/
LZespolona Oblicz(  WyrazenieZesp  WyrZ){
    LZespolona wynik;
    switch (WyrZ.Op){
        case Op_Dodaj:
            wynik = WyrZ.Arg1 + WyrZ.Arg2;
            break;
        case Op_Odejmij:
            wynik = WyrZ.Arg1 - WyrZ.Arg2;
            break;
        case Op_Mnoz:
            wynik = WyrZ.Arg1 * WyrZ.Arg2;
            break;
        case Op_Dziel:
            wynik = WyrZ.Arg1 / WyrZ.Arg2;
            break;

    return wynik;
    }
    return wynik;
}