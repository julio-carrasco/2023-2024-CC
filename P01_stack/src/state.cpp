// Julio Ivan Carrasco Armas
// 4º Ingenieria Informatica
// Universidad de La Laguna
// Complejidad de computacion
// alu0101110639@ull.edu.es

#include "../include/state.h"

/**
 * @brief Construct a new State:: State object
 *
 * @param input string of the state names
 */
State::State(std::string input) { name_ = input; }

/**
 * @brief adds transitions to the state
 * 
 * @param input string containing all the information for the transition
 */
void State::add_transition(std::string input) {
  std::string name = input.substr(0, 3);
  std::string destination = input.substr(3);
  transitions_.emplace(name, destination);
}

/**
 * @brief given an input checks for the corresponding transition and gives back the corresponding information
 * 
 * @param input string with corresponding information of the string input and the stack
 * @return std::string string with the results of the transition
 */
std::string State::next_state(std::string input) {
  std::string name = input.substr(0, 3);
  auto it = transitions_.find(name);
  if(it == transitions_.end()) {
    return nullptr;
  } else {
    return it->second;
  }

}

/**
 * @brief returns the name of the state
 * 
 * @return std::string string with the name of the state
 */
std::string State::get_name() {
  return name_;
}