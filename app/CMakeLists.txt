add_executable(CppDiagram CppDiagram.cpp)
target_compile_features(CppDiagram PRIVATE cxx_std_17)

target_link_libraries(CppDiagram PRIVATE cpp_diagram_lib)
