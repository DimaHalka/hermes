#pragma once

#include "exports.h"

#include <QPair>
#include <QVector>

DATA_MODEL_API typedef QPair<double, double> range_t;
DATA_MODEL_API typedef QPair<QVector<double>, QVector<double>> points2d;

struct DATA_MODEL_API graph {
  points2d m_data;
};
