// Julio Ivan Carrasco Armas
// 4º Ingenieria Informatica
// Universidad de La Laguna
// Complejidad de computacion
// alu0101110639@ull.edu.es

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>

int main() {
  std::string input = "a A q1 A A";
  std::string name = input.substr(0, 3);
  std::string destination = input.substr(3);
  std::cout << "name: " << name << std::endl;
  std::cout << "destiantion: " << destination << std::endl;
  return 0;
}
