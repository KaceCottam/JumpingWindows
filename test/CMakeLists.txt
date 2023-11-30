set(
    TEST_SOURCES
    pass.cpp
)

add_executable(JumpingWindows_Tests ${TEST_SOURCES})

target_link_libraries(JumpingWindows_Tests PRIVATE Catch2::Catch2WithMain)
set_property(TARGET JumpingWindows_Tests PROPERTY CXX_STANDARD 17)

catch_discover_tests(JumpingWindows_Tests)