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

    int range(Iterator<T> begin, Iterator<T> end);

    void heapify(Iterator<T> begin, int n, Iterator<T> i, bool(*comparator)(const T &, const T &));

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
int HeapSort<T>::range(Iterator<T> begin, Iterator<T> end)
{
    int size = 0;
    for(auto i = begin; i != end; i++) size++;
    return size;
}

template<typename T>
void HeapSort<T>::heapify(Iterator<T> begin, int n, Iterator<T> i, bool (*comparator)(const T &, const T &)) {
        auto largest = i; // Initialize largest as root
        int i_range = range(begin, i);
        // If left child is larger than root
        if(i_range * 2 + 1 < n) {
            auto l = begin + i_range * 2 + 1;
            if((*comparator)(*l, *largest))
                largest = l;
        }
        // If right child is larger than largest so far
        if(i_range * 2 + 2 < n) {
            auto r = begin + i_range * 2 + 2;
            if((*comparator)(*r, *largest))
                largest = r;
        }
        // If largest is not root
        if(largest != i) {
            std::swap(*i, *largest);
            // Recursively heapify the affected sub-tree
            heapify(begin, n, largest, comparator);
        }
}

/*
 * Basic heapsort algorithm, which sorts array
 * in range [begin, end) using comparator as >= function.
 */
template<typename T>
void HeapSort<T>::sort(Iterator <T> begin, Iterator <T> end, bool (*comparator)(const T &, const T &)) {
    int n = range(begin, end); //range size
    if(n == 0) return;
    // Build heap (rearrange array)
    for (auto i = begin + n/2 - 1; i != begin; i--)
        heapify(begin, n, i, comparator);
    heapify(begin, n, begin, comparator);

    // One by one extract an element from heap
    int j = n - 1;
    for (auto i = end - 1; i != begin; i--, j--) {
        // Move current root to end
        std::swap(*begin, *i);
        // call max heapify on the reduced heap
        heapify(begin, j, begin, comparator);
    }
}

#endif // HEAPSORT_H
