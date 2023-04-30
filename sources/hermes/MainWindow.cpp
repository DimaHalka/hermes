#include "MainWindow.h"

#include "ExpressionSin.h"
#include "ExpressionCos.h"

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

  auto plot = [customPlot](const IExpression& expression){
    QPen pen;
    pen.setStyle(Qt::SolidLine); 
    pen.setWidth(2); 
    pen.setColor(expression.GetColor());

    const auto& data = expression.GetData();

    auto p_graph = customPlot->addGraph();
    p_graph->setPen(pen);
    p_graph->setName(expression.GetName());
    p_graph->setData(data.first, data.second);
  };

  plot(ExpressionSin());
  plot(ExpressionCos());

  /*
  auto esin = ExpressionSin()
  auto data = esin.GetData();
  QPen pen0;
  pen0.setStyle(Qt::SolidLine); // Qt::DashLine
  pen0.setWidth(2); 
  pen0.setColor(esin.GetColor());
  customPlot->addGraph();
  customPlot->graph(0)->setPen(pen0);
  customPlot->graph(0)->setName("Sine");
  customPlot->graph(0)->setData(data.first, data.second);

  auto ecos = ExpressionCos().GetData();
  auto data = ecos.GetData();
  QPen pen1;
  pen1.setStyle(Qt::SolidLine); // Qt::DashLine
  pen1.setWidth(2); 
  pen1.setColor(ecos.GetColor());
  customPlot->addGraph();
  customPlot->graph(1)->setPen(pen1);
  customPlot->graph(1)->setName("Cosine");
  customPlot->graph(1)->setData(data1.first, data.second);
  */

  customPlot->replot();

  setWindowTitle("");
}
