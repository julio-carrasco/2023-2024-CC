// Julio Ivan Carrasco Armas
// 4º Ingenieria Informatica
// Universidad de La Laguna
// Complejidad de computacion
// alu0101110639@ull.edu.es

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>

class State {
 private:
  std::string name_;
  std::map<std::string, std::string> transitions_;

 public:
  State(std::string);
  void add_transition(std::string);
  std::string next_state(std::string);
  std::string get_name();
};