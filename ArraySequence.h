#pragma once

#include <stdexcept>
#include "Sequence.h"
#include "Unique_ptr.h"

template<typename T>
class ArraySequence : public Sequence<T> {
private:
    unique_ptr<T[]> array; 
    int size;

public:
    ArraySequence(int size) : size(size), array(new T[size]) {
        if (size < 0) {
            throw std::out_of_range("Invalid size");
        }
    }

    T& get(int index) override {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return array[index];
    }

    const T& get(int index) const override {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return array[index];
    }

    int getSize() const override {
        return size;
    }

    ArraySequence<T> concat(const ArraySequence<T>& other) const {
        int newSize = size + other.size;
        ArraySequence<T> result(newSize);

        for (int i = 0; i < size; ++i) {
            result.get(i) = array[i];
        }
        for (int i = 0; i < other.size; ++i) {
            result.get(size + i) = other.get(i);
        }

        return result;
    }
};
