/**
 * @file Vector.inl
 * @author tmyroniuk
 * @date 15.10.2019
 * @brief Contains definition of Vector class methods.
 */

#include "ArrayList.h"

template<typename T>
ArrayList<T>::ArrayList() : BaseList<T>(new ArrayRealization<T>()) {}

template<typename T>
T &ArrayList<T>::operator[](unsigned int _val) {
    return BaseList<T>::realization->begin()->forward(_val)->getVal();
}
