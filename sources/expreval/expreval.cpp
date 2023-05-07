#include "expreval.h"
#include "exprtk.hpp"

points2d eval(const std::string &expression_string,
              const range_t &range_x,
              size_t samples /* 250 */)
{
    typedef exprtk::symbol_table<double> symbol_table_t;
    typedef exprtk::expression<double> expression_t;
    typedef exprtk::parser<double> parser_t;

    double x;

    parser_t parser;
    expression_t expression;
    symbol_table_t symbol_table;
    symbol_table.add_variable("x", x);
    symbol_table.add_constants();
    expression.register_symbol_table(symbol_table);
    parser.compile(expression_string, expression);

    QVector<double> xs(samples), ys(samples);

    double start = range_x.first;
    double end = range_x.second;
    double step = (end - start) / samples;
    x = start;
    for (auto idx = 0U; idx < samples; x += step, idx++)
    {
        xs[idx] = x;
        ys[idx] = expression.value();
    }

    return {xs, ys};
}
