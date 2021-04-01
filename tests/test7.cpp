#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"
#define PI 3.1415926535
#define MIN_DIFF 0.0001
/*test7.cpp zawiera testy dodatkowych funkcji (przeciazen operatorow += i /= oraz funkcji arg()) z uzupelnienia programu*/
/*testy 1-7 sprawdzaja dzielenie z przypisaniem, 5-12 sume z przypisaniem, 13-16 funkcje arg()  */

TEST_CASE("Test 1: LZespolona dzielenie przez LZesp z przypisaniem 1")
{
    LZespolona x, y, z;

    x.re = 3;
    x.im = 3;

    y.re = 1;
    y.im = 3;

    x /= y;

    z.re = 1.2;
    z.im = -0.6;

    CHECK(x == z);
}

TEST_CASE("Test 2: LZespolona dzielenie przez LZesp z przypisaniem 2")
{
    LZespolona x, y, z;

    x.re = 4;
    x.im = 5;

    y.re = 2;
    y.im = 2;

    x /= y;

    z.re = 2.25;
    z.im = 0.25;

    CHECK(x == z);
}

TEST_CASE("Test 3: LZespolona dzielenie przez skalar z przypisaniem")
{
    LZespolona x, z;
    double y;
    x.re = 7;
    x.im = 9;

    y = 2;

    x /= y;

    z.re = 3.5;
    z.im = 4.5;

    CHECK(x == z);
}

TEST_CASE("Test 4: LZespolona dzielenie przez 0 (LZespolona)")
{
    LZespolona x, y;

    x.re = 4;
    x.im = 5;

    y.re = 0;
    y.im = 0;


    WARN_THROWS(x/=y);
}

TEST_CASE("Test 5: LZespolona dzielenie przez 0 (Skalar)")
{
    LZespolona x;
    double y;

    x.re = 4;
    x.im = 5;

    y=0;


    WARN_THROWS(x/=y);
}



TEST_CASE("Test 6: LZespolona dzielenie przez LZesp z przypisaniem malych liczb")
{
    LZespolona x, y, z;

    x.re = 0.004;
    x.im = 0.005;

    y.re = 0.002;
    y.im = 0.002;

    x /= y;

    z.re = 2.25;
    z.im = 0.25;

    CHECK(x == z);
}


TEST_CASE("Test 7: LZespolona dzielenie przez LZesp z przypisaniem liczby ujemne")
{
    LZespolona x, y, z;

    x.re = -4;
    x.im = -5;

    y.re = -1;
    y.im = -2;

    x /= y;

    z.re = 2.25;
    z.im = 0.25;

    CHECK(x == z);
}


TEST_CASE("Test 8: LZespolona suma LZesp z przypisaniem ")
{
    LZespolona x, y, z;

    x.re = 8;
    x.im = 5;

    y.re = 3;
    y.im = 4;

    x += y;

    z.re = 11;
    z.im = 9;

    CHECK(x == z);
}

TEST_CASE("Test 9: LZespolona suma LZesp male liczby z przypisaniem ")
{
    LZespolona x, y, z;

    x.re = 0.00008;
    x.im = 0.05;

    y.re = 0.0003;
    y.im = 0.004;

    x += y;

    z.re = 0.054;
    z.im = 0.00408;

    CHECK(x == z);
}

TEST_CASE("Test 10: LZespolona suma LZesp liczby ujemne z przypisaniem ")
{
    LZespolona x, y, z;

    x.re = -4;
    x.im = -3;

    y.re = -7;
    y.im = -15;

    x += y;

    z.re = -11;
    z.im = -18;

    CHECK(x == z);
}

TEST_CASE("Test 11: LZespolona suma LZesp liczby o dziwnym zapisie z przypisaniem ")
{
    LZespolona x, y, z;

    x.re = 0.0;
    x.im = 0.0;

    y.re = 0.0;
    y.im = 0.0;

    x += y;

    z.re = 0.0;
    z.im = 0.0;

    CHECK(x == z);
}

TEST_CASE("Test 12: LZespolona suma LZesp zmiana na granicy z przypisaniem ")
{
    LZespolona x, y, z;

    x.re = 0.0001;
    x.im = 0.0001;

    y.re = 0.0009;
    y.im = 0.0009;

    x += y;

    z.re = 0.001;
    z.im = 0.001;

    CHECK(x == z);
}

/*rownosc danych sprawdzam przy pomocy MID_DIFF*/
TEST_CASE("Test 13: LZespolona argument glowny 1")
{
    LZespolona x;

    double a;
    
    x.re = 1;
    x.im = 1;

    a=PI/4;
    

    CHECK(abs(x.arg() - a) <= MIN_DIFF);
}

TEST_CASE("Test 14: LZespolona argument glowny 2")
{
    LZespolona x;

    double a;
    
    x.re = -1;
    x.im = 1;

    a=PI*3/4;
    

    CHECK(abs(x.arg() - a) <= MIN_DIFF);
}

TEST_CASE("Test 15: LZespolona argument glowny duzy iloraz")
{
    LZespolona x;

    double a;
    
    x.re = 1;
    x.im = 2345;

    a=1.57036;
    

    CHECK(abs(x.arg() - a) <= MIN_DIFF);
}

TEST_CASE("Test 16: LZespolona argument glowny maly iloraz")
{
    LZespolona x;

    double a;
    
    x.re = 455;
    x.im = 2;

    a=0.000439;
    

    CHECK(abs(x.arg() - a) <= MIN_DIFF);
}