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
 *       implementation of class for an alphabet, a set of unique characters
 */

#pragma once

#include <iostream>
#include <set>
#include <sstream>

class Alphabet {
 private:
  std::set<std::string> alphabet_;

 public:
  Alphabet();
  Alphabet(const std::string);
  void insert(const std::string);
  bool checker(const std::string);
  int get_size() const;
};