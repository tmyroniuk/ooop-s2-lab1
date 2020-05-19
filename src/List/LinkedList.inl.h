/**
 * @file List.inl
 * @author tmyroniuk
 * @date 15.10.2019
 * @brief Contains definition of List class methods.
 */

#include "LinkedList.h"

template<typename T>
LinkedList<T>::LinkedList() : BaseList<T>(new LinkedRealization<T>()) {}
