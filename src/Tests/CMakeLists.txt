project(Tests)

set(CMAKE_CXX_STANDARD 17)

set(SRC_LIST
        main.cpp
        test.cpp
        ../ConsoleInterface.cpp
        ../Address/Address.cpp
        ../Address/IPv4.cpp
        ../Address/IPv6.cpp
        ../Address/MAC.cpp
        ../Address/Parser/Parser.cpp
        ../Address/Parser/IPv4_Parser.cpp
        ../Address/Parser/IPv6_Parser.cpp
        ../Address/Parser/MAC_Parser.cpp
        ../Address/Subnet/Subnet.cpp
        ../Address/Subnet/IPv4_Subnet.cpp
        ../Address/Subnet/IPv6_Subnet.cpp
        ../Address/Subnet/MAC_Subnet.cpp

)

add_executable(${PROJECT_NAME} ${SRC_LIST})
target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBRARY_NAME})