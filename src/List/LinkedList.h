/**
 * @file LinkedList.h
 * @author tmyroniuk
 * @date 13.05.2020
 * @brief Contains declaration of LinkedList class methods.
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include "BaseList.h"

/**
 * Implements linked list.
 *
 * BaseList with LinkedRealization realization. Iterators over it are safe to use after an
 * element is inserted or removed.
 *
 * @tparam T Type of elements in the list.
 */
template<typename T>
class LinkedList : public BaseList<T> {

public:

    /**
     * Default constructor.
     *
     * Creates List from BaseList constructor and LinkedRealization object as a
     * parameter.
     */
    LinkedList();
};

#include "LinkedList.inl.h"

#endif // LINKEDLIST_H
