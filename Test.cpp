#include "doctest.h"
#include "sources/MagicalContainer.hpp"

TEST_CASE("initialization of Magical Container") {
    ariel::MagicalContainer myContainer;
    CHECK_EQ(myContainer.size(), 0);
    ariel::MagicalContainer::AscendingIterator ascendindIt(myContainer);
    ariel::MagicalContainer::PrimeIterator primeIt(myContainer);
    ariel::MagicalContainer::SideCrossIterator sidecrossIt(myContainer);
    CHECK(ascendindIt.begin() == ascendindIt.end());
    CHECK(primeIt.begin() == primeIt.end());
    CHECK(sidecrossIt.begin() == sidecrossIt.end());
    CHECK_FALSE(ascendindIt.begin() != ascendindIt.end());
    CHECK_FALSE(primeIt.begin() != primeIt.end());
    CHECK_FALSE(sidecrossIt.begin() != sidecrossIt.end());
}
TEST_CASE("adding and removing elements in Magical Container") {
    ariel::MagicalContainer myContainer;
    myContainer.addElement(5);
    myContainer.addElement(6);
    CHECK_EQ(myContainer.size(),2);
    myContainer.addElement(5);//adding an element that already exist
    CHECK_EQ(myContainer.size(),2);
    ariel::MagicalContainer::AscendingIterator it(myContainer);
    CHECK_EQ(*it.begin(),5);
    CHECK_FALSE(*it.begin()!=5);
    CHECK_EQ(*(++it),6);
    CHECK_FALSE(*(it)!=6);
    CHECK_EQ(++it,it.end());
    CHECK_THROWS(myContainer.removeElement(7));//remove element that doesnt exist
    CHECK_EQ(myContainer.size(),2);
    myContainer.removeElement(5);
    CHECK_NE(myContainer.size(),2);
    CHECK_EQ(myContainer.size(),1);
    CHECK_NE(*it.begin(),5);
    CHECK_EQ(*it.begin(),6);
    CHECK_THROWS(++it);
}
TEST_CASE("Ascending iterator check"){
    ariel::MagicalContainer myContainer;
    myContainer.addElement(5);
    myContainer.addElement(3);
    myContainer.addElement(4);
    myContainer.addElement(1);
    ariel::MagicalContainer::AscendingIterator it(myContainer);
    CHECK_EQ(*it.begin(),1);
    CHECK_EQ(*(++it),3);
    CHECK_EQ(*(++it),4);
    CHECK_EQ(*(++it),5);
    CHECK_EQ(++it,it.end());
    CHECK_THROWS(++it);
}
TEST_CASE("side-cross iterator check"){
    ariel::MagicalContainer myContainer;
    myContainer.addElement(5);
    myContainer.addElement(3);
    myContainer.addElement(4);
    myContainer.addElement(1);
    ariel::MagicalContainer::SideCrossIterator it(myContainer);
    CHECK_EQ(*it.begin(),1);
    CHECK_EQ(*(++it),5);
    CHECK_EQ(*(++it),3);
    CHECK_EQ(*(++it),4);
    CHECK_EQ(*(++it),*it.end());
    CHECK_THROWS(++it);
}
TEST_CASE("prime iterator check"){
    ariel::MagicalContainer myContainer;
    myContainer.addElement(5);
    myContainer.addElement(6);
    myContainer.addElement(7);
    myContainer.addElement(9);
    ariel::MagicalContainer::PrimeIterator it(myContainer);
    CHECK_EQ(*it.begin(),5);
    CHECK_EQ(*(++it),7);
    CHECK_EQ(++it,it.end());
    CHECK_THROWS(++it);
}

TEST_CASE("Comparing iterators from the same container") {
    ariel::MagicalContainer container;
    for (int i = 1; i <= 10; ++i) {
        container.addElement(i * 2);
    }

    SUBCASE("Comparing AscendingIterator with itself") {
        ariel::MagicalContainer::AscendingIterator it1(container);
        ariel::MagicalContainer::AscendingIterator it2(container);
        CHECK(it1 == it2);
        CHECK_FALSE(it1 != it2);
        CHECK_FALSE(it1 < it2);
        CHECK_FALSE(it1 > it2);
    }

    SUBCASE("Comparing SideCrossIterator with itself") {
        ariel::MagicalContainer::SideCrossIterator it1(container);
        ariel::MagicalContainer::SideCrossIterator it2(container);
        CHECK(it1 == it2);
        CHECK_FALSE(it1 != it2);
        CHECK_FALSE(it1 < it2);
        CHECK_FALSE(it1 > it2);
    }

    SUBCASE("Comparing PrimeIterator with itself") {
        ariel::MagicalContainer::PrimeIterator it1(container);
        ariel::MagicalContainer::PrimeIterator it2(container);
        CHECK(it1 == it2);
        CHECK_FALSE(it1 != it2);
        CHECK_FALSE(it1 < it2);
        CHECK_FALSE(it1 > it2);
    }
}
TEST_CASE("container without prime numbers") {
    ariel::MagicalContainer myContainer;
    ariel::MagicalContainer::PrimeIterator primeIt(myContainer);
    myContainer.addElement(8);
    myContainer.addElement(6);
    myContainer.addElement(12);
    myContainer.addElement(20);
    CHECK_EQ(primeIt,primeIt.end());
    CHECK_THROWS(++primeIt);
}
TEST_CASE("check delete and then increment") {
    ariel::MagicalContainer container;
    container.addElement(2);
    container.addElement(3);
    container.addElement(5);
    ariel::MagicalContainer::PrimeIterator itPrime(container);
    ariel::MagicalContainer::AscendingIterator itAsc(container);
    ariel::MagicalContainer::SideCrossIterator itCross(container);
    container.removeElement(3);
    ++itAsc;
    ++itPrime;
    ++itCross;
    CHECK_EQ(*itPrime, 5);
    CHECK_EQ(*itAsc, 5);
    CHECK_EQ(*itCross, 5);
}

TEST_CASE("Different Container") {
    ariel::MagicalContainer container1;
    container1.addElement(5);
    ariel::MagicalContainer container2;
    container2.addElement(6);
    ariel::MagicalContainer::AscendingIterator ascIt(container1);
    ariel::MagicalContainer::PrimeIterator primeIt(container1);
    ariel::MagicalContainer::SideCrossIterator sideIt(container1);
    ariel::MagicalContainer::AscendingIterator ascIt2(container2);
    ariel::MagicalContainer::PrimeIterator primeIt2(container2);
    ariel::MagicalContainer::SideCrossIterator sideIt2(container2);

    CHECK_THROWS((void) (ascIt > ascIt2));
    CHECK_THROWS((void) (ascIt == ascIt2));
    CHECK_THROWS((void) (ascIt < ascIt2));
    CHECK_THROWS((void) (ascIt != ascIt2));

    CHECK_THROWS((void) (primeIt > primeIt2));
    CHECK_THROWS((void) (primeIt == primeIt2));
    CHECK_THROWS((void) (primeIt < primeIt2));
    CHECK_THROWS((void) (primeIt != primeIt2));

    CHECK_THROWS((void) (sideIt > sideIt2));
    CHECK_THROWS((void) (sideIt == sideIt2));
    CHECK_THROWS((void) (sideIt < sideIt2));
    CHECK_THROWS((void) (sideIt != sideIt2));
}

TEST_CASE("Different Iterators") {
    ariel::MagicalContainer container1;
    ariel::MagicalContainer container2;
    ariel::MagicalContainer::AscendingIterator ascIt(container1);
    ariel::MagicalContainer::PrimeIterator primeIt(container1);
    ariel::MagicalContainer::SideCrossIterator sideIt(container1);

    CHECK_THROWS((void) (ascIt > primeIt));
    CHECK_THROWS((void) (ascIt == primeIt));
    CHECK_THROWS((void) (ascIt < primeIt));
    CHECK_THROWS((void) (ascIt != primeIt));

    CHECK_THROWS((void) (ascIt > sideIt));
    CHECK_THROWS((void) (ascIt == sideIt));
    CHECK_THROWS((void) (ascIt < sideIt));
    CHECK_THROWS((void) (ascIt != sideIt));

    CHECK_THROWS((void) (primeIt > ascIt));
    CHECK_THROWS((void) (primeIt == ascIt));
    CHECK_THROWS((void) (primeIt < ascIt));
    CHECK_THROWS((void) (primeIt != ascIt));

    CHECK_THROWS((void) (primeIt > sideIt));
    CHECK_THROWS((void) (primeIt == sideIt));
    CHECK_THROWS((void) (primeIt < sideIt));
    CHECK_THROWS((void) (primeIt != sideIt));


    CHECK_THROWS((void) (sideIt > ascIt));
    CHECK_THROWS((void) (sideIt == ascIt));
    CHECK_THROWS((void) (sideIt < ascIt));
    CHECK_THROWS((void) (sideIt != ascIt));

    CHECK_THROWS((void) (sideIt > primeIt));
    CHECK_THROWS((void) (sideIt == primeIt));
    CHECK_THROWS((void) (sideIt < primeIt));
    CHECK_THROWS((void) (sideIt != primeIt));
}