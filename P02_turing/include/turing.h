// Julio Ivan Carrasco Armas
// 4º Ingenieria Informatica
// Universidad de La Laguna
// Complejidad de computacion
// alu0101110639@ull.edu.es

// Class implements a turing machine

#pragma once

#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

#include "alphabet.h"
#include "state.h"
#include "tape.h"

class Turing_machine {
 private:
  Tape tape_;
  bool valid_input_;
  Alphabet sigma_;
  Alphabet tau_;
  std::vector<State> states_;
  State current_state_;
  std::vector<std::string> end_states_;
  std::set<std::string> movements_;

  void set_state(std::string);
  bool state_checker(std::string);
  State& get_state(std::string);
  void transition_manager(std::string);
  void transition(Tape, State&);
  void write_status();

 public:
  Turing_machine(std::string);
  void start();
  void set_input(std::string);
  std::pair<std::string, std::string> get_current_input();
};