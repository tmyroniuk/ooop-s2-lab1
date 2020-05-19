/**
 * @file ArrayList.inl
 * @author tmyroniuk
 * @date 14.10.2019
 * @brief Contains definition of ArrayList class methods.
 */

#include "ArrayRealization.h"


template<typename T>
ArrayRealization<T>::Node::Node(T _val) : NodeIterator<T>(_val) {}

template<typename T>
NodeIterator<T> *ArrayRealization<T>::Node::getPrev() {
    return (this - 1);
}

template<typename T>
NodeIterator<T> *ArrayRealization<T>::Node::getNext() {
    return (this + 1);
}

template<typename T>
NodeIterator<T> *ArrayRealization<T>::Node::backward(int count) {
    return (this - count);
}

template<typename T>
NodeIterator<T> *ArrayRealization<T>::Node::forward(int count) {
    return (this + count);
}

template<typename T>
void ArrayRealization<T>::grow() {
    reserved*=grow_rate;
    auto temp = new Node[reserved];
    for (unsigned int i = 0; i < ListRealization<T>::len; i++) {
        temp[i].setVal(head[i].getVal());
    }
    head = temp;
}

template<typename T>
void ArrayRealization<T>::shrink() {
    if (ListRealization<T>::len != 0) return;
    auto temp = new Node;
    temp->setVal(head->getVal());
    head = temp;
}

template<typename T>
ArrayRealization<T>::ArrayRealization() : ListRealization<T>(), grow_rate(2), reserved(2), head(new Node()) {}

template<typename T>
void ArrayRealization<T>::insert(NodeIterator<T> *pos, T data) {
    auto i = end();
    while (i != pos) {
        i->setVal(i->getPrev()->getVal());
        i--;
    }
    i->setVal(data);
    ListRealization<T>::len++;
    if (ListRealization<T>::len + 1 >= reserved) grow();
}

template<typename T>
T ArrayRealization<T>::extract(NodeIterator<T> *pos) {
    T temp = pos->getVal();
    if (pos != end()) {
        ListRealization<T>::len--;
        if (ListRealization<T>::len == 0)
            shrink();
        else
            for (auto i = pos; i != end(); i++) *i = *(i->getNext());
    }
    return temp;
}


template<typename T>
ArrayRealization<T>::Node::Node() : NodeIterator<T>() {}

template<typename T>
NodeIterator<T> *ArrayRealization<T>::begin() {
    return head;
}

template<typename T>
NodeIterator<T> *ArrayRealization<T>::end() {
    return head + ListRealization<T>::len;
}

template<typename T>
ArrayRealization<T>::~ArrayRealization() {
    delete[] head;
}

