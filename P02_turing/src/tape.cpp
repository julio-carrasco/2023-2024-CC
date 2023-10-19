// Julio Ivan Carrasco Armas
// 4º Ingenieria Informatica
// Universidad de La Laguna
// Complejidad de computacion
// alu0101110639@ull.edu.es

#include "../include/tape.h"

Tape::Tape() { head_ = 1; }

Tape::Tape(std::string empty) {
  blank_ = empty;
  head_ = 1;
}

Tape::Tape(std::string input, std::string empty) {
  tape_.emplace_back(empty);
  tape_.emplace_back(input);
  tape_.emplace_back(empty);
  head_ = 1;
}

/**
 * @brief Returns head position
 *
 * @return int head position
 */
int Tape::get_head() { return head_; }

/**
 * @brief Moves the head left, right or stop
 *
 * @param movement string with the direction of the movement
 */
void Tape::move_head(std::string movement) {
  if (movement == "L") {
    if (head_ == 0) {
      edge_case();
    } else {
      head_ = head_ - 1;
    }

  } else if (movement == "R") {
    if (head_ == tape_.size() - 1) {
      edge_case();
      head_ = head_ + 1;
    } else {
      head_ = head_ + 1;
    }
  } else if (movement == "S") {
    head_ = head_;
  } else {
    std::cerr << "Unexpected movement request: " << movement << std::endl;
    exit(1);
  }
}

/**
 * @brief Writes the symbol to the tape in the position of the head
 *
 * @param symbol string with the symbol to write
 */
void Tape::write_tape(std::string symbol) { tape_[get_head()] = symbol; }

/**
 * @brief Reads the tape in the position of the head
 *
 * @return std::string with the character at the head
 */
std::string Tape::read_tape() {
  std::string temp = tape_[0];
  return tape_[get_head()];
}

/**
 * @brief Reads the whole tape
 *
 * @return std::string with the whole tape
 */
std::string Tape::read_whole_tape() {
  std::string output = "";
  for (auto it : tape_) {
    output += it;
  }
  return output;
}

/**
 * @brief Function handles the cases when the head is at the edge of the
 * physical vector and adds blank spaces
 *
 */
void Tape::edge_case() {
  if (head_ == 0) {
    tape_.insert(tape_.begin(), blank_);
  } else {
    tape_.emplace_back(blank_);
  }
}

/**
 * @brief Writes the whole string to the tape
 *
 * @param input
 */
void Tape::set_input(std::string input) {
  tape_.clear();
  tape_.emplace_back(blank_);
  for (int i = 0; i < input.size(); i++) {
    std::string temp = input.substr(i, 1);
    tape_.emplace_back(temp);
  }
  tape_.emplace_back(blank_);
}