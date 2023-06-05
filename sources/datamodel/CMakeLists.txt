add_library(datamodel SHARED  
  exports.h

  graph.cpp
  graph.h
 )

target_link_libraries(datamodel PRIVATE 
  Qt6::Core
)

if(WIN32)
  target_compile_definitions(datamodel PRIVATE DATA_MODEL_DLL)
  add_custom_command(TARGET datamodel POST_BUILD
                     COMMAND ${WIN_DEPLOY_QT} --no-translations $<TARGET_FILE:datamodel>)
endif(WIN32)

