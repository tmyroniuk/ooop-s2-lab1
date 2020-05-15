/**
 * @file LinkedRealisation.inl
 * @author tmyroniuk
 * @date 13.10.2019
 * @brief Contains definition of LinkedRealisation class methods.
 */

#include "LinkedRealisation.h"

template<typename T>
LinkedRealisation<T>::LinkedRealisation() : ListRealisation<T>(), head(new Node()), tail(head) {}

template<typename T>
LinkedRealisation<T>::Node::Node() : NodeIterator<T>(), prev(nullptr), next(nullptr) {}

template<typename T>
LinkedRealisation<T>::Node::Node(T data, NodeIterator<T> *_prev, NodeIterator<T> *_next) : NodeIterator<T>(data), prev(_prev),
                                                                                    next(_next) {}

template<typename T>
void LinkedRealisation<T>::insert(NodeIterator<T> *pos, T data) {
    if (LinkedRealisation<T>::len == 0) {
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
    LinkedRealisation<T>::len++;
}

template<typename T>
T LinkedRealisation<T>::extract(NodeIterator<T> *pos) {
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
        LinkedRealisation<T>::len--;
    }
    return temp;
}

template<typename T>
NodeIterator<T> *LinkedRealisation<T>::begin() {
    return head;
}

template<typename T>
NodeIterator<T> *LinkedRealisation<T>::end() {
    return tail;
}

template<typename T>
LinkedRealisation<T>::~LinkedRealisation() {
    for (auto i = head->getNext(); i != nullptr; i = i->getNext()) delete i->getPrev();
    delete tail;
}

template<typename T>
NodeIterator<T> *LinkedRealisation<T>::Node::getPrev() {
    return prev;
}

template<typename T>
NodeIterator<T> *LinkedRealisation<T>::Node::backward(int count) {
    if (count < 0) forward(-count);
    NodeIterator<T> *temp = this;
    for (int i = 0; i < count; i++) {
        temp = temp->getPrev();
    }
    return temp;
}

template<typename T>
NodeIterator<T> *LinkedRealisation<T>::Node::getNext() {
    return next;
}

template<typename T>
NodeIterator<T> *LinkedRealisation<T>::Node::forward(int count) {
    if (count < 0) backward(-count);
    NodeIterator<T> *temp = this;
    for (int i = 0; i < count; i++) {
        temp = temp->getNext();
    }
    return temp;
}

template<typename T>
void LinkedRealisation<T>::Node::setPrev(NodeIterator<T> *to) {
    prev = to;
}

template<typename T>
void LinkedRealisation<T>::Node::setNext(NodeIterator<T> *to) {
    next = to;
}
