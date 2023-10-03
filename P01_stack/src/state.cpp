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
State::State(std::string input) { name_ = input; }

/**
 * @brief adds transitions to the state
 *
 * @param input string containing all the information for the transition, it
 * follows this pattern: q1 a? A q2 A*
 */
void State::add_transition(std::string input) {
  std::istringstream iss(input);
  std::string element;
  std::vector<std::string> elements;
  std::string input_string = "";
  std::string input_stack = "";
  std::vector<std::string> temp;
  int counter = 0;
  while (iss >> element) {
    elements.push_back(element);
  }
  for (counter = 0; counter < elements.size(); counter++) {
    switch (counter) {
      case 0:
        // We do nothing here as the starting state of the transition is of no
        // use here
        break;
      // input string
      case 1:
        input_string = elements[counter];
        break;
      // stack input
      case 2:
        input_stack = elements[counter];
        break;
      // next state and stack operation
      default:
        temp.emplace_back(elements[counter]);
        break;
    }
  }
  std::pair<std::string, std::string> aux =
      std::make_pair(input_string, input_stack);
  transitions_.emplace(aux, temp);
  for (const auto& entry : transitions_) {
    const auto& key = entry.first;
    const auto& value = entry.second;

    std::cout << "Key: (" << key.first << ", " << key.second << ")"
              << std::endl;
    std::cout << "Value: ";
    for (const std::string& nextState : value) {
      std::cout << nextState << " ";
    }
    std::cout << std::endl;
  }
}

/**
 * @brief returns the name of the state
 *
 * @return std::string string with the name of the state
 */
std::string State::get_name() { return name_; }

/**
 * @brief given the current state of the input and the stack returns the
 * available transitions
 *
 * @return std::vector<std::string>
 */
std::vector<std::string> State::available_transitions(std::string) {
  
}