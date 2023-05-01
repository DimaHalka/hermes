#include "ExpressionGeneric.h"

#include <string>

#include "exprtk.hpp"

QString ExpressionGeneric::GetName() const
{
    return QString("Generic");
}

QPair<QVector<double>, QVector<double>> ExpressionGeneric::GetData() const {
    std::string expression_string = "sin(2x) + 1";

    typedef exprtk::symbol_table<double> symbol_table_t;
    typedef exprtk::expression<double>   expression_t;
    typedef exprtk::parser<double>       parser_t;

    double x;

    symbol_table_t symbol_table;
    symbol_table.add_variable("x", x);
    symbol_table.add_constants();

    expression_t expression;
    expression.register_symbol_table(symbol_table);

    parser_t parser;
    parser.compile(expression_string,expression);

    QPair<double, double> range_x(-9.0, 9.0); 

    QVector<double> x0(250), y0(250);
    double start  = range_x.first;
    double end    = range_x.second;
    double step   = (end - start) / 250;
    x = start;
    for(auto idx = 0U; idx < 250; x += step, idx++)
    {
        auto y = expression.value();
        x0[idx] = x;
        y0[idx] = y;
    }

    return QPair<QVector<double>, QVector<double>>(x0, y0);
}


QColor ExpressionGeneric::GetColor() const 
{
    return QColor(Qt::black);
}