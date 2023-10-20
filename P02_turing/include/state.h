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
 *       implementation of class that describes a state of a finite state machine with transitions
 */

#pragma once

#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

class State {
 private:
  std::string name_;
  std::string blank_;
  // transitions are stored in a map in the following way: the key is the inpunt
  // symbol , the value associated is a vector of strings containing 3 elements,
  // the next state, what to write and how to move
  std::multimap<std::string, std::vector<std::string>> transitions_;

 public:
  State();
  State(std::string);
  void add_transition(std::string);
  void add_blank(std::string);
  std::vector<std::pair<std::string, std::vector<std::string>>> available_transitions(std::string);
  std::string get_name();
};