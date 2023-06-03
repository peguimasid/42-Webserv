#include "../includes/Webserv.hpp"

int main(int argc, char **argv) {
  try {
    if (argc != 2) {
      throw std::invalid_argument("Usage: ./webserv <config_file>.conf");
    }
    signal(SIGPIPE, SIG_IGN);
    Parser config;
    config.parseServerConfigFile(argv[1]);
  } catch (std::exception &err) {
    error(err.what());
    return 1;
  }
}
