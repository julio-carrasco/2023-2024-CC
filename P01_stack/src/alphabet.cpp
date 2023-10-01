// Julio Ivan Carrasco Armas
// 4º Ingenieria Informatica
// Universidad de La Laguna
// Complejidad de computacion
// alu0101110639@ull.edu.es

#include "../include/alphabet.h"

/**
 * @brief Construct a new Alphabet:: Alphabet object
 * 
 * @param input string with all the characters of the alphabet
 */
Alphabet::Alphabet(std::string input) {
  int size = input.size();
  std::string aux;
  for (int i = 0; i < size; i++) {
    aux = input[i];
    if (aux != " ") {
      alphabet_.insert(aux);
    }
  }
  std::string empty_string = ".";
  alphabet_.insert(empty_string);
}

/**
 * @brief inserts a character in our alphabet
 * 
 * @param character 
 */
void Alphabet::insert(std::string character) { alphabet_.insert(character); }

/**
 * @brief checks wether the given character is part of our alphabet
 * 
 * @param character a string with whatever we want to check
 * @return true if character is in the set of our alphabet
 * @return false in other case
 */
bool Alphabet::checker(std::string character) {
  bool flag = false;
  if(alphabet_.find(character) != alphabet_.end()) {
    flag = true;
  }
  return flag;
}
