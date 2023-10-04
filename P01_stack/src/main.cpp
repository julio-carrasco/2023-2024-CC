// Julio Ivan Carrasco Armas
// 4º Ingenieria Informatica
// Universidad de La Laguna
// Complejidad de computacion
// alu0101110639@ull.edu.es

#include <fstream>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#include "../include/ap.h"

int main(int argc, char *argv[]) {
  std::string filename = argv[1];
  Stack_machine ap(filename);
  ap.start();
  return 0;
}
