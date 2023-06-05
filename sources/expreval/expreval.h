#pragma once

#include "exports.h"

#include <datamodel/types.h>

EXPR_EVAL_API
points2d eval(
    const std::string &expression_string, // sin(3x) + 1
    const range_t &range_x,               // -9.0 ... 9.0
    size_t samples = 250                  // number of points in the output containers, defines accuracy
);
