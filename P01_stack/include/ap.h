// Julio Ivan Carrasco Armas
// 4º Ingenieria Informatica
// Universidad de La Laguna
// Complejidad de computacion
// alu0101110639@ull.edu.es

#pragma once

#include <fstream>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

#include "alphabet.h"
#include "state.h"

class Stack_machine {
 private:
  std::string input_;
  std::string consumed_input_;
  std::stack<std::string> stack_memory_;
  Alphabet sigma_;
  Alphabet tau_;
  std::vector<State> states_;
  State current_state_;

  void set_state(std::string);
  bool state_checker(std::string);
  State& get_state(std::string);
  void transition_manager(std::string);
  std::string get_input_symbol();
  std::string get_stack_top();
  void transition(std::string, std::string, State&, std::stack<std::string>);
  

 public:
  Stack_machine(std::string);
  void start();
  std::pair<std::string, std::string> get_current_input();
};