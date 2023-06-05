add_library(expreval SHARED  
  exports.h

  expreval.cpp
  expreval.h

  exprtk.hpp
 )

target_link_libraries(expreval PRIVATE 
  Qt6::Core
)

if(WIN32)
  target_compile_options(expreval PRIVATE /bigobj)
  target_compile_definitions(expreval PRIVATE EXPR_EVAL_DLL)
  add_custom_command(TARGET expreval POST_BUILD
                     COMMAND ${WIN_DEPLOY_QT} --no-translations $<TARGET_FILE:expreval>)
endif(WIN32)

