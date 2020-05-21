project(Tests)

set(CMAKE_CXX_STANDARD 17)

set(SRC_LIST
        main.cpp
        test.cpp
        ../src/ConsoleInterface.cpp
        ../src/Address/Address.cpp
        ../src/Address/IPv4.cpp
        ../src/Address/IPv6.cpp
        ../src/Address/MAC.cpp
        ../src/Address/Parser/Parser.cpp
        ../src/Address/Parser/IPv4_Parser.cpp
        ../src/Address/Parser/IPv6_Parser.cpp
        ../src/Address/Parser/MAC_Parser.cpp
        ../src/Address/Subnet/Subnet.cpp
        ../src/Address/Subnet/IPv4_Subnet.cpp
        ../src/Address/Subnet/IPv6_Subnet.cpp
        ../src/Address/Subnet/MAC_Subnet.cpp

)

add_executable(${PROJECT_NAME} ${SRC_LIST})
target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBRARY_NAME})