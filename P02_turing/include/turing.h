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
 * @desc Turing
 *       implementation of class that describes a turing machine
 */

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
  bool written_tape_;
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

 public:
  Turing_machine(std::string);
  void start();
  void set_input(std::string);
  std::pair<std::string, std::string> get_current_input();
  void reset_machine();
};