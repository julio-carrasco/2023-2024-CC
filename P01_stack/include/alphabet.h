// Julio Ivan Carrasco Armas
// 4º Ingenieria Informatica
// Universidad de La Laguna
// Complejidad de computacion
// alu0101110639@ull.edu.es

#pragma once

#include <set>

class Alphabet {
 private:
  std::set<std::string> alphabet_;

 public:
  Alphabet(const std::string);
  void insert(const std::string);
  bool checker(const std::string);
  int get_size() const;
};