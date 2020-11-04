cmake_minimum_required(VERSION 3.0)

project(re_match)

message(STATUS "Build type : ${CMAKE_BUILD_TYPE}")

# Configuration types
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)
if(DEFINED CMAKE_BUILD_TYPE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS  ${CMAKE_CONFIGURATION_TYPES})
endif()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# no note displayed
set(CMAKE_CXX_FLAGS "-Wfatal-errors")

set(CLASSIC_LIBS pthread ncurses rt)
set(SFML_LIBS sfml-audio sfml-graphics sfml-network sfml-system sfml-window)
set(INC_DIRS ../common include /usr/local/include)
set(LIB_DIRS /usr/local/lib)

include_directories(${INC_DIRS})
link_directories(${LIB_DIRS})
add_executable(${PROJECT_NAME} src/${PROJECT_NAME}.cpp)
#target_link_libraries(${PROJECT_NAME} ${CLASSIC_LIBS}) #${SFML_LIBS})
set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_RELEASE -s)
