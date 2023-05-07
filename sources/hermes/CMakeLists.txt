add_executable(hermes 
    main.cpp
    
    QCustomPlot.h
    QCustomPlot.cpp

    MainWindow.cpp
    MainWindow.h
    MainWindow.ui
    MainWindow.qrc
)

target_include_directories(hermes PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR} 
    ${CMAKE_CURRENT_SOURCE_DIR}/..  # So that you can include <shared_lib/header.h> 
    ${CMAKE_CURRENT_BINARY_DIR}
)

target_link_libraries(hermes PRIVATE 
    Qt6::Core
    Qt6::Gui
    Qt6::PrintSupport
    Qt6::Widgets
    expreval
)