#ifndef EXPRESSION_SIN_H
#define EXPRESSION_SIN_H

#include "IExpression.h"

struct ExpressionSin : public IExpression {
    virtual ~ExpressionSin() {}

    virtual QString GetName() const override;
    virtual QPair<QVector<double>, QVector<double>> GetData() const override;
    virtual QColor GetColor() const override;
};

#endif