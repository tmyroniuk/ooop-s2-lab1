#ifndef GENERATOR_H
#define GENERATOR_H

#include <string>
#include <random>

#include <QString>

#include "List/ArrayList.h"
#include "List/DoublyLinkedList.h"
#include "List/VectorList.h"
#include "List/LinkedList.h"
#include "Address/IPv4.h"
#include "Address/MAC.h"
#include "List/Sort/ShellSort.h"
#include "List/Sort/SelectionSort.h"
#include "List/Sort/HeapSort.h"
#include "List/Sort/MergeSort.h"
#include "List/Sort/QuickSort.h"
#include "List/Sort/InsertionSort.h"

template <typename T>
class Generator
{
    static std::random_device rd;

public:
    static T rand_val();

    static T concrete_val(const std::string& str);

    static QString to_qstring(const T& val);
};

#endif // GENERATOR_H
