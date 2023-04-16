add_executable(hermes main.cpp)

list(APPEND CMAKE_PREFIX_PATH "~/Qt/6.5.0/macos")
find_package(Qt6 REQUIRED COMPONENTS Core)
qt_standard_project_setup()

target_link_libraries(hermes PRIVATE Qt6::Core)