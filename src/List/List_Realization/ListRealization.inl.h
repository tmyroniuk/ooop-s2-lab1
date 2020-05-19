/**
 * @file ListRealization.inl
 * @author tmyroniuk
 * @date 13.10.2019
 * @brief Contains definition of ListRealization class methods.
 */

#include "ListRealization.h"

template<typename T>
ListRealization<T>::ListRealization() : len(0) {}

template<typename T>
unsigned int ListRealization<T>::size() {
    return len;
}
