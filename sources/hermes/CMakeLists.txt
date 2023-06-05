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

    datamodel
    expreval
)

if(WIN32)
  add_custom_command(TARGET hermes POST_BUILD
                     COMMAND ${WIN_DEPLOY_QT} --no-translations $<TARGET_FILE:hermes>)
endif(WIN32)
