add_executable(hermes 
    main.cpp
    OpenGLWindow.h
    OpenGLWindow.cpp
    TriangleWindow.h
    TriangleWindow.cpp
)

target_link_libraries(hermes PRIVATE 
    Qt6::Core
    Qt6::Gui
    Qt6::OpenGL
    Qt6::Widgets
)