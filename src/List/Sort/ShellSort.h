#ifndef SHELLSORT_H
#define SHELLSORT_H

#include <utility>

#include "Sort.h"

/**
 * Realises basic Shell's sort algorithm.
 *
 * Overrides the sort method of Sort class.
 *
 * @tparam T Type of elements sorted.
 */
template <typename T>
class ShellSort : public Sort<T> {
    /**
     * @brief Calculates size of list range given.
     * @param begin Iterator to the begin of the range.
     * @param end Iterator to the tail of the range.
     * @return Lenght of given range.
     */
    int range(Iterator<T> begin, Iterator<T> end);
public:
    /**
     * Sorts elements in range [begin, end) using custom comparator.
     *
     * Sorts elements in range [begin, end) via basic Shell's sort with min element base.
     * Custom comparator is a bool function equal to (first >= second).
     *
     * @param begin Iterator to the begin of the range.
     * @param end Iterator to the tail of the range.
     * @param comparator Custom comparator.
     */
    void sort(Iterator<T> begin, Iterator<T> end, bool(*comparator)(const T &, const T &));
};


template<typename T>
int ShellSort<T>::range(Iterator<T> begin, Iterator<T> end)
{
    int size = 0;
    for(auto i = begin; i != end; i++) size++;
    return size;
}

template<typename T>
void ShellSort<T>::sort(Iterator <T> begin, Iterator <T> end, bool (*comparator)(const T &, const T &)) {
    int size = range(begin, end);
    //Choosing step
    for (int step = size/2; step > 0; step /= 2)
        for (auto i = begin + step; i != end; i++) {
            auto temp = *i;
            auto j = i;
            for (; range(begin, j) >= step && (*comparator)(*(j - step), temp); j -= step)
                *j = *(j - step);
            *j = temp;
        }
}

#endif // SHELLSORT_H
