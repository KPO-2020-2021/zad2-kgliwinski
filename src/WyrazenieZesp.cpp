#include "WyrazenieZesp.hh"

/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */
/************************************************************/
/* Definiuje w jaki sposob wyswietlac wyrazenia zespolone   */
/* Argumenty:                                               */
/*    stdwyj - operator strumienia wyjsciowego              */
/*    WyrZ - wyswietlane wyrazenie zespolone                */
/* Zwraca:                                                  */
/*    wyswietlone odpowienio wyrazenie WyrZ                 */
/************************************************************/
ostream &operator<<(ostream &stdwyj, WyrazenieZesp WyrZ)
{
    stdwyj<<'('<<WyrZ.Arg1.re<<showpos<<WyrZ.Arg1.im<<noshowpos<<'i'<<')';
    stdwyj<<read_sym(WyrZ.Op);
    stdwyj<<'('<<WyrZ.Arg2.re<<showpos<<WyrZ.Arg2.im<<noshowpos<<'i'<<')';
    return stdwyj;
}

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
            oper=Op_Dziel;
            break;
        default:
            cerr<<"Bledny operator matematyczny";
            break;
    }
    return oper;
}

char read_sym(Operator ope){
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
            cerr<<"Nie podano operatora";
            sym='\0';
            break;
    }
    return sym;
}

istream &operator>>(istream &stdwe, WyrazenieZesp & WyrZ)
{
    
}