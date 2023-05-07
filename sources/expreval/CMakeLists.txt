add_library(expreval SHARED  
  expreval.cpp
  expreval.h
  )

  target_link_libraries(expreval PRIVATE 
    Qt6::Core
)

