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
  std::string blank_;
  int head_;
  void edge_case();

  public:
  Tape();
  Tape(std::string);
  Tape(std::string, std::string);
  int get_head();
  void set_input(std::string);
  void move_head(std::string);
  void write_tape(std::string);
  std::string read_tape();
  std::string read_whole_tape();
};