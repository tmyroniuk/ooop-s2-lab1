/**
 * @file VectorRealization.inl.h
 * @author tmyroniuk
 * @date 14.10.2019
 * @brief Contains definition of VectorRealization class methods.
 */

#include "VectorRealization.h"

template<typename T>
VectorRealization<T>::Node::Node(T _val) : NodeIterator<T>(_val) {}

template<typename T>
NodeIterator<T> *VectorRealization<T>::Node::getPrev() {
    return (this - 1);
}

template<typename T>
NodeIterator<T> *VectorRealization<T>::Node::getNext() {
    return (this + 1);
}

template<typename T>
NodeIterator<T> *VectorRealization<T>::Node::backward(int count) {
    return (this - count);
}

template<typename T>
NodeIterator<T> *VectorRealization<T>::Node::forward(int count) {
    return (this + count);
}

template<typename T>
VectorRealization<T>::VectorRealization() : ListRealization<T>(), body(new std::vector<Node>(1)) {}

template<typename T>
void VectorRealization<T>::insert(NodeIterator<T> *pos, T data) {
    int j = 0;
    for(auto i = begin(); i != pos; i = i->getNext()) j++;
    body->insert(body->begin() + j, Node(data));
    ListRealization<T>::len++;
}

template<typename T>
T VectorRealization<T>::extract(NodeIterator<T> *pos) {
    T temp = pos->getVal();
    if (pos != end())
        for (auto i = pos; i != end(); i++)
            *i = *(i->getNext());
    body->pop_back();
    ListRealization<T>::len--;
    return temp;
}


template<typename T>
VectorRealization<T>::Node::Node() : NodeIterator<T>() {}

template<typename T>
NodeIterator<T> *VectorRealization<T>::begin() {
    return &(body->front());
}

template<typename T>
NodeIterator<T> *VectorRealization<T>::end() {
    return &(body->back());
}

template<typename T>
VectorRealization<T>::~VectorRealization() {
    delete body;
}
