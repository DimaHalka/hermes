#ifndef EXPRESSION_COS_H
#define EXPRESSION_COS_H

#include "IExpression.h"

struct ExpressionCos : public IExpression {
    virtual ~ExpressionCos() {}

    virtual QString GetName() const override;
    virtual QPair<QVector<double>, QVector<double>> GetData() const override;
    virtual QColor GetColor() const override;
};
#endif