cmake_minimum_required(VERSION 3.16)

# Note that headers are optional, and do not affect add_library, but they will not
# show up in IDEs unless they are listed in add_library.

# Optionally glob, but only for CMake 3.12 or later:
file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${CppDiagram_SOURCE_DIR}/src/*.hpp")
file(GLOB SOURCE_LIST CONFIGURE_DEPENDS "${CppDiagram_SOURCE_DIR}/src/*.cpp")
# Make an automatic library - will be static or dynamic based on user setting
add_library(cpp_diagram_lib ${SOURCE_LIST} ${HEADER_LIST})

# We need this directory, and users of our library will need it too
target_include_directories(cpp_diagram_lib PUBLIC ../src)

# This depends on wxWidgets
target_link_libraries(cpp_diagram_lib PRIVATE ${wxWidgets_LIBRARIES})

# All users of this library will need at least C++17
target_compile_features(cpp_diagram_lib PUBLIC cxx_std_17)

# Linker language
set_target_properties(cpp_diagram_lib PROPERTIES LINKER_LANGUAGE CXX)

