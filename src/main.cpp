#include "../includes/Webserv.hpp"

bool error(std::string errorMessage) {
  std::cerr << "\033[0;31m";
  std::cerr << errorMessage << std::endl;
  std::cerr << "\033[0m";
  return false;
}

int main(int argc, char **argv) {
  try {
    if (argc != 2) {
      throw std::invalid_argument("Usage: ./webserv <config_file>.conf");
    }
    signal(SIGPIPE, SIG_IGN);
    std::string configFile(argv[1]);
    std::cout << "Hello World" << std::endl;
  } catch (std::exception &err) {
    error(err.what());
    return 1;
  }
}
