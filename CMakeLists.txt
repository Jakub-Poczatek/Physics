cmake_minimum_required(VERSION 3.21)
project(Physics LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(Physics src/main.cpp)
target_link_libraries(Physics PRIVATE sfml-graphics Box2D)
target_compile_features(Physics PRIVATE cxx_std_17)
if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET Physics POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:Physics> $<TARGET_FILE_DIR:Physics> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS Physics)

# B2D - Box2D phyics library
add_subdirectory("lib/b2d/Box2D")
include_directories("lib/b2d/Box2D/")
set(B2D_INCS "lib/b2d/Box2D/")
link_directories("${CMAKE_BINARY_DIR}/lib/sfml/lib")





