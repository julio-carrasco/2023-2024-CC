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

#include "../include/apv.h"

void Help(int, char **);

int main(int argc, char *argv[]) {
  Help(argc, argv);
  std::string filename = argv[1];
  Stack_machine ap(filename);
  ap.set_input(argv[2]);
  if(argc == 4) {
    ap.set_trail(argv[3]);
  }
  
  ap.start();
  return 0;
}

void Help(int argc, char *argv[])
{
  const std::string help = "--help";
  if (argc == 2 && (argv[1] == help))
  {
    std::cerr << "To execute the stack machine it must be given at least 2 arguments in all situations" << std::endl;
    std::cerr << "The first one loads the configuration to the machine, the second one is the input string" << std::endl;
    std::cerr << "Ex: [executable] [config file] [input string]" << std::endl;
    std::cerr << "Aditionally you can pass another parameter to activate the trail mode which shows the state of the machine before each transition" << std::endl;
    std::cerr << "To activate it put a 1 after the input string" << std::endl;
    std::cerr << "Ex: [executable] [config file] [input string] [1 to activate trail mode]" << std::endl;
    exit(1);
  }
  if (argc < 3 || argc > 4)
  {
    std::cerr << "To execute the stack machine it must be given at least 2 arguments in all situations" << std::endl;
    std::cerr << "Aditionally you can pass another parameter to activate the trail mode which shows the state of the machine before each transition" << std::endl;
    std::cerr << "Ex: [executable] [config file] [input string] [1 to activate trail mode]" << std::endl;
    std::cerr << "To know more use --help" << std::endl;
    exit(1);
  }
}