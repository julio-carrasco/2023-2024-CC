// Julio Ivan Carrasco Armas
// 4º Ingenieria Informatica
// Universidad de La Laguna
// Complejidad de computacion
// alu0101110639@ull.edu.es

#include "../include/tape.h"

Tape::Tape(std::string input) {
  std::string empty = "*";
  tape_.emplace_back(empty);
  tape_.emplace_back(input);
  tape_.emplace_back(empty);
}

int Tape::getHead() { return head_; }

void Tape::moveHead(std::string movement) {
  if (movement == "L") {
    if (head_ == 0) {
      edgeCase();
    } else {
      head_ = head_ - 1;
    }

  } else if (movement == "R") {
    if (head_ <= tape_.size()) {
      edgeCase();
    } else {
      head_ = head_ - 1;
    }
  } else if (movement == "S") {
    head_ = head_;
  } else {
    std::cerr << "Unexpected movement request: " << movement << std::endl;
    exit(1);
  }
}

void Tape::writeTape(std::string symbol) { tape_[getHead()] = symbol; }

std::string Tape::readTape() { return tape_[getHead()]; }

void Tape::edgeCase() {}