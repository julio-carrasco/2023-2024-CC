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

#pragma once

#include <vector>

class Fpr {
 private:
 public:
  static int function_calls_;
  Fpr();
  int zero(int);
  int successor(int);
  int sum(int, int);
  int equals(int, int);
  int multiply(int, int);
  int power(int, int);
  int projection(int, std::vector<int>);
};