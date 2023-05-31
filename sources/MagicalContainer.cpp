
#include "MagicalContainer.hpp"
#include <cstddef>

namespace ariel {
    void MagicalContainer::addElement(int element) {

    }

    void MagicalContainer::removeElement(int element) {

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
        return 0;
    }


//AscendingIterator
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container) : container(container) {

    }


    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other) : container(
            other.container) {

    }

    MagicalContainer::AscendingIterator &
    MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other) {
        return *this;
    }

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const {
        return false;
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const {
        return false;
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const {
        return false;
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const {
        return false;
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++() {
        return *this;
    }

    int MagicalContainer::AscendingIterator::operator*() {
        return 0;
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::begin() {
        return *this;
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::end() {
        return *this;
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

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::begin() {
        return *this;
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::end() {
        return *this;
    }

// PrimeIterator
    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container) : container(container) {

    }

    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other) : container(other.container) {

    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other) {
        return *this;
    }

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const {
        return false;
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const {
        return false;
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const {
        return false;
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const {
        return false;
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++() {
        return *this;
    }

    int MagicalContainer::PrimeIterator::operator*() {
        return 0;
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::begin() {
        return *this;
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::end() {
        return *this;
    }

}