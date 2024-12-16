#pragma once

#include <stdexcept>
#include "Sequence.h"
#include "DynamicArray.h"


template<typename T>
class ArraySequence : public Sequence<T> {
private:
    DynamicArray<T> array;

public:

    ArraySequence(int size) : array(size) {
        if (size < 0) {
            throw std::out_of_range("Invalid size");
        }
    }

    T& get(int index)  {
        if (index < 0 || index >= array.getSize()) {
            throw std::out_of_range("Index out of range");
        }
        return array[index];
    }

    const T& get(int index) const  {
        if (index < 0 || index >= array.getSize()) {
            throw std::out_of_range("Index out of range");
        }
        return array[index];
    }


    void set(int index, const T& value)  {
        if (index < 0 || index >= array.getSize()) {
            throw std::out_of_range("Index out of range");
        }
        array[index] = value;
    }

    int getSize() const override {
        return array.getSize();
    }

    void resize(int newSize) {
        if (newSize < 0) {
            throw std::out_of_range("Invalid size");
        }
        array.resize(newSize);
    }

    void append(const T& value)  {
        resize(array.getSize() + 1);
        array[array.getSize() - 1] = value;
    }

    void prepend(const T& value)  {
        resize(array.getSize() + 1);
        for (int i = array.getSize() - 1; i > 0; --i) {
            array[i] = array[i - 1];
        }
        array[0] = value;
    }

    void insertAt(int index, const T& value)  {
        if (index < 0 || index > array.getSize()) {
            throw std::out_of_range("Index out of range");
        }
        resize(array.getSize() + 1);
        for (int i = array.getSize() - 1; i > index; --i) {
            array[i] = array[i - 1];
        }
        array[index] = value;
    }

    ~ArraySequence() = default;

    void concat(const ArraySequence<T>& other) {
        int otherSize = other.getSize();
        int currentSize = this->getSize();
        this->resize(currentSize + otherSize);
        for (int i = 0; i < otherSize; i++) {
            this->set(currentSize + i, other.get(i));
        }
    }

    ArraySequence<T>& operator=(const ArraySequence<T>& other) {
        if (this != &other) { 
            this->resize(other.getSize());
            for (int i = 0; i < other.getSize(); i++) {
                this->set(i, other.get(i));
            }
        }
        return *this;
    }
};
