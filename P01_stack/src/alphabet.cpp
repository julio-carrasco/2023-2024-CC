// Julio Ivan Carrasco Armas
// 4º Ingenieria Informatica
// Universidad de La Laguna
// Complejidad de computacion
// alu0101110639@ull.edu.es

#include "../include/alphabet.h"

Alphabet::Alphabet() {
  std::string empty_string = ".";
  alphabet_.insert(empty_string);
}

/**
 * @brief Construct a new Alphabet:: Alphabet object
 *
 * @param input string with all the characters of the alphabet
 */
Alphabet::Alphabet(std::string input) {
  std::istringstream iss(input);
  std::string element;
  while (iss >> element) {
    alphabet_.insert(element);
  }
  std::string empty_string = ".";
  alphabet_.insert(empty_string);
  std::cout << "Alphabet elements: " << std::endl;
  for (auto it: alphabet_) {
    std::cout << it << " ";
  }
  std::cout << std::endl;
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
  if (alphabet_.find(character) != alphabet_.end()) {
    flag = true;
  }
  return flag;
}

/**
 * @brief returns size of the alphabet
 *
 * @return int size of alphabet
 */
int Alphabet::get_size() const { return alphabet_.size(); }