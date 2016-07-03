cmake_minimum_required(VERSION 3.5)
project(Client_Mir)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
SET(BOOST_MANDATORY_COMPONENTS system serialization)

find_package(Boost COMPONENTS ${BOOST_MANDATORY_COMPONENTS} REQUIRED)
# add include path for boost to the compiler
include_directories(${Boost_INCLUDE_DIRS})


SET(EXEC_NAME "Client_Mir")

set(SOURCE_FILES main.cpp Book.h Book.cpp Borrow.cpp Borrow.h Commands.cpp Commands.h CommunicationManager.h CommunicationManager.cpp Member.h Member.cpp MessageParser.h MessageParser.cpp NetworkMessage.h NetworkMessage.cpp NetworkSettings.h NetworkSettings.cpp PureMessage.h PureMessage.cpp RequestResult.h RequestResult.cpp SyncTCPClient.h SyncTCPClient.cpp UIEntry.h UIEntry.cpp)

add_executable(${EXEC_NAME} ${SOURCE_FILES})
set_property(TARGET ${EXEC_NAME} PROPERTY CXX_STANDARD 11)
set_property(TARGET ${EXEC_NAME} PROPERTY CXX_STANDARD_REQUIRED true)
target_link_libraries(${EXEC_NAME} ${Boost_SYSTEM_LIBRARY})
target_link_libraries(${EXEC_NAME} ${Boost_SERIALIZATION_LIBRARY})
