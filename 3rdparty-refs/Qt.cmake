if(APPLE)
  set(QT_HOME ~/Qt/6.5.0/macos)
elseif(WIN32)
  set(QT_HOME C:/DGalka/Coding/QT/6.5.0/msvc2019_64)
  set(WIN_DEPLOY_QT ${QT_HOME}/bin/windeployqt.exe)
endif()

list(APPEND CMAKE_PREFIX_PATH ${QT_HOME})

find_package(Qt6 REQUIRED COMPONENTS 
    Core 
    Gui
    OpenGL
    PrintSupport
    Widgets
) 

qt_standard_project_setup()