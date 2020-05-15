//
// Created by tmyro on 18.11.2019.
//

#include "VectorRealisation.h"

template<typename T>
VectorRealisation<T>::Node::Node(T _val) : NodeIterator<T>(_val) {}

template<typename T>
NodeIterator<T> *VectorRealisation<T>::Node::getPrev() {
    return (this - 1);
}

template<typename T>
NodeIterator<T> *VectorRealisation<T>::Node::getNext() {
    return (this + 1);
}

template<typename T>
NodeIterator<T> *VectorRealisation<T>::Node::backward(int count) {
    return (this - count);
}

template<typename T>
NodeIterator<T> *VectorRealisation<T>::Node::forward(int count) {
    return (this + count);
}

template<typename T>
VectorRealisation<T>::VectorRealisation() : ListRealisation<T>(), body(new std::vector<Node>(1)) {}

template<typename T>
void VectorRealisation<T>::insert(NodeIterator<T> *pos, T data) {
    T temp;
    if (pos == end()) temp = data;
    else {
        temp = body->back().getVal();
        auto i = end() - 1;
        while (i != pos) {
            i->setVal(i->getPrev()->getVal());
            i--;
        }
        i->setVal(data);
    }
    VectorRealisation<T>::len++;
    body->push_back(Node(temp));
}

template<typename T>
T VectorRealisation<T>::extract(NodeIterator<T> *pos) {
    T temp = pos->getVal();
    if (pos != end())
        for (auto i = pos; i != end(); i++)
            *i = *(i->getNext());
    body->pop_back();
    VectorRealisation<T>::len--;
    return temp;
}


template<typename T>
VectorRealisation<T>::Node::Node() : NodeIterator<T>() {}

template<typename T>
NodeIterator<T> *VectorRealisation<T>::begin() {
    return &(body->front());
}

template<typename T>
NodeIterator<T> *VectorRealisation<T>::end() {
    return &(body->back());
}

template<typename T>
VectorRealisation<T>::~VectorRealisation() {
    delete body;
}
