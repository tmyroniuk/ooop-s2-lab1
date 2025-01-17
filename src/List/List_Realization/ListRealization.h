/**
 * @file ListRealization.h
 * @author tmyroniuk
 * @date 13.10.2019
 * @brief Contains declaration of ListRealization class.
 */

#ifndef LISTS_LISTREALIZATION_H
#define LISTS_LISTREALIZATION_H

#include "NodeIterator.h"

/**
 * Base class for
 * @tparam T Type of elements stored.
 */
template<typename T>
class ListRealization {
protected:

    /**
     * Amount of elements in the list.
     */
    unsigned int len;

public:

    /**
     * Default constructor.
     */
    explicit ListRealization();

    /*
     * Inserts new element with given value before given position.
     *
     * @param pos Insertion position.
     * @param data New element value.
     */
    virtual void insert(NodeIterator<T> *pos, T data) = 0;

    /**
     * Removes element on given position from the list, returns its value.
     *
     * @param pos Pointer to the node removed.
     *
     * @return Removed element value.
     */
    virtual T extract(NodeIterator<T> *pos) = 0;

    /**
     * Returns pointer to the first element.
     *
     * @return Pointer to the head.
     */
    virtual NodeIterator<T> *begin() = 0;

    /**
     * Returns pointer to the list tail.
     *
     * @return Pointer to the head.
     */
    virtual NodeIterator<T> *end() = 0;

    /**
     * Returns amount of elements in the list.
     *
     * @return List len.
     */
    unsigned int size();

    virtual ~ListRealization() = default;
};

#include "ListRealization.inl.h"

#endif //LISTS_LISTREALIZATION_H
