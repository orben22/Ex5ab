#ifndef MAGICAL_ITERATORS_PARTA_MAGICALCONTAINER_HPP
#define MAGICAL_ITERATORS_PARTA_MAGICALCONTAINER_HPP

#include <cstddef>
#include <set>

namespace ariel {
    struct Compare {
        bool operator() (const int* a, const int* b) const {
            return *a < *b;
        }
    };

    class MagicalContainer {
    private:
        std::set<int> my_elements;
        std::set<int *, Compare> my_primes;
    public:
        const std::set<int> &getMyElements() const;

        const std::set<int *, Compare> &getMyPrimes() const;

        //constructor
        MagicalContainer() = default;

        //destructor
        ~MagicalContainer() = default;

        //copy constructor
        MagicalContainer(const MagicalContainer &other) = default;

        //move constructor
        MagicalContainer(MagicalContainer &&other) = default;

        //assignment operators
        MagicalContainer &operator=(MagicalContainer &&other) = default;

        MagicalContainer &operator=(const MagicalContainer &other) = default;

        //MagicalContainer Functions
        void addElement(int element);

        void removeElement(int element);

        static bool isPrime(int element);

        size_t size();

        class AscendingIterator;
        class SideCrossIterator;
        class PrimeIterator;

//Iterators Classes

        class AscendingIterator {
            MagicalContainer &container;
            std::set<int>::iterator it;
            size_t counter;
        public:
            explicit AscendingIterator(MagicalContainer &container);

            AscendingIterator(const AscendingIterator &other);

            AscendingIterator(AscendingIterator &&other) = default;

            AscendingIterator &operator=(const AscendingIterator &other);

            ~AscendingIterator() = default;

            bool operator==(const AscendingIterator &other) const;

            bool operator!=(const AscendingIterator &other) const;

            bool operator>(const AscendingIterator &other) const;

            bool operator<(const AscendingIterator &other) const;
            //operators with other iterators
            bool operator==(const SideCrossIterator &other) const;

            bool operator!=(const SideCrossIterator &other) const;

            bool operator>(const SideCrossIterator &other) const;

            bool operator<(const SideCrossIterator &other) const;

            bool operator==(const PrimeIterator &other) const;

            bool operator!=(const PrimeIterator &other) const;

            bool operator>(const PrimeIterator &other) const;

            bool operator<(const PrimeIterator &other) const;

            AscendingIterator &operator++();

            int operator*();

            AscendingIterator begin();

            AscendingIterator end();
        };

        class SideCrossIterator {
            MagicalContainer &container;
            std::set<int>::iterator it_front;
            std::set<int>::iterator it_end;
            bool flag; //true=it_front, false=it_end
            size_t counter;

        public:
            explicit SideCrossIterator(MagicalContainer &container);

            SideCrossIterator(const SideCrossIterator &other);

            SideCrossIterator(SideCrossIterator &&other) = default;

            SideCrossIterator &operator=(const SideCrossIterator &other);

            ~SideCrossIterator() = default;

            bool operator==(const SideCrossIterator &other) const;

            bool operator!=(const SideCrossIterator &other) const;

            bool operator>(const SideCrossIterator &other) const;

            bool operator<(const SideCrossIterator &other) const;
            //operators with other iterators
            bool operator==(const AscendingIterator &other) const;

            bool operator!=(const AscendingIterator &other) const;

            bool operator>(const AscendingIterator &other) const;

            bool operator<(const AscendingIterator &other) const;

            bool operator==(const PrimeIterator &other) const;

            bool operator!=(const PrimeIterator &other) const;

            bool operator>(const PrimeIterator &other) const;

            bool operator<(const PrimeIterator &other) const;

            SideCrossIterator &operator++();

            int operator*();

            SideCrossIterator begin();

            SideCrossIterator end();
        };

        class PrimeIterator {

            MagicalContainer &container;
            std::set<int*>::iterator it;
            size_t counter;

        public:
            explicit PrimeIterator(MagicalContainer &container);

            PrimeIterator(const PrimeIterator &other);

            PrimeIterator(PrimeIterator &&other) = default;

            PrimeIterator &operator=(const PrimeIterator &other);

            ~PrimeIterator() = default;

            bool operator==(const PrimeIterator &other) const;

            bool operator!=(const PrimeIterator &other) const;

            bool operator>(const PrimeIterator &other) const;

            bool operator<(const PrimeIterator &other) const;
            //operators with other iterators
            bool operator==(const AscendingIterator &other) const;

            bool operator!=(const AscendingIterator &other) const;

            bool operator>(const AscendingIterator &other) const;

            bool operator<(const AscendingIterator &other) const;

            bool operator==(const SideCrossIterator &other) const;

            bool operator!=(const SideCrossIterator &other) const;

            bool operator>(const SideCrossIterator &other) const;

            bool operator<(const SideCrossIterator &other) const;

            PrimeIterator &operator++();

            int operator*();

            PrimeIterator begin();

            PrimeIterator end();
        };

    };
}

#endif
