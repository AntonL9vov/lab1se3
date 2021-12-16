
#ifndef MEPHI_3_LAB_1_LISTSEQUENCE_H
#define MEPHI_3_LAB_1_LISTSEQUENCE_H

#endif //MEPHI_3_LAB_1_LISTSEQUENCE_H

#include "ArraySequence.h"

template<typename T>
class ListSequence : public Sequence<T> {
protected:
    LinkedList<T> *list;
public:

    ListSequence() {
        this->list = new LinkedList<T>();
    }

    ListSequence(const ListSequence<T> &seq) {
        this->list = new LinkedList<T>(*seq.list);
    }

    ListSequence(LinkedList<T> *list) {
        this->list = list;
    }

    ListSequence(T *items, int size) {
        this->list = new LinkedList<T>(items, size);
    }

    ListSequence(int size) {
        this->list = new LinkedList<T>(size);
    }

    virtual ~ListSequence() {
        delete this->list;
    }

    virtual T GetFirst() const override {
        return this->list->getFirst();
    }


    virtual T GetLast() const override {
        return this->list->getLast();
    }

    virtual T Get(int index) const override {
        return this->list->get(index);
    }

    virtual int GetSize() const override {
        return this->list->getSize();
    }

    virtual ListSequence<T> *GetSubsequence(int start, int end) const override {
        LinkedList<T> *subList = this->list->getSublist(start, end);
        ListSequence<T> *seq = new ListSequence<T>(subList);
        return seq;
    }

    virtual void Set(const T &item, int index) override {
        this->list->set(item, index);
    }

    virtual void Append(const T &item) override {
        this->list->append(item);
    }

    virtual void Prepend(const T &item) override {
        this->list->prepend(item);
    }

    virtual void InsertAt(const T &item, int index) override {
        this->list->insertAt(item, index);
    }

    virtual ListSequence<T> *Concat(const Sequence<T> &seq) const override {
        ListSequence<T> *newSequence = new ListSequence<T>();

        for (int i = 0; i < this->GetSize(); i++)
            newSequence->Append(this->Get(i));

        for (int i = 0; i < seq.GetSize(); i++)
            newSequence->Append(seq.Get(i));

        return newSequence;
    }

    friend std::ostream& operator<<(std::ostream &out,const ListSequence<T> &listSequence){
        out<<""<<std::endl;
        for (int i = 0; i < listSequence.GetSize(); ++i) {
            out << listSequence.Get(i) << " ";
        }
        out<<""<<std::endl;
        return out;
    }
};