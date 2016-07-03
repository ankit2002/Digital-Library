cmake_minimum_required(VERSION 3.5)
project(Server)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


SET(BOOST_MANDATORY_COMPONENTS system serialization)

find_package(Boost COMPONENTS ${BOOST_MANDATORY_COMPONENTS} REQUIRED)

# add include path for boost to the compiler
include_directories(${Boost_INCLUDE_DIRS})

set(EXEC_NAME "Server")

set(SOURCE_FILES main.cpp NetworkSetting.cpp NetworkSetting.h MessageParser.cpp MessageParser.h Book.h Book.cpp PureMessage.h PureMessage.cpp Member.h Member.cpp Borrow.h Borrow.cpp)

add_executable(${EXEC_NAME} ${SOURCE_FILES})
set_property(TARGET ${EXEC_NAME} PROPERTY CXX_STANDARD 11)
set_property(TARGET ${EXEC_NAME} PROPERTY CXX_STANDARD_REQUIRED true)
target_link_libraries(${EXEC_NAME} ${Boost_SYSTEM_LIBRARY})
target_link_libraries(${EXEC_NAME} ${Boost_SERIALIZATION_LIBRARY})