cmake_minimum_required(VERSION "3.9.1")

set(This ExampleTests)

set(Sources
    ExampleTests.cpp
)

add_executable(${This} ${Sources})
#dependencies
target_link_libraries(${This} PUBLIC
    gtest_main
    Example
)

#tell cmake this program is unit test
#remember to set gtest_force_shared_crt:BOOL=ON in cache
add_test(
    NAME ${This}
    COMMAND ${This}
)