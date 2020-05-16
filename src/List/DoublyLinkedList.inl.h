/**
 * @file DoublyLinkedList.inl.h
 * @author tmyroniuk
 * @date 15.10.2019
 * @brief Contains definition of DoublyLinkedList class methods.
 */

#include "DoublyLinkedList.h"

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() : BaseList<T>(new DoublyLinkedRealisation<T>()) {}
