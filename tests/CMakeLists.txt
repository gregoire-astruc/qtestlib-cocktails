# Inspired by https://qt-project.org/wiki/Using_CMake_build_system
# and http://qt-project.org/quarterly/view/using_cmake_to_build_qt_projects
cmake_minimum_required(VERSION 2.6)
project(QTestLibCocktailsTests)
find_package(Qt4 REQUIRED)
set(QT_USE_QTTEST TRUE)

# Project files
set(SOURCES
    ../src/cocktail.cpp
)

set(MOC_HEADERS
    ../include/cocktail.h
)

set(TEST_SRCS
    src/tst_cocktailtest.cpp
)

include(${QT_USE_FILE})
add_definitions(${QT_DEFINITIONS})
include_directories(${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/.. include ../include ${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR}/src)

#QT4_WRAP_UI(UI_HEADERS ${UIS})
QT4_WRAP_CPP(MOC_SRCS ${MOC_HEADERS})
QT4_WRAP_CPP(MOC_TESTS ${TEST_SRCS})

add_executable(${PROJECT_NAME} ${SOURCES} ${MOC_SRCS} ${TEST_SRCS} ${MOC_TESTS})
target_link_libraries(${PROJECT_NAME} ${QT_LIBRARIES})
