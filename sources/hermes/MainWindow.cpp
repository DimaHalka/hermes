#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
  ui.setupUi(this);

  QCustomPlot *customPlot = ui.customPlot;

  QCPRange range_x(-9.0, 9.0);
  QCPRange range_y(-2.0, 2.0);

  customPlot->legend->setVisible(true);
  customPlot->legend->setFont(QFont("Helvetica", 9));
  customPlot->xAxis->setRange(range_x);
  customPlot->yAxis->setRange(range_y);
  customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
  customPlot->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));

  QSharedPointer<QCPAxisTickerPi> piTicker(new QCPAxisTickerPi);
  customPlot->xAxis->setTicker(piTicker);

  connect(ui.btnAdd, SIGNAL(pressed()), this, SLOT(onAdd()));
  connect(ui.lineEdit, SIGNAL(returnPressed()), this, SLOT(onAdd()));

  setWindowTitle("");
}

void MainWindow::plot(const QString& name, const points2d &pts)
{
  QCustomPlot *customPlot = ui.customPlot;

  QPen pen;
  pen.setStyle(Qt::SolidLine);
  pen.setWidth(2);
  pen.setColor(Qt::black);

  auto p_graph = customPlot->addGraph();
  p_graph->setPen(pen);
  p_graph->setName(name);
  p_graph->setData(pts.first, pts.second);

  customPlot->replot();
}

void MainWindow::onAdd()
{
  QString txt = ui.lineEdit->text();
  if (txt.isEmpty())
    return;

  plot(txt, eval(txt.toStdString(), {-9.0, 9.0}, 250));

  QListWidget *listPlots = ui.listPlots;
  listPlots->addItem(txt);
  QListWidgetItem *item = listPlots->item(listPlots->count() - 1);
  item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
  item->setCheckState(Qt::Checked);
}
