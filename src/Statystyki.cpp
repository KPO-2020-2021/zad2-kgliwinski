#include "Statystyki.hh"

/************************************************************/
/* Liczy % poprawnych odpowiedzi w tescie                   */
/* Argumenty:                                               */
/*    zmienna typu statystyki                               */
/* Zwraca:                                                  */
/*    proc_popr - stosunek odpowiedzi poprawnych do         */
/*                całkowitej liczby odpowiedzi              */
/************************************************************/
double statystyki::licz_odp()
{
    proc_popr = (double)popr / ((double)popr + (double)bled) * 100; /*obliczenie % poprawnych odpowiedzi na wszystkie*/
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
std::ostream &operator<<(std::ostream &stdwyj, statystyki stat)
{
    if (stat.popr + stat.bled == 0)
        stdwyj << "Nie podano żadnych odpowiedzi. Liczba odpowiedzi poprawnych oraz błędnych wynosi 0." << std::endl;    /*w przypadku gdy nie wykonano testow*/
    else
    {
        stdwyj << "Ilosc dobrych odpowiedzi: " << stat.popr << std::endl; /*wypisywana zawartosc zgodnie ze stylem podanym w tresci zadania*/
        stdwyj << "Ilosc blednych odpowiedzi: " << stat.bled << std::endl;
        stdwyj << "Wynik procentowy poprawnych odpowiedzi: " << stat.licz_odp() << " %" << std::endl;
    }
    return stdwyj;
}