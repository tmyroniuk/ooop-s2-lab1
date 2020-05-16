/**
 * @file DoublyLinkedList.h
 * @author tmyroniuk
 * @date 15.10.2019
 * @brief Contains declaration of DoublyLinkedList class.
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
class DoublyLinkedList : public BaseList<T> {

public:

    /**
     * Default constructor.
     *
     * Creates List from BaseList constructor and LinkedRealisation object as a
     * parameter.
     */
    DoublyLinkedList();
};

#include "DoublyLinkedList.inl.h"


#endif //LISTS_LIST_H
