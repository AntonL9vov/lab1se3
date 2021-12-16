
#ifndef MEPHI_3_LAB_1_ARRAYSEQUENCE_H
#define MEPHI_3_LAB_1_ARRAYSEQUENCE_H

#endif //MEPHI_3_LAB_1_ARRAYSEQUENCE_H

#include "Sequence.h"

template<typename T>
class ArraySequence : public Sequence<T> {
protected:
    DynamicArray<T> *array;

public:
    ArraySequence() {
        this->array = new DynamicArray<T>();
    }

    ArraySequence(const ArraySequence<T> &seq) {
        this->array = new DynamicArray<T>(*seq.array);
    }

    ArraySequence(DynamicArray<T> *array) {
        this->array = array;
    }

    ArraySequence(const DynamicArray<T> &items, int size) {
        this->array = new DynamicArray<T>(items, size);
    }

    ArraySequence(T *items, int size) {
        this->array = new DynamicArray<T>(items, size);
    }

    ArraySequence(int size) {
        this->array = new DynamicArray<T>(size);
    }

    ~ArraySequence() {
        delete this->array;
    }

    virtual T GetFirst() const override {
        return this->array->get(0);
    }

    virtual T GetLast() const override {
        return this->array->get(this->GetSize() - 1);
    }

    virtual T Get(int index) const override {
        return this->array->get(index);
    }

    virtual int GetSize() const override {
        return this->array->getLength();
    }

    virtual void Set(const T &item, int index) override {
        if (index < 0 || index >= this->GetSize()) throw std::out_of_range(INDEX_OUT_OF_RANGE_MESSAGE);

        this->array->set(item, index);
    }

    virtual ArraySequence<T> *GetSubsequence(int start, int end) const override {
        if (start < 0 || start >= this->GetSize()) throw std::out_of_range(INDEX_OUT_OF_RANGE_MESSAGE);
        if (end < 0 || end >= this->GetSize()) throw std::out_of_range(INDEX_OUT_OF_RANGE_MESSAGE);
        if (start > end) throw std::logic_error("Quack! End must be not less than start.");


        DynamicArray<T> *subArray = new DynamicArray<T>(end - start + 1);
        for (int i = 0; i < end - start + 1; i++)
            subArray->set(this->array->get(i + start), i);

        ArraySequence<T> *subSequence = new ArraySequence<T>(*(subArray), end - start);

        return subSequence;
    }

    virtual void Append(const T &item) override {
        return this->array->append(item);
    }

    virtual void Prepend(const T &item) override {
        this->array->Resize(this->GetSize() + 1);
        T t1 = this->array->get(0);
        T t2;
        for (int i = 0; i < this->GetSize() - 1; i++) {
            t2 = t1;
            t1 = this->array->get(i + 1);
            this->array->set(t2, i + 1);
        }
        this->array->set(item, 0);
    }

    virtual void InsertAt(const T &item, int index) override {
        if (index < 0 || index > this->GetSize()) throw std::out_of_range(INDEX_OUT_OF_RANGE_MESSAGE);

        if (this->array->getLength() + 1 > this->array->getSize()) {
            this->array->Resize(this->array->getSize() + ceil(0.2 * this->array->getSize()));
        }
        T t1 = this->array->get(index);
        T t2;
        for (int i = index; i < this->GetSize() - 1; i++) {
            t2 = t1;
            t1 = this->array->get(i + 1);
            this->array->set(t2, i + 1);
        }
        this->array->set(item, index);
    }

    virtual ArraySequence<T> *Concat(const Sequence<T> &seq) const override {
        DynamicArray<T> *array = new DynamicArray<T>(this->GetSize() + seq.GetSize());
        ArraySequence<T> *newSequence = new ArraySequence<T>(array);
        for (int i = 0; i < this->GetSize(); i++)
            newSequence->Set(this->Get(i), i);

        for (int i = 0; i < seq.GetSize(); i++)
            newSequence->Set(seq.Get(i), i + this->GetSize());

        return newSequence;
    }

    friend std::ostream& operator<<(std::ostream &out,const ArraySequence &arraySequence){
        out<<""<<std::endl;
        for (int i = 0; i < arraySequence.GetSize(); ++i) {
            out<<arraySequence.Get(i)<<" ";
        }
        out<<""<<std::endl;
        return out;
    }
};
