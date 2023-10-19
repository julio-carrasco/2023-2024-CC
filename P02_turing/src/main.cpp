// Julio Ivan Carrasco Armas
// 4º Ingenieria Informatica
// Universidad de La Laguna
// Complejidad de computacion
// alu0101110639@ull.edu.es

#include <fstream>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#include "../include/turing.h"

void Help(int, char **);

int main(int argc, char *argv[]) {
  Help(argc, argv);
  std::string filename = argv[1];
  Turing_machine mt(filename);
  mt.set_input(argv[2]);
  mt.start();
  return 0;
}

/**
 * @brief function handles the parameters given to the program in case the format is wrong
 * 
 * @param argc 
 * @param argv 
 */
void Help(int argc, char *argv[])
{
  const std::string help = "--help";
  if (argc == 2 && (argv[1] == help))
  {
    std::cerr << "To execute the turing machine it must be given at least 2 arguments in all situations" << std::endl;
    std::cerr << "The first one loads the configuration to the machine, the second one is the input string" << std::endl;
    std::cerr << "Ex: [executable] [config file] [input string]" << std::endl;
    exit(1);
  }
  if (argc < 3 || argc > 4)
  {
    std::cerr << "To execute the stack machine it must be given at least 2 arguments in all situations" << std::endl;
    std::cerr << "Ex: [executable] [config file] [input string]" << std::endl;
    std::cerr << "To know more use --help" << std::endl;
    exit(1);
  }
}