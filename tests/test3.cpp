#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

/*test3.cpp poswiecony jest funkcji sprzezenie oraz modul kwadratowy z LZespolonej*/
/*testy 1-3 sprawdzaja Sprzezenie(); testy 4-7 Modul2()*/

TEST_CASE("Test 1: LZespolona sprzezenie proste")
{
    LZespolona x, y;

    x.re = 3;
    x.im = 2;

    y.re = 3;
    y.im = -2;

    CHECK(x.Sprzezenie() == y);
}

TEST_CASE("Test 2: LZespolona sprzezenie (3+0i)")
{
    LZespolona x, y;

    x.re = 3;
    x.im = 0;

    y.re = 3;
    y.im = 0;

    CHECK(x.Sprzezenie() == y);
}

TEST_CASE("Test 3: LZespolona sprzezenie malych liczb")
{
    LZespolona x, y;

    x.re = 3;
    x.im = 0.00001;

    y.re = 3;
    y.im = -0.00001;

    CHECK(x.Sprzezenie() == y);
}

TEST_CASE("Test 4: LZespolona kwadrat modulu")
{
    LZespolona x;
    double t;

    x.re = 3;
    x.im = 4;

    t=25;

    CHECK(x.Modul2() == t);
}


TEST_CASE("Test 5: LZespolona kwadrat modulu re=0")
{
    LZespolona x;
    double t;

    x.re = 4;
    x.im = 0;

    t=16;

    CHECK(x.Modul2() == t);
}


TEST_CASE("Test 6: LZespolona kwadrat modulu im=0")
{
    LZespolona x;
    double t;

    x.re = 3;
    x.im = 0;

    t=9;

    CHECK(x.Modul2() == t);
}


TEST_CASE("Test 7: LZespolona kwadrat modulu (0+0i)")
{
    LZespolona x;
    double t;

    x.re = 0;
    x.im = 0;

    t=0;

    CHECK(x.Modul2() == t);
}