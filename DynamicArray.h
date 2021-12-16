#pragma once
#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdexcept>
#include <string>
#include <cmath>


template<typename T>
class DynamicArray {
private:
    T *data = nullptr;
    int size = 0;
    int length = 0;
public:
    DynamicArray() : size(0), length(0) {}

    DynamicArray(int size) : size(size) {
        if (size < 0) throw std::length_error(NEGATIVE_SIZE_MESSAGE);
        this->data = new T[size];
        this->length = 0;
    }


    DynamicArray(T *data, int size) : DynamicArray(size) {
        for (int i = 0; i < size; i++)
            this->data[i] = data[i];
        this->length = size;
    }


    DynamicArray(const DynamicArray<T> &array, int size) : DynamicArray(size) {
        if (size > array.size) throw std::out_of_range(INDEX_OUT_OF_RANGE_MESSAGE);

        for (int i = 0; i < size; i++)
            this->data[i] = array.data[i];

        this->length = size;
    }

    DynamicArray(const DynamicArray<T> &array) :
            DynamicArray(array.data, array.size) {}

    virtual ~DynamicArray() {
        delete[] this->data;
        this->size = 0;
        this->length = 0;
    }


    T get(int index) const {
        if (index < 0 || index >= this->length) throw std::out_of_range(INDEX_OUT_OF_RANGE_MESSAGE);

        return this->data[index];
    }


    int getSize() const { return this->size; }

    int getLength() const { return this->length; }

    void set(const T &value, int index) {
        if (index < 0 || index >= this->length) throw std::out_of_range(INDEX_OUT_OF_RANGE_MESSAGE);

        this->data[index] = value;
    }

    void append(T elem) {
        int o_size = this->size;
        int o_length = this->length;

        if (o_length < o_size) {
            this->data[o_length] = elem;
            this->length++;
        } else {
            if (size == 0) {
                this->Resize(5);
            } else {
                this->Resize(o_size + ceil(0.2 * o_size));
            }
            this->data[o_length] = elem;
            this->length++;
        }
    }

    void Resize(int size) {
        if (size < 0) throw std::length_error(NEGATIVE_SIZE_MESSAGE);

        T *newData = new T[size];


        for (int i = 0; i < (this->size > size ? size : this->size); i++)
            newData[i] = data[i];

        int length = (this->length > size ? size : this->length);

        delete[] data;
        this->data = newData;

        this->length = length;
        this->size = size;
    }

    bool operator==(const DynamicArray<T> &arr) const {
        if (this->size != arr.size) return false;

        for (int i = 0; i < this->size; i++)
            if (this->get(i) != arr.get(i)) return false;


        return true;
    }

    DynamicArray<T> &operator=(const DynamicArray &array) {
        delete[] this->data;

        this->size = array.size;
        this->data = new T[this->size];

        for (int i = 0; i < size; i++)
            this->data[i] = array.data[i];

        return *this;
    }

};

#endif // DYNAMIC_ARRAY_H