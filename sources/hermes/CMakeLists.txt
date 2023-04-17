add_executable(hermes 
    main.cpp
    MainWindow.cpp
    MainWindow.h
    MainWindow.ui
    MainWindow.qrc
)

target_link_libraries(hermes PRIVATE 
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)