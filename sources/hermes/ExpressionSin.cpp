#include "ExpressionSin.h"

#include <QtMath>

QString ExpressionSin::GetName() const
{
    return QString("Sine");
}

QPair<QVector<double>, QVector<double>> ExpressionSin::GetData() const {
    QPair<double, double> range_x(-9.0, 9.0); 

    QVector<double> x0(250), y0(250);
    double start  = range_x.first;
    double end    = range_x.second;
    double step   = (end - start) / 250;
    double curr   = start;
    for(auto idx = 0U; idx < 250; curr += step, idx++)
    {
        x0[idx] = curr;
        y0[idx] = qSin(curr);
    }

    return QPair<QVector<double>, QVector<double>>(x0, y0);
}


QColor ExpressionSin::GetColor() const 
{
    return QColor(Qt::blue);
}