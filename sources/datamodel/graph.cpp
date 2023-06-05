#include "graph.h"

void graph::init(const points2d& data)
{
  m_data = data;
  emit changed();
}
