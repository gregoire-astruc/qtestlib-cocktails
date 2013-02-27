# Inspired by https://qt-project.org/wiki/Using_CMake_build_system
# and http://qt-project.org/quarterly/view/using_cmake_to_build_qt_projects
add_definitions(-DUSE_TESTS)

set(TEST_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/tst_cocktailtest.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/tst_cocktailformtest.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/tst_cocktailtest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/tst_cocktailformtest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)

include_directories(${CMAKE_BINARY_DIR}/tests ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(${PROJECT_NAME}Test ${SOURCES} ${MOC_SRCS} ${TEST_SRCS})
set_target_properties(${PROJECT_NAME}Test PROPERTIES AUTOMOC TRUE)
target_link_libraries(${PROJECT_NAME}Test ${QT_LIBRARIES})
