add_library(expreval SHARED  
  exports.h

  expreval.cpp
  expreval.h

  exprtk.hpp
)

target_include_directories(expreval  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR} 
    ${CMAKE_CURRENT_SOURCE_DIR}/..  # So that you can include <shared_lib/header.h> 
    ${CMAKE_CURRENT_BINARY_DIR}
)

target_link_libraries(expreval PRIVATE 
  Qt6::Core

  datamodel
)

if(WIN32)
  target_compile_options(expreval PRIVATE /bigobj)
  target_compile_definitions(expreval PRIVATE EXPR_EVAL_DLL)
  add_custom_command(TARGET expreval POST_BUILD
                     COMMAND ${WIN_DEPLOY_QT} --no-translations $<TARGET_FILE:expreval>)
endif(WIN32)

