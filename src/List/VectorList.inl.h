//
// Created by tmyro on 18.11.2019.
//

#include "VectorList.h"

template<typename T>
VectorList<T>::VectorList() : BaseList<T>(new VectorRealization<T>()) {}

template<typename T>
T &VectorList<T>::operator[](unsigned int _val) {
    return BaseList<T>::realization->begin()->forward(_val)->getVal();
}