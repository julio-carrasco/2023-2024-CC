/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Complejidad Computacional
 * 
 * 
 *
 * @author Julio Carrasco Armas
 *  alu0101110639@ull.edu.es
 * 
 * @desc Turing
 *       implementation of class of a turing machine
 */

#include "../include/turing.h"

/**
 * @brief Construct a new Turing_machine::Turing_machine object
 *
 */
Turing_machine::Turing_machine(std::string filename) {
  valid_input_ = false;
  written_tape_ = false;
  std::ifstream file(filename);
  std::string line;
  // will be used to store the name of the initial state, after all states have
  // their transitions configured it will be used
  std::string initial_state = "";
  std::string blank_symbol = "";
  movements_.insert("L");
  movements_.insert("R");
  movements_.insert("S");
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
          // machine alphabet
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
          // blank symbol
          case 4:
            blank_symbol = line;
            tape_ = Tape(blank_symbol);
            break;
          // final states
          case 5:
            for (const std::string& el : elements) {
              if (state_checker(el)) {
                end_states_.emplace_back(el);
              } else {
                std::cerr << "Undefined final state: " << line << std::endl;
                exit(1);
              }
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
    if (!tau_.checker(blank_symbol)) {
      std::cerr << "Undefined blank symbol: " << blank_symbol << std::endl;
      exit(1);
    }
    for (auto it : states_) {
      it.add_blank(blank_symbol);
      if (it.get_name() == initial_state) {
        current_state_ = it;
      }
    }
  } else {
    std::cerr << "File does not exist: " << filename << std::endl;
    exit(1);
  }
  file.close();
}

/**
 * @brief Changes current state to the one with the given name
 *
 * @param name string with the state name
 */
void Turing_machine::set_state(std::string name) {
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
bool Turing_machine::state_checker(std::string name) {
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
void Turing_machine::transition_manager(std::string input) {
  std::istringstream iss(input);
  std::string element;
  std::vector<std::string> elements;
  int counter = 0;
  while (iss >> element) {
    elements.push_back(element);
  }
  int elem_size = elements.size();
  if (!state_checker(elements[0])) {
    std::cerr << "Undefined initial state: " << elements[0] << std::endl;
    exit(1);
  }
  if (!sigma_.checker(elements[1]) && !tau_.checker(elements[1])) {
    std::cerr << "Undefined input symbol: " << elements[1] << std::endl;
    exit(1);
  }
  if (!state_checker(elements[2])) {
    std::cerr << "Undefined next state: " << elements[2] << std::endl;
    exit(1);
  }
  if (!tau_.checker(elements[3])) {
    std::cerr << "Undefined output symbol: " << elements[3] << std::endl;
    exit(1);
  }
  if (movements_.find(elements[4]) == movements_.end()) {
    std::cerr << "Undefined movement: " << elements[4] << std::endl;
    exit(1);
  }
  get_state(elements[0]).add_transition(input);
}

/**
 * @brief Returns a State element by the given name
 *
 * @param name string with the name of the State
 * @return State& element by reference
 */
State& Turing_machine::get_state(std::string name) {
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
 * @brief Public method to start the machine
 *
 */
void Turing_machine::start() {
  Tape temp = tape_;
  transition(tape_, current_state_);
  if (valid_input_) {
    std::cout << "The string " << tape_.read_whole_tape() << " is valid"
              << std::endl;
  } else {
    std::cout << "The string " << tape_.read_whole_tape() << " is NOT valid"
              << std::endl;
  }
  reset_machine();
  tape_ = temp;
}

/**
 * @brief Recursive function that explores all the possible transitions until it
 * runs out of possibilities or finds that the input is valid
 *
 */
void Turing_machine::transition(Tape tape, State& state) {
  // Checks possible transitions
  std::vector<std::pair<std::string, std::vector<std::string>>>
      possible_transitions = state.available_transitions(tape.read_tape());
  // Checks if current state is an end state
  bool end_state = false;
  for (auto it : end_states_) {
    if (state.get_name() == it) {
      end_state = true;
    }
  }
  // If we are in an end state and there are no available transitions we finish
  // also records end state of tape
  if (possible_transitions.size() == 0 && end_state && !written_tape_) {
    valid_input_ = true;
    written_tape_ = true;
    tape_.set_input(tape.read_whole_tape());
    return;
  }

  // Iterates all possible transitions
  for (auto it : possible_transitions) {
    // We get the next state, then we write to the tape and then we move the
    // head, finally we call the function again
    State aux_state = get_state(it.second[0]);
    tape.write_tape(it.second[1]);
    tape.move_head(it.second[2]);
    transition(tape, aux_state);
  }

  // Records the tape when it fails
  if (possible_transitions.size() == 0 && !end_state && !valid_input_) {
    tape_.set_input(tape.read_whole_tape());
    return;
  }

  return;
}

/**
 * @brief Sets the input string to the tape
 *
 */
void Turing_machine::set_input(std::string input) { 
  bool correct = true;
  std::string temp = "";
  for(int i = 0; i < input.size(); i++) {
    temp = input.substr(i, 1);
    if(!tau_.checker(temp)) {
      correct = false;
      break;
    }
  }
  if(correct) {
    tape_.set_input(input);
  } else {
    std::cerr << "Undefined input symbol: " << temp << std::endl;
    exit(1);
  }
   
  }

void Turing_machine::reset_machine() {
  valid_input_ = false;
  written_tape_ = false;
}