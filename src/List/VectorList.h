/**
 * @file VectorList.h
 * @author tmyroniuk
 * @date 18.11.2019
 * @brief Contains declaration of VectorList class methods.
 */

#ifndef LAB1_VectorList_H
#define LAB1_VectorList_H

#include "BaseList.h"
#include "List_Realization/VectorRealization.h"
/**
 * Implements vector list.
 *
 * BaseList with VectorRealization realization. Iterators over this list are NOT safe to use after an
 * element is inserted or removed.
 *
 * @tparam T Type of elements in the list.
 */
template<typename T>
class VectorList : public BaseList<T> {

public:

    /**
     * Default constructor.
     *
     * Creates list from BaseList constructor with VectorRealization object as a
     * parameter.
     */
    VectorList();

    /**
     * Random access operator.
     *
     * Equal to:
     * val = *(list.begin() + _val);
     *
     * @param _val Index of element in the list (starting from zero)
     * @return Element on given index.
     */
    T &operator[](unsigned int _val);
};

#include "VectorList.inl.h"

#endif //LAB1_VectorList_H
