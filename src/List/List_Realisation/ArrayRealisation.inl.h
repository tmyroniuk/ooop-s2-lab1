/**
 * @file ArrayRealisation.inl
 * @author tmyroniuk
 * @date 14.10.2019
 * @brief Contains definition of ArrayRealisation class methods.
 */

#include "ArrayRealisation.h"


template<typename T>
ArrayRealisation<T>::Node::Node(T _val) : NodeIterator<T>(_val) {}

template<typename T>
NodeIterator<T> *ArrayRealisation<T>::Node::getPrev() {
    return (this - 1);
}

template<typename T>
NodeIterator<T> *ArrayRealisation<T>::Node::getNext() {
    return (this + 1);
}

template<typename T>
NodeIterator<T> *ArrayRealisation<T>::Node::backward(int count) {
    return (this - count);
}

template<typename T>
NodeIterator<T> *ArrayRealisation<T>::Node::forward(int count) {
    return (this + count);
}

template<typename T>
void ArrayRealisation<T>::grow() {
    reserved*=grow_rate;
    auto temp = new Node[reserved];
    for (unsigned int i = 0; i < ArrayRealisation<T>::len; i++) {
        temp[i].setVal(head[i].getVal());
    }
    head = temp;
}

template<typename T>
void ArrayRealisation<T>::shrink() {
    if (ArrayRealisation<T>::len != 0) return;
    auto temp = new Node;
    temp->setVal(head->getVal());
    head = temp;
}

template<typename T>
ArrayRealisation<T>::ArrayRealisation() : ListRealisation<T>(), grow_rate(2), reserved(2), head(new Node()) {}

template<typename T>
void ArrayRealisation<T>::insert(NodeIterator<T> *pos, T data) {
    auto i = end();
    while (i != pos) {
        i->setVal(i->getPrev()->getVal());
        i--;
    }
    i->setVal(data);
    ArrayRealisation<T>::len++;
    if (ArrayRealisation<T>::len + 1 >= reserved) grow();
}

template<typename T>
T ArrayRealisation<T>::extract(NodeIterator<T> *pos) {
    T temp = pos->getVal();
    if (pos != end()) {
        ArrayRealisation<T>::len--;
        if (ArrayRealisation<T>::len == 0)
            shrink();
        else
            for (auto i = pos; i != end(); i++) *i = *(i->getNext());
    }
    return temp;
}


template<typename T>
ArrayRealisation<T>::Node::Node() : NodeIterator<T>() {}

template<typename T>
NodeIterator<T> *ArrayRealisation<T>::begin() {
    return head;
}

template<typename T>
NodeIterator<T> *ArrayRealisation<T>::end() {
    return head + ArrayRealisation<T>::len;
}

template<typename T>
ArrayRealisation<T>::~ArrayRealisation() {
    delete[] head;
}

