#ifndef EXPRESSION_GENERIC_H
#define EXPRESSION_GENERIC_H

#include "IExpression.h"

struct ExpressionGeneric : public IExpression {
    virtual ~ExpressionGeneric() {}

    virtual QString GetName() const override;
    virtual QPair<QVector<double>, QVector<double>> GetData() const override;
    virtual QColor GetColor() const override;
};

#endif