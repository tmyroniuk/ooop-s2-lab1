//
// Created by tmyro on 18.11.2019.
//

#include "VectorList.h"

template<typename T>
VectorList<T>::VectorList() : BaseList<T>(new VectorRealisation<T>()) {}

template<typename T>
T &VectorList<T>::operator[](unsigned int _val) {
    return BaseList<T>::realisation->begin()->forward(_val)->getVal();
}
