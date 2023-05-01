#include "MainWindow.h"

#include "ExpressionSin.h"
#include "ExpressionCos.h"
#include "ExpressionGeneric.h"

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
  plot(ExpressionGeneric());

  customPlot->replot();

  setWindowTitle("");
}
