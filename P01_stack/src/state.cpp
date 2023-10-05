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
  std::string next_state = "";
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
      // next state
      case 3: 
        next_state = elements[counter];
        break;
      default:
        temp.emplace_back(elements[counter]);
        break;
    }
  }
  // We reverse the vector to get the order of the stack symbols right
  temp.emplace_back(next_state);
  std::reverse(temp.begin(), temp.end());
  std::pair<std::string, std::string> aux =
      std::make_pair(input_string, input_stack);
  transitions_.emplace(aux, temp);
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
std::vector<std::pair<std::string, std::vector<std::string>>> State::available_transitions(
    std::string input, std::string stack_top) {

  std::vector<std::pair<std::string, std::vector<std::string>>> possible_transitions;
  std::pair<std::string, std::string> current_input =
      std::make_pair(input.substr(0,1), stack_top);

  
  for (auto it = transitions_.begin(); it != transitions_.end(); it++) {
    if(it->first == current_input) {
      possible_transitions.emplace_back(std::make_pair(current_input.first, it->second));
    }
  }
  // Case to add empty transitions
  if (current_input.first != ".") {
    std::pair<std::string, std::string> empty_transition =
        std::make_pair(".", stack_top);
    for (auto it = transitions_.equal_range(empty_transition);
         it.first != it.second; ++it.first) {
      possible_transitions.emplace_back(std::make_pair(empty_transition.first, it.first->second));
    }
  }

  /*
  for (auto transitions : possible_transitions) {
    std::cout << "Possible Transitions consuming " << transitions.first << ": ";
    for (auto it : transitions.second) {
      std::cout << it << " ";
    }
    std::cout << std::endl;
  }
  */
  return possible_transitions;
}