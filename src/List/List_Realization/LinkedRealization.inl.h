/**
 * @file LinkedRealization.inl.h
 * @author tmyroniuk
 * @date 13.05.2020
 * @brief Contains definition of LinkedRealization class methods.
 */
#include "LinkedRealization.h"

template<typename T>
LinkedRealization<T>::LinkedRealization() : ListRealization<T>(), head(new Node()), tail(head) {}

template<typename T>
LinkedRealization<T>::Node::Node(ListRealization<T>* _list) : NodeIterator<T>(), next(nullptr), list(_list) {}

template<typename T>
LinkedRealization<T>::Node::Node(T data, NodeIterator<T> *_next, ListRealization<T>* _list) : NodeIterator<T>(data),
                                                                                    next(_next), list(_list) {}

template<typename T>
void LinkedRealization<T>::insert(NodeIterator<T> *pos, T data) {
    if (LinkedRealization<T>::len == 0) {
        //create head
        head = new Node(data, tail, this);
    } else {
        Node *temp = new Node(data, nullptr, this);
        //in case it is not head fix left
        if (pos != head) {
            pos->getPrev()->setNext(temp);
        } else head = temp;
        //fix right
        temp->setNext(pos);

    }
    LinkedRealization<T>::len++;
}

template<typename T>
T LinkedRealization<T>::extract(NodeIterator<T> *pos) {
    T temp = pos->getVal();
    //we shouldn't delete tail
    if (pos != tail) {
        //in case it is not head fix left
        if (pos != head)
            pos->getPrev()->setNext(pos->getNext());
        else head = pos->getNext();
        delete pos;
        LinkedRealization<T>::len--;
    }
    return temp;
}

template<typename T>
NodeIterator<T> *LinkedRealization<T>::begin() {
    return head;
}

template<typename T>
NodeIterator<T> *LinkedRealization<T>::end() {
    return tail;
}

template<typename T>
LinkedRealization<T>::~LinkedRealization() {
    for (auto i = head->getNext(); i != nullptr; i = i->getNext()) delete i->getPrev();
    delete tail;
}

template<typename T>
NodeIterator<T> *LinkedRealization<T>::Node::getPrev() {
    if(this == list->begin()) return nullptr;
    //Search for node for which this node is next
    for(auto i = list->begin(); i->getNext() != nullptr; i = i->getNext());
        if(i->getNext() == this) return i;
    return nullptr;
}

template<typename T>
NodeIterator<T> *LinkedRealization<T>::Node::backward(int count) {
    if (count < 0) forward(-count);
    NodeIterator<T> *temp = this;
    for (int i = 0; i < count; i++) {
        temp = temp->getPrev();
    }
    return temp;
}

template<typename T>
NodeIterator<T> *LinkedRealization<T>::Node::getNext() {
    return next;
}

template<typename T>
NodeIterator<T> *LinkedRealization<T>::Node::forward(int count) {
    if (count < 0) backward(-count);
    NodeIterator<T> *temp = this;
    for (int i = 0; i < count; i++) {
        temp = temp->getNext();
    }
    return temp;
}

template<typename T>
void LinkedRealization<T>::Node::setNext(NodeIterator<T> *to) {
    next = to;
}
