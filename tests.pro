QT += core



SOURCES += \
    src/Address/Address.cpp \
    src/Address/IPv4.cpp \
    src/Address/IPv6.cpp \
    src/Address/MAC.cpp \
    src/Address/Parser/IPv4_Parser.cpp \
    src/Address/Parser/IPv6_Parser.cpp \
    src/Address/Parser/MAC_Parser.cpp \
    src/Address/Parser/Parser.cpp \
    src/Address/Subnet/IPv4_Subnet.cpp \
    src/Address/Subnet/IPv6_Subnet.cpp \
    src/Address/Subnet/MAC_Subnet.cpp \
    src/Address/Subnet/Subnet.cpp \
    src/generator.cpp \
    tests/main.cpp \
    tests/tests.cpp

HEADERS += \
    src/Address/Address.h \
    src/Address/IPv4.h \
    src/Address/IPv6.h \
    src/Address/MAC.h \
    src/Address/Parser/IPv4_Parser.h \
    src/Address/Parser/IPv6_Parser.h \
    src/Address/Parser/MAC_Parser.h \
    src/Address/Parser/Parser.h \
    src/Address/Subnet/IPv4_Subnet.h \
    src/Address/Subnet/IPv6_Subnet.h \
    src/Address/Subnet/MAC_Subnet.h \
    src/Address/Subnet/Subnet.h \
    src/CustomSort.h \
    src/List/ArrayList.h \
    src/List/ArrayList.inl.h \
    src/List/BaseList.h \
    src/List/BaseList.inl.h \
    src/List/DoublyLinkedList.h \
    src/List/DoublyLinkedList.inl.h \
    src/List/Iterator.h \
    src/List/Iterator.inl.h \
    src/List/LinkedList.h \
    src/List/LinkedList.inl.h \
    src/List/List_Realization/ArrayRealization.h \
    src/List/List_Realization/ArrayRealization.inl.h \
    src/List/List_Realization/DoublyLinkedRealization.h \
    src/List/List_Realization/DoublyLinkedRealization.inl.h \
    src/List/List_Realization/LinkedRealization.h \
    src/List/List_Realization/LinkedRealization.inl.h \
    src/List/List_Realization/ListRealization.h \
    src/List/List_Realization/ListRealization.inl.h \
    src/List/List_Realization/NodeIterator.h \
    src/List/List_Realization/NodeIterator.inl.h \
    src/List/List_Realization/VectorRealization.h \
    src/List/List_Realization/VectorRealization.inl.h \
    src/List/Sort/HeapSort.h \
    src/List/Sort/InsertionSort.h \
    src/List/Sort/MergeSort.h \
    src/List/Sort/QuickSort.h \
    src/List/Sort/SelectionSort.h \
    src/List/Sort/ShellSort.h \
    src/List/Sort/Sort.h \
    src/List/VectorList.h \
    src/List/VectorList.inl.h \
    src/generator.h \
    tests/catch.hpp
