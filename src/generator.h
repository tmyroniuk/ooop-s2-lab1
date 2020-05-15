#ifndef GENERATOR_H
#define GENERATOR_H

#include <string>
#include <random>

#include <QString>

#include "List/ArrayList.h"
#include "List/LinkedList.h"
#include "List/VectorList.h"
#include "Address/IPv4.h"
#include "Address/MAC.h"
#include "List/Sort/MergeSort.h"
#include "List/Sort/QuickSort.h"
#include "List/Sort/InsertionSort.h"
#include "CustomSort.h"

template <typename T>
class Generator
{
public:
    static T rand_val();

    static T concrete_val(const std::string& str);

    static QString to_qstring(const T& val);
};

#endif // GENERATOR_H
