#ifndef IEXPRESSION_H
#define IEXPRESSION_H

#include <QVector>
#include <QPair>
#include <QColor>

struct IExpression
{
    virtual ~IExpression() {}
    
    virtual QString GetName() const = 0;
    virtual QPair<QVector<double>, QVector<double>> GetData() const = 0;
    virtual QColor GetColor() const = 0;
};

#endif