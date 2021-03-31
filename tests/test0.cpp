#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"


/*test0.cpp poswiecony jest operatorowi ==*/
/*wszystkie testy sprawdzaja dzialanie operatora ==*/

TEST_CASE("Test 1: Prosta rownosc") {
    LZespolona x, y;

    
    x.re = 2;
    x.im = 2;

    y.re = 2;          
    y.im = 2;
   
    CHECK(x == y);
}

TEST_CASE("Test 2: Prosta rownosc dla liczb malych (rzedu x*10^-4) z zasiegu MIN_DIFF") {
    LZespolona x, y;

    
    x.re = 0.0002;
    x.im = 0.0003;

    y.re = 0.0002;         
    y.im = 0.0003;
   
    CHECK(x == y);
}


TEST_CASE("Test 3: Prosta rownosc dla liczb malych (rzedu x*10^-8) spoza zasiegu MIN_DIFF") {
    LZespolona x, y;

    
    x.re = 0.000000003;
    x.im = 0.000000004;

    y.re = 0.000000003;          
    y.im = 0.000000004;
   
    CHECK(x == y);
}

TEST_CASE("Test 4: Prosta nierownosc") {
    LZespolona x, y;

    
    x.re = 2;
    x.im = 2;

    y.re = 3;          
    y.im = 3;
   
    CHECK(!(x == y));
}

TEST_CASE("Test 5: Minimalna nierownosc (rzedu x*10^-4) z zasiegu MIN_DIFF") {
    LZespolona x, y;

    
    x.re = 0.0002;
    x.im = 0.0004;

    y.re = 0.0003;          
    y.im = 0.0005;
   
    CHECK((x == y));       /*failure: roznice w liczbach wynosza 0.0001 i sa wystarczajace (MIN_DIFF=0.0001) aby program
                                       uznawał liczby x i y za rowne*/
}

TEST_CASE("Test 6: Minimalna nierownosc (rzedu x*10^-5) mniejsza niz MIN_DIFF") {
    LZespolona x, y;

    
    x.re = 0.00002;
    x.im = 0.00004;

    y.re = 0.00003;          
    y.im = 0.00005;
   
    CHECK((x == y));       /*failure: roznice w liczbach wynosza 0.000 1 i sa wystarczajace (MIN_DIFF=0.0001) aby program
                                       uznawał liczby x i y za rowne*/
}
