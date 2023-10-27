/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 *
 *

 * @author Julio Carrasco Armas
 *  alu0101110639@ull.edu.es
 *
 * @desc FPR
 *       a class that implements a few recursive primitive functions
 */

#include "../include/fpr.h"

Fpr::Fpr() { function_calls_ = 0; }


/**
 * @brief power function implemented in a recursive primitive way
 * 
 * @param x base
 * @param y exponent
 * @return int 
 */
int Fpr::power(int x, int y) {
  function_calls_++;
  if (y == 0) {
    return projection(1, {successor(zero(x))});
  } else {
    return projection(3, {x, y, multiply(x, power(x, y - 1))});
  }
}

/**
 * @brief multiply function implemented in a primitive recursive way
 * 
 * @param x 
 * @param y 
 * @return int 
 */
int Fpr::multiply(int x, int y) {
  function_calls_++;
  if (y == 0) {
    return projection(3, {x, y, zero(x)});
  } else {
    return projection(3, {x, y, sum(x, multiply(x, y - 1))});
  }
}

/**
 * @brief sum function implemented in a primitive recursive way
 * 
 * @param x 
 * @param y 
 * @return int 
 */
int Fpr::sum(int x, int y) {
  function_calls_++;
  if (y == 0) {
    return projection(1, {x}); 
  } else {
    return projection(1, {sum(successor(x), y - 1)});
  }
}

/**
 * @brief succesor function, gives the next number
 * 
 * @param x 
 * @return int 
 */
int Fpr::successor(int x) {
  function_calls_++;
  return projection(2, {x, x + 1});
}

/**
 * @brief zero function, returns 0
 * 
 * @return int 
 */
int Fpr::zero(int x) {
  function_calls_++;
  return projection(1, {0});
}

/**
 * @brief projection function, 
 * 
 * @param index 
 * @param vec 
 * @return int 
 */
int Fpr::projection(int index, std::vector<int> vec) {
  function_calls_++;
  for(int i = 0; i < vec.size(); i++) {
    if(i == index - 1) {
      return vec[i];
    }
  }
}