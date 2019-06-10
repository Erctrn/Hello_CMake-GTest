#boilerplate 
#you can check version# when you open the gui
cmake_minimum_required(VERSION "3.9.1")

#optional variable
set(This Example)

#gives project a name
project(${This} C CXX)

#set variables for language versions
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

#for unit tests
enable_testing()

add_subdirectory(googletest)

set(Headers
    Example.h
)

set(Sources
    Example.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})

#add_subdir goes into the subdir to look for the next cmakelists
#and runs as a child node
add_subdirectory(test)


#PROJECT_NAME variable set = to whatever is inside project(), to get that value, dereference by using ${}
#creates executable target requiring 2 params (name of executable, source code required to build executable)
#add_executable("${PROJECT_NAME}" "Main.cpp")

#for installtions
#install target in bin
#install(TARGETS "${PROJECT_NAME}" DESTINATION bin) #${CMAKE_INSTALL_PREFIX}/bin
#install files Main.cpp in src
#install(FILES "Main.cpp" DESTINATION src) #${CMAKE_INSTALL_PREFIX}/src


#include(CTest)
#params(name of test, executable you want to run test on)
#a test passes when it passes a 0 value, fails if anything else
#add_test("test1" "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}") #points to build dir/filename

#CDash information
#Experimental build does not interact with version control software
#Continuous build attempts to update project to match online repo
#Nightly attempts to update project to match online repo at a specific time
#You can mess with the Nightly build's options in ctestconfig.cmake

#Installs packaging in a temp location and compresses package into a zip and/or 7z file
#NSIS packager gives you an interface for installing the contents instead
#include(CPack)

