#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"
#include "WyrazenieZesp.hh"

/*test4.cpp poswiecony jest sprawdzaniu wczytywania oraz wypiywania LZesp oraz WyrZesp*/
/* Testy 1-9 sprawdzaja LZesp, a 10-20 WyrZesp */

TEST_CASE("Test 1: LZespolona proste wczytanie")
{
    LZespolona x;

    std::istringstream in("(1+10i)");
    in >> x;
    std::ostringstream out;
    out << x; // lub strcmp? ew. == dla LZesp

    CHECK("(1+10i)" == out.str());
}

TEST_CASE("Test 2: LZespolona wczytanie malej liczby")
{
    LZespolona x;

    std::istringstream in("(0.0000001+0.0000001i)");
    in >> x;
    std::ostringstream out;
    out << x; // lub strcmp? ew. == dla LZesp

    CHECK("(1e-07+1e-07i)" == out.str()); /*double wyswietla sie w taki sposob dla malych liczb*/
}

TEST_CASE("Test 3: LZespolona - wyswietlanie standard")
{
    LZespolona x;

    x.re = 2;
    x.im = 2;

    std::ostringstream out;

    out << x;
 
    CHECK("(2+2i)" == out.str());
}

TEST_CASE("Test 4: LZespolona - wyswietlanie zaokraglone")
{
    LZespolona x;

    x.re = 2.0 / 3.0;
    x.im = 2.0 / 3.0;

    std::ostringstream out;

    out << x;
 
    CHECK("(0.6667+0.6667i)" == out.str()); /*zaokraglenie do 4 miejsca po przecinku*/
}

TEST_CASE("Test 5: LZespolona wczytanie blednej liczby 1")
{
    LZespolona x;

    std::istringstream in("1+1i)");
    in >> x;
    std::ostringstream out;

    if (in.fail())
    {
        out << "Blad zapisu liczby zespolonej. Sprobuj jeszcze raz."; /*rozwiazanie tego tak samo jak w main*/
    }
    else
        out << x; /*jesli jednak program nie zwroci bledu wczytania*/

    CHECK("Blad zapisu liczby zespolonej. Sprobuj jeszcze raz." == out.str()); /*double wyswietla sie w taki sposob dla malych liczb*/
}

TEST_CASE("Test 6: LZespolona wczytanie blednej liczby 2")
{
    LZespolona x;

    std::istringstream in("(1+1)");
    in >> x;
    std::ostringstream out;

    if (in.fail())
    {
        out << "Blad zapisu liczby zespolonej. Sprobuj jeszcze raz."; /*rozwiazanie tego tak samo jak w main*/
    }
    else
        out << x; /*jesli jednak program nie zwroci bledu wczytania*/

    CHECK("Blad zapisu liczby zespolonej. Sprobuj jeszcze raz." == out.str()); /*double wyswietla sie w taki sposob dla malych liczb*/
}

TEST_CASE("Test 7: LZespolona wczytanie blednej liczby 3")
{
    LZespolona x;

    std::istringstream in("(11i)");
    in >> x;
    std::ostringstream out;

    if (in.fail())
    {
        out << "Blad zapisu liczby zespolonej. Sprobuj jeszcze raz."; /*rozwiazanie tego tak samo jak w main*/
    }
    else
        out << x; /*jesli jednak program nie zwroci bledu wczytania*/

    CHECK("Blad zapisu liczby zespolonej. Sprobuj jeszcze raz." == out.str()); /*double wyswietla sie w taki sposob dla malych liczb*/
}

TEST_CASE("Test 8: LZespolona wczytanie blednej liczby 3")
{
    LZespolona x;

    std::istringstream in("(1==1i)");
    in >> x;
    std::ostringstream out;

    if (in.fail())
    {
        out << "Blad zapisu liczby zespolonej. Sprobuj jeszcze raz."; /*rozwiazanie tego tak samo jak w main*/
    }
    else
        out << x; /*jesli jednak program nie zwroci bledu wczytania*/

    CHECK("Blad zapisu liczby zespolonej. Sprobuj jeszcze raz." == out.str()); /*double wyswietla sie w taki sposob dla malych liczb*/
}

TEST_CASE("Test 9: LZespolona wczytanie blednej liczby 4")
{
    LZespolona x;

    std::istringstream in("");
    in >> x;
    std::ostringstream out;

    if (in.fail())
    {
        out << "Blad zapisu liczby zespolonej. Sprobuj jeszcze raz."; /*rozwiazanie tego tak samo jak w main*/
    }
    else
        out << x; /*jesli jednak program nie zwroci bledu wczytania*/

    CHECK("Blad zapisu liczby zespolonej. Sprobuj jeszcze raz." == out.str()); /*double wyswietla sie w taki sposob dla malych liczb*/
}


TEST_CASE("Test 10: WyrZespolone proste wczytanie")
{
    WyrazenieZesp x;

    std::istringstream in("(1+10i)+(2+11i)");
    in >> x;
    std::ostringstream out;
    out << x; // lub strcmp? ew. == dla LZesp

    CHECK("(1+10i)+(2+11i)" == out.str());
}

TEST_CASE("Test 11: WyrZespolone wczytanie malych wartosci")
{
    WyrazenieZesp x;

    std::istringstream in("(0.00001+0.00001i)+(0.00002+0.00002i)");
    in >> x;
    std::ostringstream out;
    out << x; // lub strcmp? ew. == dla LZesp

    CHECK("(1e-05+1e-05i)+(2e-05+2e-05i)" == out.str());
}

TEST_CASE("Test 12: WyrZespolone wyswietlanie standard (+)")
{
    WyrazenieZesp x;

    x.Arg1.re = 2;
    x.Arg1.im = 2;

    x.Op = Op_Dodaj;

    x.Arg2.re = 3;
    x.Arg2.im = 3;
    std::ostringstream out;

    out << x;

    CHECK("(2+2i)+(3+3i)" == out.str());
}

TEST_CASE("Test 13: WyrZespolone wyswietlanie standard (-)")
{
    WyrazenieZesp x;

    x.Arg1.re = 2;
    x.Arg1.im = 2;

    x.Op = Op_Odejmij;

    x.Arg2.re = 3;
    x.Arg2.im = 3;
    std::ostringstream out;

    out << x;

    CHECK("(2+2i)-(3+3i)" == out.str());
}

TEST_CASE("Test 14: WyrZespolone wyswietlanie standard (*)")
{
    WyrazenieZesp x;

    x.Arg1.re = 2;
    x.Arg1.im = 2;

    x.Op = Op_Mnoz;

    x.Arg2.re = 3;
    x.Arg2.im = 3;
    std::ostringstream out;

    out << x;

    CHECK("(2+2i)*(3+3i)" == out.str());
}

TEST_CASE("Test 15: WyrZespolone wyswietlanie standard (/)")
{
    WyrazenieZesp x;

    x.Arg1.re = 2;
    x.Arg1.im = 2;

    x.Op = Op_Dziel;

    x.Arg2.re = 3;
    x.Arg2.im = 3;
    std::ostringstream out;

    out << x;
 
    CHECK("(2+2i)/(3+3i)" == out.str());
}

TEST_CASE("Test 16: WyrZespolone wyswietlanie zaokraglone")
{
    WyrazenieZesp x;

    x.Arg1.re = 2.0 / 3.0;
    x.Arg1.im = 2.0 / 3.0;

    x.Op = Op_Odejmij;

    x.Arg2.re = 3.0 / 7.0;
    x.Arg2.im = 3.0 / 7.0;
    std::ostringstream out;

    out << x;

    CHECK("(0.6667+0.6667i)-(0.4286+0.4286i)" == out.str());
}

TEST_CASE("Test 17: WyrZespolone wczytywanie blednej liczby (bez operatora)")
{
    WyrazenieZesp x;

    std::istringstream in("(0.00001+0.00001i)(0.00002+0.00002i)");

    WARN_THROWS(in >> x);
}

TEST_CASE("Test 18: Wyrzespolone wczytanie blednego wyrazenia (blad w LZespolonej) 1")
{
    WyrazenieZesp x;

    std::istringstream in("1+1i)+(1+1i)");

    WARN_THROWS(in >> x);
}

TEST_CASE("Test 19: Wyrzespolone wczytanie blednego wyrazenia (blad w LZespolonej) 2")
{
    WyrazenieZesp x;

    std::istringstream in("(1+2)+(2=1i)");

    WARN_THROWS(in >> x);
}

TEST_CASE("Test 20: Wyrzespolone wczytanie blednego wyrazenia (blad w LZespolonej) 3")
{
    WyrazenieZesp x;

    std::istringstream in("");

    WARN_THROWS(in >> x);
}