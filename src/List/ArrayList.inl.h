/**
 * @file ArrayList.inl.h
 * @author tmyroniuk
 * @date 15.10.2019
 * @brief Contains definition of ArrayList class methods.
 */

#include "ArrayList.h"

template<typename T>
ArrayList<T>::ArrayList() : BaseList<T>(new ArrayRealisation<T>()) {}

template<typename T>
T &ArrayList<T>::operator[](unsigned int _val) {
    return BaseList<T>::realisation->begin()->forward(_val)->getVal();
}
