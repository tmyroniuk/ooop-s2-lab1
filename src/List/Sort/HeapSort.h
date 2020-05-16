/**
 * @file InsertionSort.h
 * @author tmyroniuk
 * @date 22.10.2019
 * @brief Contains declaration and definition of InsertionSort class.
 */
#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <utility>

#include "Sort.h"

/**
 * Realises heap sort algorithm.
 *
 * Overrides the sort method of Sort class with heap sort.
 *
 * @tparam T Type of elements sorted.
 */
template <typename T>
class HeapSort : public Sort<T> {

    void restoreHeap(Iterator<T> begin, int father, int size, bool(*comparator)(const T &, const T &));

public:
    /**
     * Sorts elements in range [begin, end) using custom comparator.
     *
     * Sorts elements in range [begin, end) via insertion sort. Custom
     * comparator is a bool function equal to (first >= second).
     *
     * @param begin Iterator to the begin of the range.
     * @param end Iterator to the tail of the range.
     * @param comparator Custom comparator.
     */
    void sort(Iterator<T> begin, Iterator<T> end, bool(*comparator)(const T &, const T &));
};

template<typename T>
void HeapSort<T>::restoreHeap(Iterator<T> begin, int father, int size, bool (*comparator)(const T &, const T &)) {
    while(father < size / 2) {
        int maxson = 2 * father + 1;
        if (2 * father + 2 < size && (*comparator)(*(begin + 2 * father + 2), *(begin + 2 * father + 1)))
            maxson++;
        if ((*comparator)(*(begin + maxson), *(begin + father)) && *(begin + maxson) != *(begin + father)) {
                std::swap(*(begin + maxson),*(begin + father));
                father = maxson;
        }
        else return;
    }
}

/*
 * Basic heapsort algorithm, which sorts array
 * in range [begin, end) using comparator as >= function.
 */
template<typename T>
void HeapSort<T>::sort(Iterator <T> begin, Iterator <T> end, bool (*comparator)(const T &, const T &)) {
    int size = 0;
    for(auto i = begin; i != end; i++) size++;
    for(int i = size / 2 - 1; i >= 0; i--)
        restoreHeap(begin, i, size, comparator);

    for(int i = size - 1; i > 0; i--) {
        //Swap max (first) with the last in unsorted part
        std::swap(*begin, *(begin + i));
        //Restore heap
        restoreHeap(begin, 0, i - 1, comparator);
    }
}

#endif // HEAPSORT_H
