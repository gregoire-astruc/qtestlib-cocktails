# Inspired by https://qt-project.org/wiki/Using_CMake_build_system
# and http://qt-project.org/quarterly/view/using_cmake_to_build_qt_projects
add_definitions(-DUSE_TESTS)

# List of tested classes.
set(Testees
    Cocktail
    CocktailForm
)

# Classnames in lowercase
string(TOLOWER "${Testees}" TesteesLower)

# C++ line to run a test class
set(runTests "    status |= runTests<\\1Test>(argc, argv);\n")

# Include line
set(includeTest "\#include \"tst_\\1test.h\"\n")


# List of filenames included in the test executable build
string(REGEX REPLACE "([^;]+)(;|$)"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/tst_\\1test.h;${CMAKE_CURRENT_SOURCE_DIR}/src/tst_\\1test.cpp\\2"
    TestFiles "${TesteesLower}"
)

# ... with the configured main class
LIST(APPEND TestFiles "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")

# Creates includes.
string(REGEX REPLACE "([^;]+)(;|$)" "${includeTest}" TEST_INCLUDES "${TesteesLower}")

# Generates runner lines.
string(REGEX REPLACE "([^;]+)(;|$)" "${runTests}" TEST_RUNNERS "${Testees}")

# Configure the main build class
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp.in ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

include_directories(${CMAKE_BINARY_DIR}/tests ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(${PROJECT_NAME}Test ${SOURCES} ${MOC_SRCS} ${TestFiles})
set_target_properties(${PROJECT_NAME}Test PROPERTIES AUTOMOC TRUE)
target_link_libraries(${PROJECT_NAME}Test ${QT_LIBRARIES})
