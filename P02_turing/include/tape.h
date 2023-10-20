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
 *       implementation of class that describes the tape of a turing machine
 */

#pragma once


#include <iostream>
#include <string>
#include <vector>

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