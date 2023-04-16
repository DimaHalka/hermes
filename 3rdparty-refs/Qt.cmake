list(APPEND CMAKE_PREFIX_PATH "~/Qt/6.5.0/macos")

find_package(Qt6 REQUIRED COMPONENTS 
    Core 
    Gui
    OpenGL
    Widgets
) 

qt_standard_project_setup()