/**
 * @file LinkedList.inl
 * @author tmyroniuk
 * @date 13.10.2019
 * @brief Contains definition of LinkedList class methods.
 */

#include "LinkedRealization.h"

template<typename T>
LinkedRealization<T>::LinkedRealization() : ListRealization<T>(), head(new Node()), tail(head) {}

template<typename T>
LinkedRealization<T>::Node::Node() : NodeIterator<T>(), prev(nullptr), next(nullptr) {}

template<typename T>
LinkedRealization<T>::Node::Node(T data, NodeIterator<T> *_prev, NodeIterator<T> *_next) : NodeIterator<T>(data), prev(_prev),
                                                                                           next(_next) {}

template<typename T>
void LinkedRealization<T>::insert(NodeIterator<T> *pos, T data) {
    if (ListRealization<T>::len == 0) {
        //create head
        head = new Node(data, nullptr, tail);
        //fix tail
        tail->setPrev(head);
    } else {
        Node *temp = new Node(data, pos->getPrev(), pos);
        //fix right
        pos->setPrev(temp);
        //in case it is not head fix left
        if (pos != head) {
            temp->getPrev()->setNext(temp);
        } else head = temp;
    }
    ListRealization<T>::len++;
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
        //fix right
        pos->getNext()->setPrev(pos->getPrev());
        delete pos;
        ListRealization<T>::len--;
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
    return prev;
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
void LinkedRealization<T>::Node::setPrev(NodeIterator<T> *to) {
    prev = to;
}

template<typename T>
void LinkedRealization<T>::Node::setNext(NodeIterator<T> *to) {
    next = to;
}
