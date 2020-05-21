/**
 * @file LinkedList.inl.h
 * @author tmyroniuk
 * @date 13.05.2020
 * @brief Contains definition of LinkedList class methods.
 */

#include "LinkedList.h"

template<typename T>
LinkedList<T>::LinkedList() : BaseList<T>(new DoublyLinkedRealization<T>()) {}
