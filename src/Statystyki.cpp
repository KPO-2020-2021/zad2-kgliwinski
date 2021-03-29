#include "Statystyki.hh"

/************************************************************/
/* Liczy % poprawnych odpowiedzi w tescie                   */
/* Argumenty:                                               */
/*    zmienna typu statystyki                               */
/* Zwraca:                                                  */
/*    proc_popr - stosunek odpowiedzi poprawnych do         */
/*                całkowitej liczby odpowiedzi              */
/************************************************************/
double statystyki::licz_odp(){
     proc_popr = (double)popr/((double)popr+(double)bled) * 100;
     return proc_popr;
}


/************************************************************/
/* Definiuje w jaki sposob wyswietlac statystyki            */
/* Argumenty:                                               */
/*    stdwyj - operator strumienia wyjsciowego              */
/*    stat - wyswietlana struktura statystyk                */
/* Zwraca:                                                  */
/*    wyswietlona odpowiednio informacje o statystykach     */
/************************************************************/
std::ostream & operator << ( std::ostream & stdwyj , statystyki stat){
    stdwyj<<"Ilosc dobrych odpowiedzi: " << stat.popr << std::endl;
    stdwyj<<"Ilosc blednych odpowiedzi: " << stat.bled << std::endl;
    stdwyj<<"Wynik procentowy poprawnych odpowiedzi: "<< stat.licz_odp() << " %" << std::endl;
    return stdwyj;
}