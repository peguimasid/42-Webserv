#include "../../includes/ServerFactory.hpp"

ServerFactory::ServerFactory() {}

ServerFactory::~ServerFactory() {}

std::vector<Server> ServerFactory::createServers(std::vector<std::string> serverConfigs) {
  std::vector<Server> servers;

  for (size_t i = 0; i < serverConfigs.size(); i++) {
    Server server;
    servers.push_back(server);
  }

  return servers;
}
