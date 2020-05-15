QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

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
    src/genericlistmodel.cpp \
    src/main.cpp \
    src/mainwindow.cpp

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
    src/List/Iterator.h \
    src/List/Iterator.inl.h \
    src/List/LinkedList.h \
    src/List/LinkedList.inl.h \
    src/List/List_Realisation/ArrayRealisation.h \
    src/List/List_Realisation/ArrayRealisation.inl.h \
    src/List/List_Realisation/LinkedRealisation.h \
    src/List/List_Realisation/LinkedRealisation.inl.h \
    src/List/List_Realisation/ListRealisation.h \
    src/List/List_Realisation/ListRealisation.inl.h \
    src/List/List_Realisation/NodeIterator.h \
    src/List/List_Realisation/NodeIterator.inl.h \
    src/List/List_Realisation/VectorRealisation.h \
    src/List/List_Realisation/VectorRealisation.inl.h \
    src/List/Sort/InsertionSort.h \
    src/List/Sort/MergeSort.h \
    src/List/Sort/QuickSort.h \
    src/List/Sort/Sort.h \
    src/List/VectorList.h \
    src/List/VectorList.inl.h \
    src/generator.h \
    src/genericlistmodel.h \
    src/mainwindow.h

FORMS += \
    src/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
