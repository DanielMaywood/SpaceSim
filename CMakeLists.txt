# =============================
# SpaceSim
# Author: Daniel Maywood <daniel@maywood.me>
# =============================
cmake_minimum_required(VERSION 3.10.3)

project(SpaceSim)

# =============================
# Sfml
# =============================
set(SFML_STATIC_LIBRARIES TRUE)
set(BUILD_SHARED_LIBS FALSE)

add_subdirectory(Vendor/SFML)

# =============================
# Executable
# =============================
add_executable(SpaceSim
    "Source/Main.cpp"
    "Source/Body.cpp"
    "Source/Vector2.cpp"
    "Source/Position.cpp"
    "Source/SolarSystem.cpp"
    "Source/Velocity.cpp"
    "Source/Application.cpp" "Source/Settings.cpp")

# =============================
# Libraries
# =============================
target_link_libraries(SpaceSim
    PRIVATE
        sfml-graphics
)

# =============================
# Properties
# =============================
set_target_properties(SpaceSim
    PROPERTIES
        CXX_STANDARD 20
)
