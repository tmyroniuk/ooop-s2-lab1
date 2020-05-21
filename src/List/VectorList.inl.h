/**
 * @file VectorList.inl.h
 * @author tmyroniuk
 * @date 18.11.2019
 * @brief Contains definition of VectorList class methods.
 */

#include "VectorList.h"

template<typename T>
VectorList<T>::VectorList() : BaseList<T>(new VectorRealization<T>()) {}

template<typename T>
T &VectorList<T>::operator[](unsigned int _val) {
    return BaseList<T>::realization->begin()->forward(_val)->getVal();
}
