#include "../includes/Webserv.hpp"

int error(std::string errorMessage) {
  std::cerr << "\033[0;31m";
  std::cerr << errorMessage << std::endl;
  std::cerr << "\033[0m";
  return 1;
}

int main(int argc, char **argv) {
  try {
    if (argc != 2) {
      throw std::invalid_argument("Usage: ./webserv <config_file>.conf");
    }
    signal(SIGPIPE, SIG_IGN);
    Parser config;
    config.parseServerConfigFile(argv[1]);
  } catch (std::exception &err) {
    return error(err.what());
  }
}
