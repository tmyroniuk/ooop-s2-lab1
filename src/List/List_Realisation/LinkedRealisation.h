/**
 * @file LinkedRealisation.inl.h
 * @author tmyroniuk
 * @date 13.05.2020
 * @brief Contains definition of LinkedRealisation class methods.
 */
#ifndef LINKEDREALISATION_H
#define LINKEDREALISATION_H


#include "ListRealisation.h"

/**
 * Realisation of the doubly linked list.
 *
 * Realisation of the list which stores Nodes pointing to next node.
 * List ends with tail node, first Node in the list is head.
 *
 * @tparam T Type if the elements stored.
 */
template<typename T>
class LinkedRealisation : public ListRealisation<T> {
public:
    /**
     * Implementation of node and iterator over linked list
     *
     * Behaves as node and iterator in LinkedRealisation. Overrides methods
     * of NodeIterator class to work with array list.
     */
    class Node : public NodeIterator<T> {
    private:
        /**
         * Pointer to the next node in the list.
         */
        NodeIterator<T> *next;

        /**
         * Pointer to the next node in the list.
         */
        LinkedRealisation<T> *list;

    public:

        /**
         * Constructs node in of the list.
         */
        Node(ListRealisation<T>* _list);

        /**
         * Creates node with given value and pointers to next element and containing list.
         *
         * @param data New node value.
         * @param _prev Element before new node.
         * @param _next Element after new node.
         */
        Node(T data, NodeIterator<T> *_next, ListRealisation<T>* _list);

        /**
         * Returns ptr to the previous element.
         *
         * @return Pointer to the previous node.
         */
        NodeIterator<T> *getPrev();

        /**
         * Returns ptr to the next element.
         *
         * @return Pointer to the next node.
         */
        NodeIterator<T> *getNext();

        /**
         * Returns node <count> positions after this.
         *
         * @param count Positions forward to move.
         *
         * @return Pointer to the node <count> positions after this.
         */
        NodeIterator<T> *forward(int count);

        /**
         * Returns node <count> positions before this.
         *
         * @param count Positions backward to move.
         *
         * @return Pointer to the node <count> positions before this.
         */
        NodeIterator<T> *backward(int count);

        /**
         * Changes previous element to given.
         *
         * @param to New previous element.
         */
        virtual void setPrev(NodeIterator<T> *to) {}

        /**
         * Changes next element to given.
         *
         * @param to New next element.
         */
        virtual void setNext(NodeIterator<T> *to);
    };

    /**
     * Default constructor.
     *
     * Creates tail node. Set the head pointer to it. Links them.
     */
    LinkedRealisation();

    /**
     * Inserts new element with given value before given position.
     *
     * @param pos Insertion position.
     * @param data New element value.
     */
    void insert(NodeIterator<T> *pos, T data);

    /**
     * Removes element on given position from the list, returns its value.
     *
     * @param pos Pointer to the node removed.
     *
     * @return Removed element value.
     */
    T extract(NodeIterator<T> *pos);

    /**
     * Returns pointer to the first element.
     *
     * @return Pointer to the head.
     */
    NodeIterator<T> *begin();

    /**
     * Returns pointer to the tail.
     *
     * @return Tail pointer.
     */
    NodeIterator<T> *end();

    /**
     * Destructor.
     *
     * Deletes each element of the list. Does NOT delete raw pointers stored
     * in the list.
     */
    virtual ~LinkedRealisation();

private:

    /**
     * Pointer to the first element.
     */
    NodeIterator<T> *head;

    /**
     * Pointer to the tail. Tail always exist.
     */
    NodeIterator<T> *tail;
};

#include "LinkedRealisation.inl.h"

#endif // LINKEDREALISATION_H
