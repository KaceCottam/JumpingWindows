set(
    SOURCES
    main.cpp
)


add_executable(JumpingWindows ${SOURCES})

target_link_libraries(
        JumpingWindows 
        PRIVATE
        fmt::fmt-header-only
        sfml-system
        sfml-graphics
        sfml-window
        ImGui-SFML::ImGui-SFML)

set_property(TARGET JumpingWindows PROPERTY CXX_STANDARD 17)
