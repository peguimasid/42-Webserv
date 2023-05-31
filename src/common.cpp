#include "../includes/Webserv.hpp"

bool error(std::string errorMessage) {
  std::cerr << "\033[0;31m";
  std::cerr << errorMessage << std::endl;
  std::cerr << "\033[0m";
  return false;
}
