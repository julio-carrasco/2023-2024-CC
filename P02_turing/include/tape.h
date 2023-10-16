// Julio Ivan Carrasco Armas
// 4º Ingenieria Informatica
// Universidad de La Laguna
// Complejidad de computacion
// alu0101110639@ull.edu.es

// Class implements a turing machine tape

#pragma once


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Tape {
  private:
  std::vector<std::string> tape_;
  int head_;
  void edgeCase();

  public:
  Tape(std::string);
  int getHead();
  void moveHead(std::string);
  void writeTape(std::string);
  std::string readTape();
};