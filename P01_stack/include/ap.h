// Julio Ivan Carrasco Armas
// 4º Ingenieria Informatica
// Universidad de La Laguna
// Complejidad de computacion
// alu0101110639@ull.edu.es

#pragma once

#include <iostream>
#include <stack>
#include <string>
#include <vector>

#include "alphabet.h"
#include "state.h"

class Stack_machine {
 private:
  std::stack<std::string> stack_memory_;
  Alphabet sigma_;
  Alphabet tau_;
  std::vector<State> states_;
  State current_state_;

  public:
  Stack_machine();
  void transition(std::string);
};