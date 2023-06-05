#pragma once

#include "exports.h"
#include "types.h"

#include <QObject>

class DATA_MODEL_API graph : public QObject {
  Q_OBJECT

public:
  void init(const points2d& data);

signals:
  void changed();

private:
  points2d m_data;
};
