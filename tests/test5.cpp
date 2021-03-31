#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"
#include "WyrazenieZesp.hh"

/*test5.cpp poswiecony jest sprawdzaniu operacji matematycznych dla WyrZesp*/
/*test 1-5 dodawanie, test 6-10 odejmowanie, test 11-16 mnozenie, test 17-23*/

TEST_CASE("Test 1: WyrZespolone suma standard")
{
    WyrazenieZesp x;
    LZespolona y;

    x.Arg1.re = 1;
    x.Arg1.im = 2;

    x.Op = Op_Dodaj;

    x.Arg2.re = 3;
    x.Arg2.im = 3;

    y.re = 4;
    y.im = 5;

    CHECK(x.Oblicz() == y);
}

TEST_CASE("Test 2: WyrZespolone suma male liczby")
{
    WyrazenieZesp x;
    LZespolona y;

    x.Arg1.re = 0.0001;
    x.Arg1.im = 0.0002;

    x.Op = Op_Dodaj;

    x.Arg2.re = 0.0003;
    x.Arg2.im = 0.0003;

    y.re = 0.0004;
    y.im = 0.0005;

    CHECK(x.Oblicz() == y);
}

TEST_CASE("Test 3: WyrZespolone suma zaokraglone")
{
    WyrazenieZesp x;
    LZespolona y;

    x.Arg1.re = 2.0 / 3.0;
    x.Arg1.im = 2.0 / 3.0;

    x.Op = Op_Dodaj;

    x.Arg2.re = 1.0 / 3.0;
    x.Arg2.im = 4.0 / 3.0;

    y.re = 1;
    y.im = 2;

    CHECK(x.Oblicz() == y);
}

TEST_CASE("Test 4: WyrZespolone suma ujemne")
{
    WyrazenieZesp x;
    LZespolona y;

    x.Arg1.re = -2.0 / 3.0;
    x.Arg1.im = -2.0 / 3.0;

    x.Op = Op_Dodaj;

    x.Arg2.re = 2.0 / 3.0;
    x.Arg2.im = 2.0 / 3.0;

    y.re = 0;
    y.im = 0;

    CHECK(x.Oblicz() == y);
}

TEST_CASE("Test 5: WyrZespolone suma zero")
{
    WyrazenieZesp x;
    LZespolona y;

    x.Arg1.re = 0;
    x.Arg1.im = 0;

    x.Op = Op_Dodaj;

    x.Arg2.re = 0;
    x.Arg2.im = 0;

    y.re = 0;
    y.im = 0;

    CHECK(x.Oblicz() == y);
}

TEST_CASE("Test 6: WyrZespolone roznica standard")
{
    WyrazenieZesp x;
    LZespolona y;

    x.Arg1.re = 1;
    x.Arg1.im = 2;

    x.Op = Op_Odejmij;

    x.Arg2.re = 3;
    x.Arg2.im = 3;

    y.re = -2;
    y.im = -1;

    CHECK(x.Oblicz() == y);
}

TEST_CASE("Test 7: WyrZespolone roznica male liczby")
{
    WyrazenieZesp x;
    LZespolona y;

    x.Arg1.re = 0.0001;
    x.Arg1.im = 0.0002;

    x.Op = Op_Odejmij;

    x.Arg2.re = 0.0003;
    x.Arg2.im = 0.0003;

    y.re = -0.0002;
    y.im = -0.0001;

    CHECK(x.Oblicz() == y);
}

TEST_CASE("Test 8: WyrZespolone roznica zaokraglone")
{
    WyrazenieZesp x;
    LZespolona y;

    x.Arg1.re = 2.0 / 3.0;
    x.Arg1.im = 2.0 / 3.0;

    x.Op = Op_Odejmij;

    x.Arg2.re = 1.0 / 3.0;
    x.Arg2.im = 4.0 / 3.0;

    y.re = 1.0 / 3.0;
    y.im = -2.0 / 3.0;

    CHECK(x.Oblicz() == y);
}

TEST_CASE("Test 9: WyrZespolone roznica ujemne")
{
    WyrazenieZesp x;
    LZespolona y;

    x.Arg1.re = -2.0 / 3.0;
    x.Arg1.im = -2.0 / 3.0;

    x.Op = Op_Odejmij;

    x.Arg2.re = -2.0 / 3.0;
    x.Arg2.im = -2.0 / 3.0;

    y.re = 0;
    y.im = 0;

    CHECK(x.Oblicz() == y);
}

TEST_CASE("Test 10: WyrZespolone suma zero")
{
    WyrazenieZesp x;
    LZespolona y;

    x.Arg1.re = 0;
    x.Arg1.im = 0;

    x.Op = Op_Odejmij;

    x.Arg2.re = 0;
    x.Arg2.im = 0;

    y.re = 0;
    y.im = 0;

    CHECK(x.Oblicz() == y);
}

TEST_CASE("Test 11: WyrZespolone iloczyn standard")
{
    WyrazenieZesp x;
    LZespolona y;

    x.Arg1.re = 1;
    x.Arg1.im = 2;

    x.Op = Op_Mnoz;

    x.Arg2.re = 2;
    x.Arg2.im = 1;

    y.re = 0;
    y.im = 5;

    CHECK(x.Oblicz() == y);
}

TEST_CASE("Test 12: WyrZespolone iloczyn male liczby")
{
    WyrazenieZesp x;
    LZespolona y;

    x.Arg1.re = 0.0001;
    x.Arg1.im = 0.0002;

    x.Op = Op_Mnoz;

    x.Arg2.re = 0.0002;
    x.Arg2.im = 0.0001;

    y.re = 0;
    y.im = 0.000000005;

    CHECK(x.Oblicz() == y);
}

TEST_CASE("Test 13: WyrZespolone iloczyn zaokraglone")
{
    WyrazenieZesp x;
    LZespolona y;

    x.Arg1.re = 2.0 / 3.0;
    x.Arg1.im = 1.0 / 3.0;

    x.Op = Op_Mnoz;

    x.Arg2.re = 1.0 / 4.0;
    x.Arg2.im = 1.0 / 6.0;

    y.re = 0.1111;
    y.im = 0.1944;

    CHECK(x.Oblicz() == y);
}

TEST_CASE("Test 14: WyrZespolone iloczyn przez 0")
{
    WyrazenieZesp x;
    LZespolona y;

    x.Arg1.re = 2.0 / 3.0;
    x.Arg1.im = 1.0 / 3.0;

    x.Op = Op_Mnoz;

    x.Arg2.re = 0;
    x.Arg2.im = 0;

    y.re = 0;
    y.im = 0;

    CHECK(x.Oblicz() == y);
}

TEST_CASE("Test 15: WyrZespolone 0*0")
{
    WyrazenieZesp x;
    LZespolona y;

    x.Arg1.re = 0;
    x.Arg1.im = 0;

    x.Op = Op_Mnoz;

    x.Arg2.re = 0;
    x.Arg2.im = 0;

    y.re = 0;
    y.im = 0;

    CHECK(x.Oblicz() == y);
}

TEST_CASE("Test 16: WyrZespolone iloczyn liczb ujemnych")
{
    WyrazenieZesp x;
    LZespolona y;

    x.Arg1.re = -1.5;
    x.Arg1.im = -2;

    x.Op = Op_Mnoz;

    x.Arg2.re = -3;
    x.Arg2.im = -4;

    y.re = -3.5;
    y.im = 12;

    CHECK(x.Oblicz() == y);
}

TEST_CASE("Test 17: WyrZespolone iloraz standard")
{
    WyrazenieZesp x;
    LZespolona y;

    x.Arg1.re = 5;
    x.Arg1.im = 2;

    x.Op = Op_Dziel;

    x.Arg2.re = 3;
    x.Arg2.im = 4;

    y.re = 0.92;
    y.im = -0.56;

    CHECK(x.Oblicz() == y);
}

TEST_CASE("Test 18: WyrZespolone iloraz malych liczb")
{
    WyrazenieZesp x;
    LZespolona y;

    x.Arg1.re = 0.0001;
    x.Arg1.im = 0.0002;

    x.Op = Op_Dziel;

    x.Arg2.re = 0.0003;
    x.Arg2.im = 0.0004;

    y.re = 0.44;
    y.im = 0.08;

    CHECK(x.Oblicz() == y);
}

TEST_CASE("Test 19: WyrZespolone iloraz zera")
{
    WyrazenieZesp x;
    LZespolona y;

    x.Arg1.re = 0;
    x.Arg1.im = 0;

    x.Op = Op_Dziel;

    x.Arg2.re = 0.0003;
    x.Arg2.im = 0.0004;

    y.re = 0;
    y.im = 0;

    CHECK(x.Oblicz() == y);
}

TEST_CASE("Test 20: WyrZespolone dzielenie przez 0")
{
    WyrazenieZesp x;

    x.Arg1.re = 0.0003;
    x.Arg1.im = 0.0004;

    x.Op = Op_Dziel;

    x.Arg2.re = 0;
    x.Arg2.im = 0;

     WARN_THROWS(x.Oblicz());
}

TEST_CASE("Test 21: WyrZespolone dzielenie 0 przez 0")
{
    WyrazenieZesp x;

    x.Arg1.re = 0;
    x.Arg1.im = 0;

    x.Op = Op_Dziel;

    x.Arg2.re = 0;
    x.Arg2.im = 0;

     WARN_THROWS(x.Oblicz());
}

TEST_CASE("Test 22: WyrZespolone dzielenie liczb ujemnych")
{
    WyrazenieZesp x;
    LZespolona y;

    x.Arg1.re =-10;
    x.Arg1.im = -20;

    x.Op = Op_Dziel;

    x.Arg2.re = -2;
    x.Arg2.im = 0;

    y.re = 5;
    y.im = 10;

    CHECK(x.Oblicz() == y);
}

TEST_CASE("Test 23: WyrZespolone dzielenie liczb zaokraglonych")
{
    WyrazenieZesp x;
    LZespolona y;

    x.Arg1.re =2.0/3.0;
    x.Arg1.im = -2.0/3.0;

    x.Op = Op_Dziel;

    x.Arg2.re = 1.0/4.0;
    x.Arg2.im = 4.0/7.0;

    y.re = -0.5508;
    y.im = -1.408;

    CHECK(x.Oblicz() == y);
}