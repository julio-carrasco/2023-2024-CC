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

#include <iostream>

#include "../include/fpr.h"

int Fpr::function_calls_ = 0;

int main() {
  std::cout << "Input two numbers for the operation x^y" << std::endl;
  int x, y;
  std::cin >> x >> y;
  Fpr temp;
  std::cout << "Result: " << temp.power(x, y) << std::endl;
  std::cout << "Recursive calls: " << Fpr::function_calls_ << std::endl;
}
