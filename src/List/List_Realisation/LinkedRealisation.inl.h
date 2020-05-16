/**
 * @file LinkedRealisation.inl.h
 * @author tmyroniuk
 * @date 13.05.2020
 * @brief Contains definition of LinkedRealisation class methods.
 */
#include "LinkedRealisation.h"

template<typename T>
LinkedRealisation<T>::LinkedRealisation() : ListRealisation<T>(), head(new Node()), tail(head) {}

template<typename T>
LinkedRealisation<T>::Node::Node(ListRealisation<T>* _list) : NodeIterator<T>(), next(nullptr), list(_list) {}

template<typename T>
LinkedRealisation<T>::Node::Node(T data, NodeIterator<T> *_next, ListRealisation<T>* _list) : NodeIterator<T>(data),
                                                                                    next(_next), list(_list) {}

template<typename T>
void LinkedRealisation<T>::insert(NodeIterator<T> *pos, T data) {
    if (LinkedRealisation<T>::len == 0) {
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
    if(this == list->begin()) return nullptr;
    //Search for node for which this node is next
    for(auto i = list->begin(); i->getNext() != nullptr; i = i->getNext());
        if(i->getNext() == this) return i;
    return nullptr;
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
void LinkedRealisation<T>::Node::setNext(NodeIterator<T> *to) {
    next = to;
}
