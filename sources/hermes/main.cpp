#include <iostream>

#include "TriangleWindow.h"

#include <QGuiApplication>

// https://doc.qt.io/qt-6/qtopengl-openglwindow-example.html
int main(int argc, char** argv) 
{
    QGuiApplication app(argc, argv);

    QSurfaceFormat format;
    format.setSamples(16);

    TriangleWindow window;
    window.setFormat(format);
    window.resize(640, 480);
    window.show();

    window.setAnimating(true);

    return app.exec();
}

