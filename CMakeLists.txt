# Inspired by https://qt-project.org/wiki/Using_CMake_build_system
# and http://qt-project.org/quarterly/view/using_cmake_to_build_qt_projects
cmake_minimum_required(VERSION 2.6)
project(QTestLibCocktails)

option(BUILD_TESTS
    "Build tests files alongside main project"
    ON
)

if (BUILD_TESTS)
  set(QT_USE_QTTEST TRUE)
endif (BUILD_TESTS)

find_package(Qt4 REQUIRED)

# Project files
set(HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/cocktail.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/cocktailform.h
    ${CMAKE_CURRENT_SOURCE_DIR}/tests/test.h
)

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/cocktail.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/cocktailform.cpp
    ${HEADERS}
)


set(MOC_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/cocktail.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/cocktailform.h
)

set(UIS
    ${CMAKE_CURRENT_SOURCE_DIR}/ui/cocktailform.ui
)

include(${QT_USE_FILE})
add_definitions(${QT_DEFINITIONS})
include_directories(${CMAKE_SOURCE_DIR} include ${CMAKE_CURRENT_BINARY_DIR})

QT4_WRAP_UI(UI_HEADERS ${UIS})

add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp ${SOURCES} ${MOC_SRCS} ${UI_HEADERS})
set_target_properties(${PROJECT_NAME} PROPERTIES AUTOMOC TRUE)
target_link_libraries(${PROJECT_NAME} ${QT_LIBRARIES})

if (BUILD_TESTS)
  add_subdirectory(tests)
endif (BUILD_TESTS)
