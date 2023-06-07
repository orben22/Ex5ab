#ifndef MAGICAL_ITERATORS_PARTA_MAGICALCONTAINER_HPP
#define MAGICAL_ITERATORS_PARTA_MAGICALCONTAINER_HPP

#include <vector>
#include <cstddef>

namespace ariel {

    class MagicalContainer {
    private:
        std::vector<int> my_elements;
        std::vector<int *> my_primes;
    public:
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

        bool isExist(int element);

//Iterators Classes

        class AscendingIterator {
            MagicalContainer &container;
            std::vector<int>::iterator it;
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

            AscendingIterator &operator++();

            int operator*();

            AscendingIterator begin();

            AscendingIterator end();
        };

        class SideCrossIterator {
            MagicalContainer &container;
            std::vector<int>::iterator it;

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

            SideCrossIterator &operator++();

            int operator*();

            SideCrossIterator begin();

            SideCrossIterator end();
        };

        class PrimeIterator {

            MagicalContainer &container;
            std::vector<int*>::iterator it;

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

            PrimeIterator &operator++();

            int operator*();

            PrimeIterator begin();

            PrimeIterator end();
        };

    };
}

#endif
