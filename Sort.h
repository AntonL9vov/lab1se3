#pragma once
#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <string>
#include <functional>
#include "Sequence.h"

using namespace std;

template<typename T>
class Sorter {
protected:
    void Swap(Sequence<T> &seq, int i1, int i2) {
        T item = seq.Get(i1);
        seq.Set(seq.Get(i2), i1);
        seq.Set(item, i2);
    }

public:
    Sorter() {};

    void BubbleSort(Sequence<T> &seq, int(*func)(T, T), int mode = 0) {
        int size = seq.GetSize();
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (mode < 0) {
                    if (func(seq.Get(j), seq.Get(j + 1)) < 0) {
                        Swap(seq, j, j + 1);
                    }
                } else {
                    if (func(seq.Get(j), seq.Get(j + 1)) > 0) {
                        Swap(seq, j, j + 1);
                    }
                }

            }
        }
    }

    void ShakerSort(Sequence<T> &seq, int(*func)(T, T), int mode = 0) {

        int size = seq.GetSize();
        int left = 0;
        int right = size - 1;
        int flag = 1;

        while ((left < right) && (flag > 0)) {
            flag = 0;
            for (int i = left; i < right; i++) {
                if (mode < 0) {
                    if (func(seq.Get(i), seq.Get(i + 1)) < 0) {
                        Swap(seq, i, i + 1);
                        flag = 1;
                    }
                } else {
                    if (func(seq.Get(i), seq.Get(i + 1)) > 0) {
                        Swap(seq, i, i + 1);
                        flag = 1;
                    }
                }

            }
            right--;

            for (int i = right; i > left; i--) {
                if (mode < 0) {
                    if (func(seq.Get(i - 1), seq.Get(i)) < 0) {
                        Swap(seq, i, i - 1);
                        flag = 1;
                    }
                } else {
                    if (func(seq.Get(i - 1), seq.Get(i)) > 0) {
                        Swap(seq, i, i - 1);
                        flag = 1;
                    }
                }

            }
            left++;
        }
    }

    void QuickSort(Sequence<T> &seq, int(*func)(T, T), int right, int left = 0) {
        if (left < right) {
            T v = seq.Get((left+right)/2);
            int l = left;
            int r = right;
            while (l <= r){
                while (seq.Get(l) < v)
                    l++;
                while (seq.Get(r) > v)
                    r--;
                if(l >= r)
                    break;
                Swap(seq, l++, r--);
            }

            QuickSort(seq, func, r, left);
            QuickSort(seq, func, right, r + 1);
        }
    }

    void InsertionSort(Sequence<T> &seq, int(*func)(T, T), int mode = 0) {
        int length = seq.GetSize();
        T tmp;
        int item;
        for (int i = 1; i < length; i++) {
            tmp = seq.Get(i);
            item = i - 1;
            if (mode < 0) {
                while (item >= 0 && func(seq.Get(item), tmp) < 0) {
                    seq.Set(seq.Get(item), item + 1);
                    seq.Set(tmp, item);
                    item--;
                }
            } else {
                while (item >= 0 && func(seq.Get(item), tmp) > 0) {
                    seq.Set(seq.Get(item), item + 1);
                    seq.Set(tmp, item);
                    item--;
                }
            }
        }
    }

    void ShellSort(Sequence<T> &seq, int(*func)(T, T), int mode = 0) {
        int step, i, j;
        int size = seq.GetSize();

        for (step = size / 2; step > 0; step /= 2) {
            for (i = step; i < size; i++) {
                if (mode < 0) {
                    for (j = i - step; j >= 0 && func(seq.Get(j), seq.Get(j + step)) < 0; j -= step) {
                        Swap(seq, j, j + step);
                    }
                } else {
                    for (j = i - step; j >= 0 && func(seq.Get(j), seq.Get(j + step)) > 0; j -= step) {
                        Swap(seq, j, j + step);
                    }
                }
            }
        }
    }

};


#endif // SORT_H
