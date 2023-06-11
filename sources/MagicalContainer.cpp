
#include "MagicalContainer.hpp"
#include <cstddef>
#include <stdexcept>
#include "algorithm"

namespace ariel {
    // Function: addElement
    // Adds the specified element to the container
    // If the element is a prime number, we will add a pointer of that element to the my_primes set
    // Parameters: element- the element to be added
    // Returns: void
    void MagicalContainer::addElement(int element) {
        my_elements.insert(element);
        if (isPrime(element)) {
            my_primes.insert(new int(element));
        }
    }
    // Function: removeElement
    // Removes the specified element from the container
    // Parameters: element- the element to be removed
    // Throws: runtime_error if the element is not in the set
    // Returns: void
    void MagicalContainer::removeElement(int element) {
        size_t remove = this->my_elements.erase(element);
        if (remove <= 0) throw std::runtime_error("not in the set");
        if (isPrime(element)) {
            for (auto it = my_primes.begin(); it != my_primes.end();) {
                if (**it == element) {
                    it = my_primes.erase(it);
                } else {
                    ++it;
                }
            }
        }
    }
    // Function: isPrime
    // Checks if the given element is prime
    // Parameters: element- the element to be checked
    // Returns: true if the element is prime, false otherwise
    bool MagicalContainer::isPrime(int element) {
        if (element <= 1) return false;
        if (element == 2) return true;
        if (element % 2 == 0) return false;
        for (int i = 3; i * i <= element; i += 2) {
            if (element % i == 0) {
                return false;
            }
        }
        return true;
    }
    // Function: size
    // Returns the size of the container (number of elements)
    // Returns: the size of the container
    size_t MagicalContainer::size() {
        return this->my_elements.size();
    }
    // Function: getMyElements
    // Returns a constant reference to the elements set
    const std::set<int> &MagicalContainer::getMyElements() const {
        return my_elements;
    }
    // Function: getMyPrimes
    // Returns a constant reference to the prime elements set
    const std::set<int *, Compare> &MagicalContainer::getMyPrimes() const {
        return my_primes;
    }

//AscendingIterator

    // Constructor: AscendingIterator
    // Initializes the AscendingIterator object with a reference to the container and sets the iterator position and counter.
    // Parameters: container- reference to the MagicalContainer object
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container) : container(container),
                                                                                          it(container.my_elements.begin()),
                                                                                          counter(1) {
    }
    // Copy constructor: AscendingIterator
    // Creates a new AscendingIterator object by copying another AscendingIterator object.
    // Parameters: other- the AscendingIterator object to be copied
    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other) : container(
            other.container), it(other.it), counter(other.counter) {
    }
    // Assignment operator: operator=
    // Assigns the values of another AscendingIterator object to the current object.
    // Parameters: other- the AscendingIterator object to be assigned
    // Returns: a reference to the current AscendingIterator object after assignment

    MagicalContainer::AscendingIterator &
    MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other) {
        if (this == &other) return *this;
        if (this->container.my_elements != other.container.my_elements)
            throw std::runtime_error("can't compare when its not the same container");
        this->it = other.it;
        return *this;
    }
    // Equality comparison operator: operator==
    // Compares the current AscendingIterator object with another AscendingIterator object for equality.
    // Parameters: other- the AscendingIterator object to be compared
    // Returns: true if the two iterators are equal, false otherwise
    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const {
        if (this->container.my_elements != other.container.my_elements)
            throw std::runtime_error("can't compare when its not the same container");
        return this->counter == other.counter;
    }
    // Inequality comparison operator: operator!=
    // Compares the current AscendingIterator object with another AscendingIterator object for inequality.
    // Parameters: other- the AscendingIterator object to be compared
    // Returns: true if the two iterators are not equal, false otherwise
    // Realizing the operator == realization
    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const {
        return (!(this->counter == other.counter));
    }
    // Greater than comparison operator: operator>
    // Compares the current AscendingIterator object with another AscendingIterator object.
    // Parameters: other- the AscendingIterator object to be compared
    // Returns: true if the current iterator is greater than the other iterator, false otherwise
    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const {
        if (this->container.my_elements != other.container.my_elements)
            throw std::runtime_error("can't compare when its not the same container");
        return this->counter > other.counter;
    }
    // Less than comparison operator: operator<
    // Compares the current AscendingIterator object with another AscendingIterator object.
    // Parameters: other- the AscendingIterator object to be compared
    // Returns: true if the current iterator is less than the other iterator, false otherwise
    // Realizing the operator > realization
    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const {
        return other.counter > this->counter;
    }
    // Prefix increment operator: operator++
    // Increments the iterator to point to the next element in the container.
    // Throws: runtime_error if the iterator is already at the end of the container
    // Returns: a reference to the updated AscendingIterator object
    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++() {
        if (it == container.my_elements.end()) throw std::runtime_error("can't promote the iterator");
        it++;
        counter++;
        return *this;
    }
    // Dereference operator: operator*
    // Returns the value pointed to by the iterator.
    // Throws: runtime_error if the iterator is at the end of the container
    // Returns: the value of the current element
    int MagicalContainer::AscendingIterator::operator*() {
        if (it == container.my_elements.end()) throw std::runtime_error("can't return the value of the iterator");
        return *it;
    }
    // Function: begin
    // Returns: an AscendingIterator object pointing to the beginning of the container
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() {
        return AscendingIterator(this->container);
    }
    // Function: end
    // Returns: an AscendingIterator object pointing to the end of the container
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() {
        AscendingIterator endIt(this->container);
        endIt.it = container.my_elements.end();
        endIt.counter = this->container.size() + 1;
        return endIt;
    }
    // Equality comparison operator: operator==
    // Compares the current AscendingIterator object with a SideCrossIterator object for equality.
    // Throws: runtime_error indicating that comparison between different iterators is not supported
    bool MagicalContainer::AscendingIterator::operator==(const MagicalContainer::SideCrossIterator &other) const {
        throw std::runtime_error("cannot compare between different iterators");
    }
    // Inequality comparison operator: operator!=
    // Compares the current AscendingIterator object with a SideCrossIterator object for inequality.
    // Throws: runtime_error indicating that comparison between different iterators is not supported
    bool MagicalContainer::AscendingIterator::operator!=(const MagicalContainer::SideCrossIterator &other) const {
        throw std::runtime_error("cannot compare between different iterators");
    }
    // Greater than comparison operator: operator>
    // Compares the current AscendingIterator object with a SideCrossIterator object.
    // Throws: runtime_error indicating that comparison between different iterators is not supported
    bool MagicalContainer::AscendingIterator::operator>(const MagicalContainer::SideCrossIterator &other) const {
        throw std::runtime_error("cannot compare between different iterators");
    }
    // Less than comparison operator: operator<
    // Compares the current AscendingIterator object with a SideCrossIterator object.
    // Throws: runtime_error indicating that comparison between different iterators is not supported
    bool MagicalContainer::AscendingIterator::operator<(const MagicalContainer::SideCrossIterator &other) const {
        throw std::runtime_error("cannot compare between different iterators");
    }
    // Equality comparison operator: operator==
    // Compares the current AscendingIterator object with a PrimeIterator object for equality.
    // Throws: runtime_error indicating that comparison between different iterators is not supported
    bool MagicalContainer::AscendingIterator::operator==(const MagicalContainer::PrimeIterator &other) const {
        throw std::runtime_error("cannot compare between different iterators");
    }
    // Inequality comparison operator: operator!=
    // Compares the current AscendingIterator object with a PrimeIterator object for inequality.
    // Throws: runtime_error indicating that comparison between different iterators is not supported
    bool MagicalContainer::AscendingIterator::operator!=(const MagicalContainer::PrimeIterator &other) const {
        throw std::runtime_error("cannot compare between different iterators");
    }
    // Greater than comparison operator: operator>
    // Compares the current AscendingIterator object with a PrimeIterator object.
    // Throws: runtime_error indicating that comparison between different iterators is not supported
    bool MagicalContainer::AscendingIterator::operator>(const MagicalContainer::PrimeIterator &other) const {
        throw std::runtime_error("cannot compare between different iterators");
    }
    // Less than comparison operator: operator<
    // Compares the current AscendingIterator object with a PrimeIterator object.
    // Throws: runtime_error indicating that comparison between different iterators is not supported
    bool MagicalContainer::AscendingIterator::operator<(const MagicalContainer::PrimeIterator &other) const {
        throw std::runtime_error("cannot compare between different iterators");
    }

// SideCrossIterator

    // Constructor
    // Initializes a SideCrossIterator object with the given container.
    // Sets the initial positions of the front and end iterators based on the container's elements.
    // The boolean variable: flag=true means we need to increment the it_front
    // Flag=false means we need to increment thee it_end.
    // If the container is not empty, the end iterator is set to the last element.
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container) : container(container),
                                                                                          it_front(
                                                                                                  container.my_elements.begin()),
                                                                                          it_end(container.my_elements.end()),
                                                                                          flag(true), counter(1) {
        if (!container.my_elements.empty()) it_end=--this->container.my_elements.end();
    }
    // Copy constructor
    // Initializes a SideCrossIterator object with the same values as the other SideCrossIterator object.
    // Copies the container, iterators, flag, and counter.
    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other) : container(
            other.container), it_front(other.container.my_elements.begin()),
                                                                                             it_end(--other.container.my_elements.end()),
                                                                                             flag(true), counter(other.counter) {
    }

    // Assignment operator: operator=
    // Assigns the values from another SideCrossIterator object to the current SideCrossIterator object.
    // Throws: runtime_error if the containers of the two iterators are not the same
    // Returns: a reference to the updated SideCrossIterator object
    MagicalContainer::SideCrossIterator &
    MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other) {
        if (this == &other) return *this;
        if (this->container.my_elements != other.container.my_elements)
            throw std::runtime_error("can't compare when its not the same container");
        this->it_front = other.it_front;
        this->it_end = other.it_end;
        return *this;
    }

    // Equality comparison operator: operator==
    // Compares the current SideCrossIterator object with another SideCrossIterator object for equality.
    // Throws: runtime_error if the containers of the two iterators are not the same
    // Returns: true if the iterators are equal, false otherwise

    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const {
        if (this->container.my_elements != other.container.my_elements)
            throw std::runtime_error("can't compare when its not the same container");
        return this->counter == other.counter;
    }

    // Inequality comparison operator: operator!=
    // Compares the current SideCrossIterator object with another SideCrossIterator object for inequality.
    // Returns: true if the iterators are not equal, false otherwise
    // Realizing the operator == realization
    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const {
        return !(this->counter == other.counter);
    }

    // Greater than comparison operator: operator>
    // Compares the current SideCrossIterator object with another SideCrossIterator object.
    // Throws: runtime_error if the containers of the two iterators are not the same
    // Returns: true if the current iterator is greater than the other iterator, false otherwise
    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const {
        if (this->container.my_elements != other.container.my_elements)
            throw std::runtime_error("can't compare when its not the same container");
        return this->counter > other.counter;
    }

    // Less than comparison operator: operator<
    // Compares the current SideCrossIterator object with another SideCrossIterator object.
    // Returns: true if the current iterator is less than the other iterator, false otherwise
    // Realizing the operator > realization
    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const {
        return other.counter > this->counter;
    }

    // Pre-increment operator: operator++
    // Advances the iterator to the next position.
    // Throws: runtime_error if the iterator is already at or past the end
    // Returns: a reference to the updated SideCrossIterator object
    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++() {
        if (counter >= this->container.size() + 1) {
            throw std::runtime_error("can't promote this iterator");
        }
        if (flag) {
            it_front++;
        } else {
            it_end--;
        }
        flag = !flag;
        counter++;
        return *this;
    }

    // Dereference operator: operator*
    // Returns the value pointed to by the iterator.
    // Throws: runtime_error if the iterator is out of bounds
    // Returns: the value of the current element
    int MagicalContainer::SideCrossIterator::operator*() {
        if (counter > this->container.size() + 1) throw std::runtime_error("out of bounds");
        if (flag) return *it_front;
        return *it_end;
    }

    // Begin function
    // Returns a SideCrossIterator object pointing to the beginning of the container.
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() {
        return SideCrossIterator(this->container);
    }

    // End function
    // Returns a SideCrossIterator object pointing to the end of the container.
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() {
        SideCrossIterator endIt(this->container);
        endIt.it_front = this->container.my_elements.end();
        endIt.it_end = this->container.my_elements.end();
        endIt.counter = this->container.size() + 1;
        return endIt;
    }

    // Equality comparison operator: operator== with AscendingIterator
    // Throws: runtime_error indicating that comparison between different iterators is not allowed
    bool MagicalContainer::SideCrossIterator::operator==(const MagicalContainer::AscendingIterator &other) const {
        throw std::runtime_error("cannot compare between different iterators");
    }

    // Inequality comparison operator: operator!= with AscendingIterator
    // Throws: std::runtime_error indicating that comparison between different iterators is not allowed
    bool MagicalContainer::SideCrossIterator::operator!=(const MagicalContainer::AscendingIterator &other) const {
        throw std::runtime_error("cannot compare between different iterators");
    }

    // Greater than comparison operator: operator> with AscendingIterator
    // Throws: std::runtime_error indicating that comparison between different iterators is not allowed
    bool MagicalContainer::SideCrossIterator::operator>(const MagicalContainer::AscendingIterator &other) const {
        throw std::runtime_error("cannot compare between different iterators");
    }
    // Less than comparison operator: operator< with AscendingIterator
    // Throws: std::runtime_error indicating that comparison between different iterators is not allowed
    bool MagicalContainer::SideCrossIterator::operator<(const MagicalContainer::AscendingIterator &other) const {
        throw std::runtime_error("cannot compare between different iterators");
    }
    // Equality comparison operator: operator== with PrimeIterator
    // Throws: runtime_error indicating that comparison between different iterators is not allowed
    bool MagicalContainer::SideCrossIterator::operator==(const MagicalContainer::PrimeIterator &other) const {
        throw std::runtime_error("cannot compare between different iterators");
    }
    // Inequality comparison operator: operator!= with PrimeIterator
    // Throws: runtime_error indicating that comparison between different iterators is not allowed
    bool MagicalContainer::SideCrossIterator::operator!=(const MagicalContainer::PrimeIterator &other) const {
        throw std::runtime_error("cannot compare between different iterators");
    }
    // Greater than comparison operator: operator> with PrimeIterator
    // Throws: runtime_error indicating that comparison between different iterators is not allowed
    bool MagicalContainer::SideCrossIterator::operator>(const MagicalContainer::PrimeIterator &other) const {
        throw std::runtime_error("cannot compare between different iterators");
    }
    // Less than comparison operator: operator< with PrimeIterator
    // Throws: std::runtime_error indicating that comparison between different iterators is not allowed
    bool MagicalContainer::SideCrossIterator::operator<(const MagicalContainer::PrimeIterator &other) const {
        throw std::runtime_error("cannot compare between different iterators");
    }


// PrimeIterator
    // Constructor
    // Initializes a PrimeIterator object with the given container.
    // If the container is empty, sets the iterator to the end.
    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container) : container(container),
                                                                                  it(container.my_primes.begin()),counter(1)
                                                                                  {
        if (this->container.my_primes.empty()) it=this->container.my_primes.end();

                                                                                  }
    // Copy constructor
    // Initializes a PrimeIterator object with the same values as another PrimeIterator object.
    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other) : container(other.container),
                                                                                 it(other.it), counter(other.counter) {}

    // Assignment operator: operator=
    // Assigns the values from another PrimeIterator object to the current object.
    // Throws: runtime_error if the containers of the two iterators are not the same
    // Returns: a reference to the updated PrimeIterator object
    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other) {
        if (this == &other) return *this;
        if (this->container.my_primes != other.container.my_primes)
            throw std::runtime_error("can't compare when its not the same container");
        this->it = other.it;
        return *this;
    }
    // Equality comparison operator: operator==
    // Compares the current PrimeIterator object with another PrimeIterator object.
    // Throws: runtime_error if the containers of the two iterators are not the same
    // Returns: true if the iterators are equal, false otherwise
    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const {
        if (this->container.my_primes != other.container.my_primes)
            throw std::runtime_error("can't compare when its not the same container");
        return this->counter == other.counter;
    }
    // Inequality comparison operator: operator!=
    // Compares the current PrimeIterator object with another PrimeIterator object.
    // Returns: true if the iterators are not equal, false otherwise
    // Realizing the operator == realization
    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const {
        return !(this->counter == other.counter);
    }
    // Greater than comparison operator: operator>
    // Compares the current PrimeIterator object with another PrimeIterator object.
    // Throws: runtime_error if the containers of the two iterators are not the same
    // Returns: true if the current iterator is greater than the other iterator, false otherwise
    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const {
        if (this->container.my_primes != other.container.my_primes)
            throw std::runtime_error("can't compare when its not the same container");
        return this->counter > other.counter;
    }
    // Less than comparison operator: operator<
    // Compares the current PrimeIterator object with another PrimeIterator object.
    // Returns: true if the other iterator is greater than the current iterator, false otherwise
    // Realizing the operator > realization
    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const {
        return other.counter > this->counter;
    }
    // Pre-increment operator: operator++
    // Advances the iterator to the next position.
    // Throws: runtime_error if the iterator is already at the end
    // Returns: a reference to the updated PrimeIterator object
    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++() {
        if (it == this->container.my_primes.end()) throw std::runtime_error("can't promote the iterator");
        it++;
        counter++;
        return *this;
    }
    // Dereference operator: operator*
    // Returns the value pointed to by the iterator.
    // Throws: runtime_error if the iterator is at the end
    // Returns: the value of the iterator
    int MagicalContainer::PrimeIterator::operator*() {
        if (it == container.my_primes.end()) throw std::runtime_error("can't return the value of the iterator");
        return **it;
    }
    // Begin function
    // Returns a PrimeIterator object that points to the beginning of the container.
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() {
        return PrimeIterator(this->container);
    }
    // End function
    // Returns a PrimeIterator object that points to the end of the container.
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() {
        PrimeIterator endIt(this->container);
        endIt.it = container.my_primes.end();
        endIt.counter = this->container.my_primes.size() + 1;
        return endIt;
    }
    // Equality comparison operator: operator== with AscendingIterator
    // Throws: runtime_error indicating that comparison between different iterators is not allowed
    bool MagicalContainer::PrimeIterator::operator==(const MagicalContainer::AscendingIterator &other) const {
        throw std::runtime_error("cannot compare between different iterators");
    }
    // Inequality comparison operator: operator!= with AscendingIterator
    // Throws: std::runtime_error indicating that comparison between different iterators is not allowed
    bool MagicalContainer::PrimeIterator::operator!=(const MagicalContainer::AscendingIterator &other) const {
        throw std::runtime_error("cannot compare between different iterators");
    }
    // Greater than comparison operator: operator> with AscendingIterator
    // Compares the current PrimeIterator object with an AscendingIterator object.
    // Throws: std::runtime_error indicating that comparison between different iterators is not allowed
    bool MagicalContainer::PrimeIterator::operator>(const MagicalContainer::AscendingIterator &other) const {
        throw std::runtime_error("cannot compare between different iterators");
    }
    // Less than comparison operator: operator< with AscendingIterator
    // Throws: std::runtime_error indicating that comparison between different iterators is not allowed
    bool MagicalContainer::PrimeIterator::operator<(const MagicalContainer::AscendingIterator &other) const {
        throw std::runtime_error("cannot compare between different iterators");
    }
    // Equality comparison operator: operator== with SideCrossIterator
    // Throws: runtime_error indicating that comparison between different iterators is not allowed
    bool MagicalContainer::PrimeIterator::operator==(const MagicalContainer::SideCrossIterator &other) const {
        throw std::runtime_error("cannot compare between different iterators");
    }
    // Inequality comparison operator: operator!= with SideCrossIterator
    // Throws: std::runtime_error indicating that comparison between different iterators is not allowed
    bool MagicalContainer::PrimeIterator::operator!=(const MagicalContainer::SideCrossIterator &other) const {
        throw std::runtime_error("cannot compare between different iterators");
    }
    // Greater than comparison operator: operator> with SideCrossIterator
    // Throws: std::runtime_error indicating that comparison between different iterators is not allowed
    bool MagicalContainer::PrimeIterator::operator>(const MagicalContainer::SideCrossIterator &other) const {
        throw std::runtime_error("cannot compare between different iterators");
    }
    // Less than comparison operator: operator< with SideCrossIterator
    // Throws: std::runtime_error indicating that comparison between different iterators is not allowed
    bool MagicalContainer::PrimeIterator::operator<(const MagicalContainer::SideCrossIterator &other) const {
        throw std::runtime_error("cannot compare between different iterators");
    }


}