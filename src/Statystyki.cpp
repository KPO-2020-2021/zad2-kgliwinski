#include "Statystyki.hh"


double statystyki::licz_odp(){
     proc_popr = (double)popr/((double)popr+(double)bled) * 100;
     return proc_popr;
}

std::ostream & operator << ( std::ostream & stdwyj , statystyki stat){
    stdwyj<<"Ilosc dobrych odpowiedzi: " << stat.popr << std::endl;
    stdwyj<<"Ilosc blednych odpowiedzi: " << stat.bled << std::endl;
    stdwyj<<"Wynik procentowy poprawnych odpowiedzi: "<< stat.licz_odp() << " %" << std::endl;
    return stdwyj;
}