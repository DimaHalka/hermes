#pragma once

#ifndef DATA_MODEL_DLL
  #define DATA_MODEL_API __declspec(dllimport)
#else
  #define DATA_MODEL_API __declspec(dllexport)
#endif

