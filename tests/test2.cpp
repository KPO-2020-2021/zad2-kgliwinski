#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("Test LZespolona dzielenie przez skalar 1") {
    LZespolona x, y;
    double t = 2;
    
    x.re = 2;
    x.im = 2;

    y.re = 1;
    y.im = 1;
   
    CHECK(x/t == y);
}

TEST_CASE("Test LZespolona dzielenie przez skalar 2") {
    LZespolona x, y;
    double t = 3;
    
    x.re = 2;
    x.im = 2;

    y.re = 0.66666666;          /*modyfikacja testu aby wynik byl poprawny*/
    y.im = 0.66666666;
   
    CHECK(x/t == y);
}

TEST_CASE("Test LZespolona dzielenie przez skalar - zero") {
    LZespolona x;
    double t = 0;
    
    x.re = 2;
    x.im = 2;
 
   WARN_THROWS(x/t);
}

TEST_CASE("Test LZespolona dzielenie przez LZespolona 1") {
    LZespolona x,y,z;
    
    x.re=1;
    x.im=1;

    y.re=2;
    y.im=3;

    z.re=0.3846;
    z.im=-0.07692;
    
    CHECK((x/y) == z);

}

TEST_CASE("Test LZespolona dzielenie przez LZespolona 1") {
    LZespolona x,y,z;
    
    x.re=0;
    x.im=1;

    y.re=0;
    y.im=3;

    z.re=0.3333;
    z.im=0;
    
    CHECK((x/y) == z);
}

TEST_CASE("Test LZespolona dzielenie przez LZespolona - zero") {
    LZespolona x, y;
    
    
    x.re = 2;
    x.im = 2;

    y.re=0;
    y.im=0;
 
   WARN_THROWS(x/y);
}