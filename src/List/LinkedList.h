/**
 * @file List.h
 * @author tmyroniuk
 * @date 15.10.2019
 * @brief Contains declaration of List class.
 */

#ifndef LISTS_LIST_H
#define LISTS_LIST_H

#include "BaseList.h"

/**
 * Implements linked list.
 *
 * BaseList with LinkedRealisation realisation. Iterators over this are safe to use after an
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
     * Creates List from BaseList constructor and LinkedRealisation object as a
     * parameter.
     */
    LinkedList();
};

#include "LinkedList.inl.h"


#endif //LISTS_LIST_H
