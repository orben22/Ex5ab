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
    CHECK_FALSE(*(++it)!=6);
    CHECK_EQ(++it,it.end());
    myContainer.removeElement(7);//remove element that doesnt exist
    CHECK_EQ(myContainer.size(),2);
    myContainer.removeElement(5);
    CHECK_NE(myContainer.size(),2);
    CHECK_EQ(myContainer.size(),1);
    CHECK_NE(*it.begin(),5);
    CHECK_EQ(*it.begin(),6);
    CHECK_EQ(++it,it.end());
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
    CHECK_EQ(*(++it),*it.end());
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
    CHECK_EQ(*(++it),*it.end());
}