# Inspired by https://qt-project.org/wiki/Using_CMake_build_system
# and http://qt-project.org/quarterly/view/using_cmake_to_build_qt_projects
cmake_minimum_required(VERSION 2.6)
project(QTestLibCocktails)
find_package(Qt4 REQUIRED)

# Project files
set(SOURCES
)

set(HEADERS
    include/test.h
)

set(MOC_HEADERS
)

set(UIS
)

include(${QT_USE_FILE})
add_definitions(${QT_DEFINITIONS})
include_directories(${CMAKE_SOURCE_DIR} include ${CMAKE_CURRENT_BINARY_DIR})

QT4_WRAP_UI(UI_HEADERS ${UIS})
QT4_WRAP_CPP(MOC_SRCS ${MOC_HEADERS})

add_executable(${PROJECT_NAME} ${SOURCES} ${MOC_SRCS} ${UI_HEADERS})
target_link_libraries(${PROJECT_NAME} ${QT_LIBRARIES})
