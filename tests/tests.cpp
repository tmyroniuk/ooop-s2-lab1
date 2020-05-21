#include <utility>

#include "catch.hpp"

#include "../src/generator.h"
#include "../src/Address/IPv4.h"
#include "../src/Address/IPv6.h"
#include "../src/Address/MAC.h"
#include "../src/List/LinkedList.h"
#include "../src/List/ArrayList.h"
#include "../src/List/VectorList.h"
#include "../src/List/DoublyLinkedList.h"
#include "../src/List/Sort/QuickSort.h"
#include "../src/List/Sort/MergeSort.h"
#include "../src/List/Sort/InsertionSort.h"
#include "../src/List/Sort/HeapSort.h"
#include "../src/List/Sort/SelectionSort.h"
#include "../src/List/Sort/ShellSort.h"

TEST_CASE("LinkedList tests") {
    LinkedList<int> list;
    REQUIRE(list.empty());
    list.push_back(1);
    list.push_back(5);
    list.push_back(4);

    SECTION("insertion") {
        REQUIRE((*list.begin()) == 1);
        REQUIRE((*(list.begin() + 1)) == 5);
        REQUIRE((*(list.begin() + 2)) == 4);
        list.push_front(255);
        REQUIRE(list.front() == 255);
        list.insert(list.begin() + 2, 0);
        REQUIRE((*(list.begin() + 2)) == 0);
        REQUIRE(list.size() == 5);
    }
    SECTION("removal") {
        REQUIRE(list.pop_front() == 1);
        REQUIRE(list.pop_back() == 4);
        REQUIRE(list.extract(list.begin()) == 5);
        REQUIRE(list.empty());
    }
}
TEST_CASE("ArrayList tests") {
    ArrayList<int> list;
    REQUIRE(list.empty());
    list.push_back(1);
    list.push_back(5);
    list.push_back(4);

    SECTION("insertion") {
        REQUIRE(list[0] == 1);
        REQUIRE(list[1] == 5);
        REQUIRE(list[2] == 4);
        list.push_front(255);
        REQUIRE(list[0] == 255);
        list.insert(list.begin() + 2, 0);
        REQUIRE(list[2] == 0);
        REQUIRE(list.size() == 5);
    }
    SECTION("removal") {
        REQUIRE(list.pop_front() == 1);
        REQUIRE(list.pop_back() == 4);
        REQUIRE(list.extract(list.begin()) == 5);
        REQUIRE(list.empty());
    }
}
TEST_CASE("VectorList tests") {
    VectorList<int> list;
    REQUIRE(list.empty());
    list.push_back(1);
    list.push_back(5);
    list.push_back(4);

    SECTION("insertion") {
        REQUIRE(list[0] == 1);
        REQUIRE(list[1] == 5);
        REQUIRE(list[2] == 4);
        list.push_front(255);
        REQUIRE(list[0] == 255);
        list.insert(list.begin() + 2, 0);
        REQUIRE(list[2] == 0);
        REQUIRE(list.size() == 5);
    }
    SECTION("removal") {
        REQUIRE(list.pop_front() == 1);
        REQUIRE(list.pop_back() == 4);
        REQUIRE(list.extract(list.begin()) == 5);
        REQUIRE(list.empty());
    }
}
TEST_CASE("Sorting tests") {
    ArrayList<int> list;
    int size = 200;
    for(int i = 0; i < size; i++) list.push_back(Generator<int>::rand_val());

    SECTION("Quick sort") {
        list.setSortAlgo(new QuickSort<int>);
        list.sort();
        for(int i = 0; i < size - 1; i++) {
            DYNAMIC_SECTION(i) {
                REQUIRE(list[i] <= list[i+1]);
            }
        }
    }
    SECTION("Merge sort") {
        list.setSortAlgo(new MergeSort<int>);
        list.sort();
        for(int i = 0; i < size - 1; i++) {
            DYNAMIC_SECTION(i) {
                REQUIRE(list[i] <= list[i+1]);
            }
        }
    }
    SECTION("Insertion sort") {
        list.setSortAlgo(new InsertionSort<int>);
        list.sort();
        for(int i = 0; i < size - 1; i++) {
            DYNAMIC_SECTION(i) {
                REQUIRE(list[i] <= list[i+1]);
            }
        }
    }
    SECTION("Selection sort") {
        list.setSortAlgo(new SelectionSort<int>);
        list.sort();
        for(int i = 0; i < size - 1; i++) {
            DYNAMIC_SECTION(i) {
                REQUIRE(list[i] <= list[i+1]);
            }
        }
    }
    SECTION("Shell's sort") {
        list.setSortAlgo(new ShellSort<int>);
        list.sort();
        for(int i = 0; i < size - 1; i++) {
            DYNAMIC_SECTION(i) {
                REQUIRE(list[i] <= list[i+1]);
            }
        }
    }
    SECTION("Heap sort") {
        list.setSortAlgo(new HeapSort<int>);
        list.sort();
        for(int i = 0; i < size - 1; i++) {
            DYNAMIC_SECTION(i) {
                REQUIRE(list[i] <= list[i+1]);
            }
        }
    }
    SECTION("Consistency") {
        ArrayList<int> list2;
        ArrayList<int> list3;
        ArrayList<int> list4;
        ArrayList<int> list5;
        ArrayList<int> list6;
        for(int i = 0; i < size; i++) {
            list2.push_back(list[i]);
            list3.push_back(list[i]);
            list4.push_back(list[i]);
            list5.push_back(list[i]);
            list6.push_back(list[i]);
        }
        list.setSortAlgo(new QuickSort<int>);
        list2.setSortAlgo(new MergeSort<int>);
        list3.setSortAlgo(new InsertionSort<int>);
        list4.setSortAlgo(new SelectionSort<int>);
        list5.setSortAlgo(new ShellSort<int>);
        list6.setSortAlgo(new HeapSort<int>);
        list.sort();
        list2.sort();
        list3.sort();
        list4.sort();
        list5.sort();
        list6.sort();
        for(int i = 0; i < size; i++) {
            DYNAMIC_SECTION(i) {
                REQUIRE(list[i] == list2[i]);

            }
        }
    }
}
TEST_CASE("Addresses") {
    SECTION("IPv4") {
        REQUIRE(IPv4() == IPv4(""));
        IPv4 a("192.168.1.1");
        IPv4 b("192.0.0.0");
        REQUIRE(a >= b);
        std::swap(a, b);
        REQUIRE(b >= a);
        REQUIRE(a.asString() == "192.0.0.0");
        REQUIRE(b.asString() == "192.168.1.1");
    }
    SECTION("IPv6") {
        REQUIRE(IPv6() == IPv6(""));
        IPv6 a("ffff:0:0:0:0:0:0:0");
        IPv6 b("2001:db8:11a3:9d7:1f34:8a2e:7a0:765d");
        REQUIRE(a >= b);
        std::swap(a, b);
        REQUIRE(b >= a);
        REQUIRE(a.asString() == "2001:db8:11a3:9d7:1f34:8a2e:7a0:765d");
        REQUIRE(b.asString() == "ffff:0:0:0:0:0:0:0");
    }
    SECTION("MAC") {
        REQUIRE(MAC() == MAC(""));
        IPv4 a("ff:a0:c9:14:c8:29");
        IPv4 b("00:a0:c9:14:c8:29");
        REQUIRE(a >= b);
        std::swap(a, b);
        REQUIRE(b >= a);
        REQUIRE(a.asString() == "00:a0:c9:14:c8:29");
        REQUIRE(b.asString() == "ff:a0:c9:14:c8:29");
    }
}
