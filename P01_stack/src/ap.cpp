// Julio Ivan Carrasco Armas
// 4º Ingenieria Informatica
// Universidad de La Laguna
// Complejidad de computacion
// alu0101110639@ull.edu.es

#include "../include/ap.h"

/**
 * @brief Construct a new Stack_machine::Stack_machine object
 *
 */
Stack_machine::Stack_machine(std::string filename) {
  valid_input_ = false;
  trailblaze_ = false;
  std::ifstream file(filename);
  std::string line;
  // will be used to store the name of the initial state, after all states have
  // their transitions configured it will be used
  std::string initial_state = "";
  int counter = 0;
  if (file.is_open()) {
    while (getline(file, line)) {
      if (line[0] != '#') {
        std::istringstream iss(line);
        std::string element;
        std::vector<std::string> elements;
        while (iss >> element) {
          elements.push_back(element);
        }
        switch (counter) {
          // state names
          case 0:
            for (const std::string& el : elements) {
              states_.emplace_back(State(el));
            }
            break;
          // input alphabet
          case 1:
            sigma_ = Alphabet(line);
            break;
          // stack alphabet
          case 2:
            tau_ = Alphabet(line);
            break;
          // initial state
          case 3:
            if (state_checker(line)) {
              initial_state = line;
            } else {
              std::cerr << "Undefined initial state: " << line << std::endl;
              exit(1);
            }
            break;
          // initial stack symbols
          case 4:
            if (tau_.checker(line)) {
              stack_memory_.push(line);
            } else {
              std::cerr << "Undefined initial stack symbol: " << line << std::endl;
              exit(1);
            }
            break;
          // transitions
          default:
            transition_manager(line);
            break;
        }
        counter++;
      }
    }
    for (auto it : states_) {
      if (it.get_name() == initial_state) {
        current_state_ = it;
      }
    }
  }
  file.close();
}

/**
 * @brief Changes current state to the one with the given name
 *
 * @param name string with the state name
 */
void Stack_machine::set_state(std::string name) {
  for (auto el : states_) {
    if (name == el.get_name()) {
      current_state_ = el;
    }
  }
}

/**
 * @brief Checks if the state with x name exists
 *
 * @param name string with the name of the state we want to check
 * @return true if the state with that name exists
 * @return false otherwise
 */
bool Stack_machine::state_checker(std::string name) {
  bool flag = false;
  for (auto el : states_) {
    if (name == el.get_name()) {
      flag = true;
    }
  }
  return flag;
}

/**
 * @brief Checks the transition to see if it's valid and adds them to the states
 *
 * @param input the transition to check
 */
void Stack_machine::transition_manager(std::string input) {
  std::istringstream iss(input);
  std::string element;
  std::vector<std::string> elements;
  int counter = 0;
  while (iss >> element) {
    elements.push_back(element);
  }
  int elem_size = elements.size();
  for (counter = 0; counter < elem_size; counter++) {
    switch (counter) {
      // initial state of the transition
      case 0:
        if (!state_checker(elements[counter])) {
          std::cerr << "Undefined initial state" << elements[counter]
                    << std::endl;
          exit(1);
        }
        break;
      // input
      case 1:
        if (!sigma_.checker(elements[counter])) {
          std::cerr << "Undefined input symbol" << elements[counter]
                    << std::endl;
          exit(1);
        }
        break;
      // stack input
      case 2:
        if (!tau_.checker(elements[counter])) {
          std::cerr << "Undefined stack symbol" << elements[counter]
                    << std::endl;
          exit(1);
        }
        break;
      // next state
      case 3:
        if (!state_checker(elements[counter])) {
          std::cerr << "Undefined next state" << elements[counter] << std::endl;
          exit(1);
        }
        break;
      // stack operation
      default:
        if (!tau_.checker(elements[counter])) {
          std::cerr << "Undefined stack symbol: " << elements[counter]
                    << std::endl;
          exit(1);
        }
        break;
    }
  }
  get_state(elements[0]).add_transition(input);
}

/**
 * @brief Returns a State element by the given name
 *
 * @param name string with the name of the State
 * @return State& element by reference
 */
State& Stack_machine::get_state(std::string name) {
  int size = states_.size();
  for (int i = 0; i < size; i++) {
    if (states_[i].get_name() == name) {
      return states_[i];
    }
  }
  std::cerr << "There is no state with the provided name" << std::endl;
  exit(1);
}

/**
 * @brief Returns the first symbol of the input string
 *
 * @return std::string that contains the first symbol of the string
 */
std::string Stack_machine::get_input_symbol() {
  std::string aux = "";
  if (!input_.empty()) {
    aux = input_.substr(0, 1);
  }
  return aux;
}

/**
 *
 * @brief Returns the top symbol of the stack
 *
 * @return std::string that contains the top symbol of the stack
 */
std::string Stack_machine::get_stack_top() { return stack_memory_.top(); }

/**
 * @brief Returns a pair with the current input and stack state
 *
 * @return std::pair<std::string, std::string> pair with the input and stack
 */
std::pair<std::string, std::string> Stack_machine::get_current_input() {
  return std::make_pair(get_input_symbol(), get_stack_top());
}

void Stack_machine::set_input(std::string input) { input_ = input; }

/**
 * @brief Public method to start the machine
 *
 */
void Stack_machine::start() {
  transition(input_, consumed_input_, current_state_, stack_memory_);
  write_path();
  if (valid_input_) {
    std::cout << "The string " << input_ << " is valid" << std::endl;
  } else {
    std::cout << "The string " << input_ << " is NOT valid" << std::endl;
  }
}

/**
 * @brief Recursive function that explores all the possible transitions until it
 * runs out of possibilities or finds that the input is valid
 *
 */
void Stack_machine::transition(std::string input, std::string consumed_input,
                               State& state, std::stack<std::string> stack) {
  // State before doing the transition

  // Checks if stack and input are both empty
  if (stack.top() == "." && stack.size() == 1 && input == ".") {
    valid_input_ = true;
    write_state(state.get_name(), input, consumed_input, stack);
    return;
  }

  if (stack.top() == "." && stack.size() > 1) {
    stack.pop();
  }
  std::vector<std::pair<std::string, std::vector<std::string>>>
      possible_transitions;
  possible_transitions = state.available_transitions(input, stack.top());
  // Iterates all possible transitions
  for (auto it : possible_transitions) {
    // Copies the stack and applies the outcome of the transition
    std::stack<std::string> aux_stack = stack;
    aux_stack.pop();
    int stack_elements_size = it.second.size();
    for (int i = 1; i < stack_elements_size; i++) {
      aux_stack.push(it.second[i]);
    }
    State aux_state = get_state(it.second[0]);
    // Different cases for epsilon transitions and normal ones
    if (it.first == ".") {
      transition(input, consumed_input, aux_state, aux_stack);
      // Writes the path in the way out
      if (valid_input_) {
        write_state(state.get_name(), input, consumed_input, stack);
        return;
      }
    } else {
      // Applies the transition outcome to the input string
      std::string aux_input = input.substr(1);
      std::string aux_consumed = consumed_input + input.substr(0, 1);
      if (aux_input.empty()) {
        aux_input = ".";
      }
      transition(aux_input, aux_consumed, aux_state, aux_stack);
      // Writes the path in the way out
      if (valid_input_) {
        write_state(state.get_name(), input, consumed_input, stack);
        return;
      }
    }
  }

  return;
}

/**
 * @brief Sets the flag to output in console the transitions that are being made
 *
 * @param mode 1 to activate the mode
 */
void Stack_machine::set_trail(std::string mode) {
  if (mode == "1") {
    trailblaze_ = true;
  }
}

/**
 * @brief Saves the current state of the machine to the trail path
 *
 */
void Stack_machine::write_state(std::string name, std::string input,
                                std::string consumed,
                                std::stack<std::string> stack) {
  std::string path = "";
  if (trailblaze_ && valid_input_) {
    path = name + " / " + input + " / " + consumed + " / ";
    while (!stack.empty()) {
      path += stack.top() + " ";
      stack.pop();
    }
    path += "\n";
    trail_path_.emplace_back(path);
  }
}

/**
 * @brief Writes in console the path the machine has taken to arrive to a valid
 * conclusion
 *
 */
void Stack_machine::write_path() {
  if (trailblaze_ && valid_input_) {
    std::cout << std::endl;
    std::cout << "Path taken: " << std::endl << std::endl;
    std::reverse(trail_path_.begin(), trail_path_.end());
    for (auto it : trail_path_) {
      std::cout << it;
    }
    std::cout << std::endl;
  }
}