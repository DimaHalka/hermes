#include <iostream>

#include <QString>

int main(int argc, char** argv) 
{
    QString qstr("Qt is available for hermes binary");
    std::cout << qstr.toStdString().c_str() << std::endl;
    return 0;
}