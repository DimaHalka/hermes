#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>

#include <expreval/expreval.h>

#include "ui_MainWindow.h"

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = 0);

private:
  Ui_MainWindowClass ui;
  
  void plot(const QString& name, const points2d& pts); 

private slots:
  void onAdd();
};

#endif // MAIN_WINDOW_H
