
#include "MagicalContainer.hpp"
#include <cstddef>
#include <stdexcept>
#include "algorithm"

namespace ariel {
    void MagicalContainer::addElement(int element) {
        if (std::find(my_elements.begin(),my_elements.end(),element)!=my_elements.end()) return;
        for (size_t i = 0, j = 1; i < this->size() - 1 && j < this->size(); i++, j++) {
            int pre, next;
            pre = this->my_elements.at(i);
            next = this->my_elements.at(j);
            if (element > pre && element < next) {

            }
        }
    }

    void MagicalContainer::removeElement(int element) {
        if (std::find(my_elements.begin(),my_elements.end(),element)==my_elements.end()) return;
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

//AscendingIterator
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container) : container(container),
                                                                                          it(container.my_elements.begin()),counter(1) {
    }


    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other) : container(
            other.container), it(other.it),counter(1) {
    }

    MagicalContainer::AscendingIterator &
    MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other) {
        if (this==&other) return *this;
        if (this->container.my_elements != other.container.my_elements) throw std::runtime_error("can't compare when its not the same container");
        this->it=other.it;
        return *this;
    }

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const {
        if (this->container.my_elements!=other.container.my_elements) throw std::runtime_error("can't compare when its not the same container");
        return this->counter==other.counter;
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const {
        return (!(this->counter==other.counter));
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const {
        if (this->container.my_elements!=other.container.my_elements) throw std::runtime_error("can't compare when its not the same container");
        return this->counter>other.counter;
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const {
        return other.counter>this->counter;
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++() {
        if (it == container.my_elements.end()) throw std::runtime_error("can't promote the iterator");
        it++;
        counter++;
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
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container) : container(container), it_front(container.my_elements.begin()), it_end(--container.my_elements.end()), flag(true),counter(1) {
    }

    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other) : container(
            other.container), it_front(other.container.my_elements.begin()), it_end(--other.container.my_elements.end()), flag(true), counter(1) {
    }


    MagicalContainer::SideCrossIterator &
    MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other) {
        if (this==&other) return *this;
        if (this->container.my_elements != other.container.my_elements) throw std::runtime_error("can't compare when its not the same container");
        this->it_front=other.it_front;
        this->it_end=other.it_end;
        return *this;
    }


    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const {
        if (this->container.my_elements!=other.container.my_elements) throw std::runtime_error("can't compare when its not the same container");
        return this->counter==other.counter;
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const {
        return !(this->counter==other.counter);
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const {
        if (this->container.my_elements!=other.container.my_elements) throw std::runtime_error("can't compare when its not the same container");
        return this->counter>other.counter;
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const {
        return other.counter>this->counter;
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++() {
        if (counter>this->container.size()) throw std::runtime_error("can't promote this iterator");
        if (counter==this->container.size()){
            it_front=this->container.my_elements.end();
            it_end=this->container.my_elements.end();
            return *this;
        }
        if (flag) {
            it_front++;
        }else {
            it_end--;
        }
        flag=!flag;
        counter++;
        return *this;
    }

    int MagicalContainer::SideCrossIterator::operator*() {
        if (counter>this->container.size()) throw std::runtime_error("out of bounds");
        if (flag) return *it_front;
        return *it_end;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() {
        return SideCrossIterator(this->container);
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() {
        SideCrossIterator endIt(this->container);
        endIt.it_front=this->container.my_elements.end();
        endIt.it_end = this->container.my_elements.end();
        endIt.counter=this->container.size();
        return endIt;
    }

// PrimeIterator
    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container) : container(container),
                                                                                  it(container.my_primes.begin()),counter(1) {
    }

    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other): container(other.container),it(other.it),counter(1){}

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other) {
        if (this==&other) return *this;
        if (this->container.my_primes != other.container.my_primes) throw std::runtime_error("can't compare when its not the same container");
        this->it=other.it;
        return *this;
    }

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const {
        if (this->container.my_primes!=other.container.my_primes) throw std::runtime_error("can't compare when its not the same container");
        return this->counter==other.counter;
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const {
        return !(this->counter==other.counter);
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const {
        if (this->container.my_primes!=other.container.my_primes) throw std::runtime_error("can't compare when its not the same container");
        return this->counter>other.counter;
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const {
        return other.counter>this->counter;
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++() {
        if (it == this->container.my_primes.end()) throw std::runtime_error("can't promote the iterator");
        it++;
        counter++;
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