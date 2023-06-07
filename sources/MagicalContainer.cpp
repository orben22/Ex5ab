
#include "MagicalContainer.hpp"
#include <cstddef>
#include <stdexcept>
#include "algorithm"

namespace ariel {
    void MagicalContainer::addElement(int element) {
        if (isExist(element)) return;
        for (size_t i = 0, j = 1; i < this->size() - 1 && j < this->size(); i++, j++) {
            int pre, next;
            pre = this->my_elements.at(i);
            next = this->my_elements.at(j);
            if (element > pre && element < next) {

            }
        }
    }

    void MagicalContainer::removeElement(int element) {
        if (!isExist(element)) return;
        std::remove(this->my_elements.begin(), this->my_elements.end(), element);
    }

    bool MagicalContainer::isPrime(int element) {
        if (element <= 1) {
            return false;
        }
        for (int i = 2; i < element / 2; i++) {
            if (element % i == 0) {
                return false;
            }
        }
        return true;
    }

    size_t MagicalContainer::size() {
        return this->my_elements.size();
    }

    bool MagicalContainer::isExist(int element) {
        for (size_t i = 0; i < this->size(); i++) {
            if (element == this->my_elements.at(i)) return true;
        }
        return false;
    }
//AscendingIterator
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container) : container(container),
                                                                                          it(container.my_elements.begin()) {
    }


    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other) : container(
            other.container), it(other.it) {
    }

    MagicalContainer::AscendingIterator &
    MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other) {
        return *this;
    }

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const {
        return (*it == *other.it);
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const {
        return (!(*it == *other.it));
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const {
        return *it > *other.it;
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const {
        return !(*it > *other.it) && !(*it == *other.it);
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++() {
        if (it == container.my_elements.end()) throw std::runtime_error("can't promote the iterator");
        it++;
        return *this;
    }

    int MagicalContainer::AscendingIterator::operator*() {
        if (it == container.my_elements.end()) throw std::runtime_error("can't return the value of the iterator");
        return *it;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() {
        return AscendingIterator(this->container);
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() {
        AscendingIterator endIt(this->container);
        endIt.it = container.my_elements.end();
        return endIt;
    }

// SideCrossIterator
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container) : container(container) {

    }

    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other) : container(
            other.container) {

    }


    MagicalContainer::SideCrossIterator &
    MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other) {
        return *this;
    }


    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const {
        return false;
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const {
        return false;
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const {
        return false;
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const {
        return false;
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++() {
        return *this;
    }

    int MagicalContainer::SideCrossIterator::operator*() {
        return 0;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() {
        return SideCrossIterator(this->container);
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() {
        SideCrossIterator endIt(this->container);
        endIt.it = container.my_elements.end();
        return endIt;
    }

// PrimeIterator
    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container) : container(container),it(container.my_primes.begin()) {
    }

    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other) = default;

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other) {
        return *this;
    }

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const {
        return (*it == *other.it);
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const {
        return !(*it == *other.it);
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const {
        if (this->container.my_primes!=other.container.my_primes) throw std::runtime_error("can't compare on different containers");
        return *it > *other.it;
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const {
        return *other.it>*it;
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++() {
        if (it==this->container.my_primes.end()) throw std::runtime_error("can't promote the iterator");
        it++;
        return *this;
    }

    int MagicalContainer::PrimeIterator::operator*() {
        if (it == container.my_primes.end()) throw std::runtime_error("can't return the value of the iterator");
        return **it;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() {
        return PrimeIterator(this->container);
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() {
        PrimeIterator endIt(this->container);
        endIt.it = container.my_primes.end();
        return endIt;
    }

}