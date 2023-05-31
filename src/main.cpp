#include "../includes/Webserv.hpp"

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
