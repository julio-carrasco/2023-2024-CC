// Julio Ivan Carrasco Armas
// 4º Ingenieria Informatica
// Universidad de La Laguna
// Complejidad de computacion
// alu0101110639@ull.edu.es

#include "../include/state.h"

State::State() { name_ = "empty"; }

/**
 * @brief Construct a new State:: State object
 *
 * @param input string of the state names
 */
State::State(std::string input) {
  name_ = input;
}

/**
 * @brief adds transitions to the state
 *
 * @param input string containing all the information for the transition, it
 * follows this pattern: q1 a q2 A L/R
 */
void State::add_transition(std::string input) {
  std::istringstream iss(input);
  std::string element;
  std::vector<std::string> elements;
  std::string input_string = "";
  std::string next_state = "";
  std::string output_string = "";
  std::string movement = "";
  std::vector<std::string> temp;
  while (iss >> element) {
    elements.push_back(element);
  }
  // The transition function is always the same so we can hardcode it
  input_string = elements[1];
  next_state = elements[2];
  output_string = elements[3];
  movement = elements[4];
  temp.emplace_back(next_state);
  temp.emplace_back(output_string);
  temp.emplace_back(movement);

  transitions_.emplace(input_string, temp);
}

/**
 * @brief returns the name of the state
 *
 * @return std::string string with the name of the state
 */
std::string State::get_name() { return name_; }


/**
 * @brief adds the blank symbol to the state since the symbol can change
 * 
 * @param blank string with the blank symbol
 */
void State::add_blank(std::string blank) {
  blank_ = blank;
}

/**
 * @brief given the current state of the input and the stack returns the
 * available transitions
 *
 * @return std::vector<std::string>
 */
std::vector<std::pair<std::string, std::vector<std::string>>>
State::available_transitions(std::string input) {
  std::vector<std::pair<std::string, std::vector<std::string>>>
      possible_transitions;

  for (auto it = transitions_.begin(); it != transitions_.end(); it++) {
    if (it->first == input) {
      possible_transitions.emplace_back(std::make_pair(input, it->second));
    }
  }
  // Case to add empty transitions
  if (input != blank_) {
    std::string empty = blank_;
    for (auto it = transitions_.begin(); it != transitions_.end(); it++) {
      possible_transitions.emplace_back(std::make_pair(empty, it->second));
    }
  }
  return possible_transitions;
}