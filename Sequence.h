#pragma once
#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <stdexcept>


template<typename T>
class Sequence {
public:

    virtual T GetFirst() const = 0;

    virtual T GetLast() const = 0;

    virtual T Get(int index) const = 0;

    virtual int GetSize() const = 0;


    virtual Sequence<T> *GetSubsequence(int start, int end) const = 0; //end excluding

    virtual void Set(const T &item, int index) = 0;

    virtual void Append(const T &item) = 0;

    virtual void Prepend(const T &item) = 0;

    virtual void InsertAt(const T &item, int index) = 0;

    virtual Sequence<T> *Concat(const Sequence<T> &seq) const = 0;

    virtual bool operator==(const Sequence<T> &seq) const {
        if (this->GetSize() != seq.GetSize()) return false;

        for (int i = 0; i < this->GetSize(); i++) {
            if (this->Get(i) != seq.Get(i)) return false;
        }

        return true;
    }

};

#endif // SEQUENCE_H