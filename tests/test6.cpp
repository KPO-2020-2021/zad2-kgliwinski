#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"
#include "WyrazenieZesp.hh"
#include "Statystyki.hh"

/*test6.cpp poswiecony jest sprawdzaniu funkcji statystyk, liczenia i wypisywania odowiednich wynikow*/
/**/

TEST_CASE("Test 1: Statystyki - wyliczenie i wyswietlenie 1")
{
    statystyki a;
    a.popr=3;
    a.bled=7;

    std::ostringstream out;
    out << a; // lub strcmp? ew. == dla LZesp

    CHECK("Ilosc dobrych odpowiedzi: 3\nIlosc blednych odpowiedzi: 7\nWynik procentowy poprawnych odpowiedzi: 30 %\n"==out.str());
}

TEST_CASE("Test 2: Statystyki - wyliczenie i wyswietlenie 2")
{
    statystyki a;
    a.popr=1;
    a.bled=2;

    std::ostringstream out;
    out << a; // lub strcmp? ew. == dla LZesp

    CHECK("Ilosc dobrych odpowiedzi: 1\nIlosc blednych odpowiedzi: 2\nWynik procentowy poprawnych odpowiedzi: 33.3333 %\n"==out.str());
}

TEST_CASE("Test 3: Statystyki - wyliczenie i wyswietlenie 3")
{
    statystyki a;
    a.popr=0;
    a.bled=5;

    std::ostringstream out;
    out << a; // lub strcmp? ew. == dla LZesp

    CHECK("Ilosc dobrych odpowiedzi: 0\nIlosc blednych odpowiedzi: 5\nWynik procentowy poprawnych odpowiedzi: 0 %\n"==out.str());
}

TEST_CASE("Test 4: Statystyki - wyliczenie i wyswietlenie 4")
{
    statystyki a;
    a.popr=5;
    a.bled=0;

    std::ostringstream out;
    out << a; // lub strcmp? ew. == dla LZesp

    CHECK("Ilosc dobrych odpowiedzi: 5\nIlosc blednych odpowiedzi: 0\nWynik procentowy poprawnych odpowiedzi: 100 %\n"==out.str());
}

TEST_CASE("Test 5: Statystyki - wyliczenie dla braku odpowiedzi")
{
    statystyki a;
    a.popr=0;
    a.bled=0;

    std::ostringstream out;
    out << a; // lub strcmp? ew. == dla LZesp

    CHECK("Nie podano żadnych odpowiedzi. Liczba odpowiedzi poprawnych oraz błędnych wynosi 0.\n"==out.str());
}