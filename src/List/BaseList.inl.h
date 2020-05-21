/**
 * @file BaseList.inl.h
 * @author tmyroniuk
 * @date 13.10.2019
 * @brief Contains definition of BaseList class methods.
 */

#include "BaseList.h"
#include "List_Realization/DoublyLinkedRealization.h"
#include "List_Realization/ArrayRealization.h"


template<typename T>
NodeIterator<T> *BaseList<T>::getNode(const Iterator<T> &_iterator) {
    return _iterator.node;
}

template<typename T>
Iterator<T> BaseList<T>::begin() {
    return Iterator<T>(realization->begin());
}

template<typename T>
Iterator<T> BaseList<T>::end() {
    return Iterator<T>(realization->end());
}


template<typename T>
void BaseList<T>::insert(const Iterator<T> &pos, T data) {
    realization->insert(getNode(pos), data);
}

template<typename T>
T BaseList<T>::extract(const Iterator<T> &pos) {
    return realization->extract(getNode(pos));
}

template<typename T>
unsigned int BaseList<T>::size() {
    return realization->size();
}

template<typename T>
BaseList<T>::BaseList(ListRealization<T> *type) : realization(type), sorting_algo(new QuickSort<T>) {}

template<typename T>
void BaseList<T>::push_back(T data) {
    realization->insert(realization->end(), data);
}

template<typename T>
void BaseList<T>::push_front(T data) {
    realization->insert(realization->begin(), data);
}

template<typename T>
T BaseList<T>::pop_back() {
    return realization->extract(realization->end()->getPrev());
}

template<typename T>
T BaseList<T>::pop_front() {
    return realization->extract(realization->begin());
}

template<typename T>
T &BaseList<T>::front() {
    return realization->begin()->getVal();
}

template<typename T>
T &BaseList<T>::back() {
    return realization->end()->getPrev()->getVal();
}

template<typename T>
BaseList<T>::~BaseList() {
    delete realization;
}

template<typename T>
bool BaseList<T>::empty() {
    return realization->size() == 0;
}

template<typename T>
void BaseList<T>::sort() {
    sorting_algo->sort(begin(), end());
}

template<typename T>
void BaseList<T>::sort(bool (*comparator)(const T &, const T &)) {
    sorting_algo->sort(begin(), end(), comparator);
}

template<typename T>
void BaseList<T>::setSortAlgo(Sort<T> *to) {
    delete sorting_algo;
    sorting_algo = to;
}
