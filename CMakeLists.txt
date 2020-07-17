cmake_minimum_required(VERSION 3.16)

project(CppDiagram)

find_package(wxWidgets REQUIRED core base)
include(${wxWidgets_USE_FILE})
include_directories(${wxWidgets_INCLUDE_DIRS})

# Only do these if this is the main project, and not if it is included through add_subdirectory
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    # Let's ensure -std=c++xx instead of -std=g++xx
    set(CMAKE_CXX_EXTENSIONS OFF)

    # Let's nicely support folders in IDEs
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)

    # Docs only available if this is the main app
    #find_package(Doxygen)
    #if(Doxygen_FOUND)
    #    add_subdirectory(docs)
    #else()
    #    message(STATUS "Doxygen not found, not building docs")
    #endif()
endif()

add_library(sources "")

#source code directory
add_subdirectory(src)

#binary files directory
add_subdirectory(bin)
#add_subdirectory(include)
