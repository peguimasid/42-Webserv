#include "../includes/Webserv.hpp"

int error(std::string errorMessage) {
  std::cerr << "\033[0;31m";
  std::cerr << errorMessage << std::endl;
  std::cerr << "\033[0m";
  return 1;
}

// TODO: Remove this
void printServers(std::vector<Server> servers) {
  for (size_t i = 0; i < servers.size(); i++) {
    std::cout << "-----------------Start-----------------" << std::endl;
    std::cout << servers[i].getPort() << std::endl;
    std::cout << "------------------End------------------" << std::endl;
  }
}

int main(int argc, char **argv) {
  try {
    if (argc != 2) {
      throw std::invalid_argument("Usage: ./webserv <config_file>.conf");
    }
    signal(SIGPIPE, SIG_IGN);
    Parser config;
    std::vector<Server> servers = config.parseServerConfigFile(argv[1]);
    printServers(servers);
  } catch (std::exception &err) {
    return error(err.what());
  }
}
