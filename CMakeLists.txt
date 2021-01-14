cmake_minimum_required(VERSION 3.2)

set(NAME_EXECUTABLE "bulk")
set(NAME_TEST "test_bulk")
set(PATHES headers/ interfaces/)
set(SRC_PATH "src/")

if(NOT DEFINED ENV{TRAVIS_BUILD_NUMBER})
    set(ENV{TRAVIS_BUILD_NUMBER} 1)
endif()

project(${NAME_EXECUTABLE} VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER}  LANGUAGES CXX)

#set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_DEBUG_RUNTIME OFF)
#set(Boost_DEBUG ON)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(${NAME_EXECUTABLE} ${SRC_PATH}main.cpp)

set(LIBRARIES commands printer factory logger handler model observ)

add_library(commands    ${SRC_PATH}Commands.cpp)
add_library(printer     ${SRC_PATH}ConsolePrinter.cpp)
add_library(factory     ${SRC_PATH}FactoryCommands.cpp)
add_library(logger      ${SRC_PATH}FileLoger.cpp)
add_library(handler     ${SRC_PATH}Handler.cpp)
add_library(model       ${SRC_PATH}ModelBulk.cpp)
add_library(observ      ${SRC_PATH}Observable.cpp)

target_include_directories(commands PRIVATE ${PATHES})
target_include_directories(factory PRIVATE ${PATHES})
target_include_directories(model PRIVATE ${PATHES})
target_include_directories(printer PRIVATE ${PATHES})
target_include_directories(logger PRIVATE ${PATHES})
target_include_directories(handler PRIVATE ${PATHES})
target_include_directories(observ PRIVATE ${PATHES})
target_include_directories(${NAME_EXECUTABLE} PRIVATE ${PATHES})

target_link_libraries(${NAME_EXECUTABLE} PRIVATE ${LIBRARIES})

add_executable(${NAME_TEST} ${SRC_PATH}test.cpp)

set_target_properties(${NAME_EXECUTABLE} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

set_target_properties(${NAME_TEST} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(${NAME_TEST} ${Boost_LIBRARIES} ${LIBRARIES})

target_include_directories(${NAME_TEST} PRIVATE ${PATHES})

if (MSVC)
    target_compile_options(${NAME_EXECUTABLE} PRIVATE /W4)
    target_compile_options(${NAME_TEST} PRIVATE /W4)
else()
    target_compile_options(${NAME_EXECUTABLE} PRIVATE -Wall -Wextra -pedantic -Werror)
    target_compile_options(${NAME_TEST} PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

install(TARGETS ${NAME_EXECUTABLE} RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT azbyx@inbox.ru)

include(CPack)

enable_testing()

add_test(${NAME_TEST} ${NAME_TEST})
