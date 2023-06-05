#pragma once

#ifndef EXPR_EVAL_DLL
  #define EXPR_EVAL_API __declspec(dllimport)
#else
  #define EXPR_EVAL_API __declspec(dllexport)
#endif

