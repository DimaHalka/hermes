#include "MainWindow.h"

#include <QtWidgets/QApplication>

int main(int argc, char** argv) 
{
    QApplication a(argc, argv);
    MainWindow wnd;
    wnd.show();
    return a.exec();
}

