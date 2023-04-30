#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
  ui.setupUi(this);

  auto *customPlot = ui.customPlot;

  QCPRange range_x(-9.0, 9.0);
  QCPRange range_y(-2.0, 2.0);
  
  customPlot->legend->setVisible(true);
  customPlot->legend->setFont(QFont("Helvetica", 9));
  customPlot->xAxis->setRange(range_x);
  customPlot->yAxis->setRange(range_y);
  customPlot->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));
  
  QSharedPointer<QCPAxisTickerPi> piTicker(new QCPAxisTickerPi);
  customPlot->xAxis->setTicker(piTicker);

  QPen pen;
  pen.setStyle(Qt::SolidLine); // Qt::DashLine
  pen.setWidth(2);
  pen.setColor(Qt::red);

  QVector<double> x0(250), y0(250);
  double start  = range_x.lower;
  double end  = range_x.upper;
  double step = (end - start) / 250;
  auto idx = 0U;
  for(auto curr = start; curr < end; curr += step, idx++)
  {
    x0[idx] = curr;
    y0[idx] = qSin(curr);
  }

  customPlot->addGraph();
  customPlot->graph(0)->setPen(pen);
  customPlot->graph(0)->setName("Sine");
  customPlot->graph(0)->setData(x0, y0);
  customPlot->replot();

  setWindowTitle("hermes");
}
