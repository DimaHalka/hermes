#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>

#include "ui_MainWindow.h"

class MainWindow : public QMainWindow
  {
  Q_OBJECT

  public:
    MainWindow(QWidget *parent = 0);

  private:
    Ui_MainWindowClass ui;
  };

#endif // MAIN_WINDOW_H
