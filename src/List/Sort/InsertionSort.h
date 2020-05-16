/**
 * @file InsertionSort.h
 * @author tmyroniuk
 * @date 22.10.2019
 * @brief Contains declaration and definition of InsertionSort class.
 */

#ifndef LAB1_INSERTIONSORT_H
#define LAB1_INSERTIONSORT_H

#include <utility>

#include "Sort.h"

/**
 * Realises insertion sort algorithm.
 *
 * Overrides the sort method of Sort class with insertion sort.
 *
 * @tparam T Type of elements sorted.
 */
template <typename T>
class SelectionSort : public Sort<T> {
public:
    /**
     * Sorts elements in range [begin, end) using custom comparator.
     *
     * Sorts elements in range [begin, end) via insertion sort with min element base.
     * Custom comparator is a bool function equal to (first >= second).
     *
     * @param begin Iterator to the begin of the range.
     * @param end Iterator to the tail of the range.
     * @param comparator Custom comparator.
     */
    void sort(Iterator<T> begin, Iterator<T> end, bool(*comparator)(const T &, const T &));
};


template<typename T>
void SelectionSort<T>::sort(Iterator <T> begin, Iterator <T> end, bool (*comparator)(const T &, const T &)) {
    //check if empty
    if(begin == end) return;
    Iterator<T> i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = begin; i != end - 1; i++) {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j != end; j++)
            if (!(*comparator)(*j, *min_idx))  min_idx = j;

        // Swap the found minimum element with the first element
        std::swap(*min_idx, *i);
    }
}


#endif //LAB1_INSERTIONSORT_H
