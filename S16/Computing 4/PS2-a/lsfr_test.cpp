#include <iostream>
#include <string>

#include "lfsr_class.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(fiveBitsTapAtTwo) {

    LFSR l("00111", 2);
    BOOST_REQUIRE(l.step() == 1);
    BOOST_REQUIRE(l.step() == 1);
    BOOST_REQUIRE(l.step() == 0);
    BOOST_REQUIRE(l.step() == 0);
    BOOST_REQUIRE(l.step() == 0);
    BOOST_REQUIRE(l.step() == 1);
    BOOST_REQUIRE(l.step() == 1);
    BOOST_REQUIRE(l.step() == 0);

    LFSR l2("00111", 2);
    BOOST_REQUIRE(l2.generate(8) == 198);
}

BOOST_AUTO_TEST_CASE(threeBitsTapAtOne) { //short string test

    LFSR l("101", 1);
    BOOST_REQUIRE(l.step() == 1);
    BOOST_REQUIRE(l.step() == 1);
    BOOST_REQUIRE(l.step() == 0);
    BOOST_REQUIRE(l.step() == 0);
    BOOST_REQUIRE(l.step() == 1);
    BOOST_REQUIRE(l.step() == 0);
    BOOST_REQUIRE(l.step() == 1);

    LFSR l2("101", 1);
    BOOST_REQUIRE(l2.generate(7) == 101);
}



BOOST_AUTO_TEST_CASE(thirtyBitsTapAtFifteen) { //long string test

    LFSR l("1010010110110110101100110101101", 15);
    BOOST_REQUIRE(l.step() == 1);
    BOOST_REQUIRE(l.step() == 1);
    BOOST_REQUIRE(l.step() == 1);
    BOOST_REQUIRE(l.step() == 1);
    BOOST_REQUIRE(l.step() == 1);
    BOOST_REQUIRE(l.step() == 1);
    BOOST_REQUIRE(l.step() == 0);
    BOOST_REQUIRE(l.step() == 0);
    BOOST_REQUIRE(l.step() == 0);
    BOOST_REQUIRE(l.step() == 0);
    BOOST_REQUIRE(l.step() == 0);
    BOOST_REQUIRE(l.step() == 1);
    BOOST_REQUIRE(l.step() == 1);
    BOOST_REQUIRE(l.step() == 0);
    BOOST_REQUIRE(l.step() == 1);
    BOOST_REQUIRE(l.step() == 1);
    BOOST_REQUIRE(l.step() == 0);
    BOOST_REQUIRE(l.step() == 1);
    BOOST_REQUIRE(l.step() == 0);
    BOOST_REQUIRE(l.step() == 0);

    LFSR l2("1010010110110110101100110101101", 15);
    BOOST_REQUIRE(l2.generate(20) == 1032628);
}
