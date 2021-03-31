#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"


/*test1.cpp poswiecony jest operacjom dodawania i odejmowania liczb zespolonych*/
/*testy 1-5: dodawaniu; testy 6-10: odejmowaniu*/
TEST_CASE("test LZespolona Suma"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = -3;

    z.re = 2;
    z.im = -2;
    
    CHECK(x+y == z);
}

TEST_CASE ("test LZespolona suma wartosci o dziwnym zapisie"){
    LZespolona x, y, z;

    x.re = 0.0;
    x.im = 0.0;

    y.re = 0.0;
    y.im = 0.0;

    z.re = 0.0;
    z.im = 0.0;

    CHECK (x+y == z);
}


TEST_CASE ("test LZespolona Suma bardzo male wartosci (ale mieszczace sie w zakresie double)"){
    LZespolona x, y, z;

    x.re = 0.0000000001;
    x.im = 0.0000000001;

    y.re = 0.0000000001;
    y.im = 0.0000000001;

    z.re = 0.0000000002;
    z.im = 0.0000000002;

    CHECK (x+y == z);
}

TEST_CASE ("test LZespolona Suma malych wartosci"){
    LZespolona x, y, z;

    x.re = 0.00001;
    x.im = 0.00001;

    y.re = 0.00002;
    y.im = 0.00005;

    z.re = 0.00003;
    z.im = 0.00006;

    CHECK (x+y == z);
}


TEST_CASE ("test LZespolona suma : zmiany na granicach"){
    LZespolona x, y, z;

    x.re = 0.00001;
    x.im = 0.00001;

    y.re = 0.00009;
    y.im = 0.00009;

    z.re = 0.0001;
    z.im = 0.0001;

    CHECK (x+y == z);
}

TEST_CASE ("test LZespolona roznica"){
    LZespolona x, y, z;

    x.re = 2;
    x.im = 3;

    y.re = 2;
    y.im = 3;

    z.re = 0;
    z.im = 0;
    
    CHECK(x-y == z);
}

TEST_CASE ("test LZespolona roznica wartosci o dziwnym zapisie"){
    LZespolona x, y, z;

    x.re = 0.00;
    x.im = 0.00;

    y.re = 0.0;
    y.im = 0.0;

    z.re = 0.0;
    z.im = 0.0;

    CHECK (x-y == z);
}


TEST_CASE ("test LZespolona roznica bardzo male wartosci (ale mieszczace sie w zakresie double)"){
    LZespolona x, y, z;

    x.re = 0.0000000001;
    x.im = 0.0000000001;

    y.re = 0.0000000002;
    y.im = 0.0000000002;

    z.re = -0.0000000001;
    z.im = -0.0000000001;

    CHECK (x-y == z);
}

TEST_CASE ("test LZespolona roznica malych wartosci"){
    LZespolona x, y, z;

    x.re = 0.000025;
    x.im = 0.000015;

    y.re = 0.000020;
    y.im = 0.000010;

    z.re = 0.000005;
    z.im = 0.000005;

    CHECK (x-y == z);
}


TEST_CASE ("test LZespolona suma : zmiany na granicach"){
    LZespolona x, y, z;

    x.re = 0.00001;
    x.im = 0.00001;

    y.re = 0.000001;
    y.im = 0.000001;

    z.re = 0.000009;
    z.im = 0.000009;

    CHECK (x-y == z);
}