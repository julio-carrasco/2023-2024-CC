// Julio Ivan Carrasco Armas
// 4º Ingenieria Informatica
// Universidad de La Laguna
// Complejidad de computacion
// alu0101110639@ull.edu.es

#pragma once

#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

class State {
 private:
  std::string name_;
  // transitions are stored in a map in the following way: the key is a pair of
  // the input and stack values, the value associated is a vector of strings
  // containing 2 elements, the next state and the new stack value
  std::multimap<std::pair<std::string, std::string>, std::vector<std::string>>
      transitions_;

 public:
  State();
  State(std::string);
  void add_transition(std::string);
  std::vector<std::pair<std::string, std::vector<std::string>>> available_transitions(std::string, std::string);
  std::string get_name();
};