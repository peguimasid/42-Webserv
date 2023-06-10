#include "../../includes/ServerFactory.hpp"

ServerFactory::ServerFactory() {}

ServerFactory::~ServerFactory() {}

Server ServerFactory::createServer(const std::string &serverConfig) {
  Server server;

  (void)serverConfig;

  return server;
}

std::vector<Server> ServerFactory::createServers(std::vector<std::string> serverConfigs) {
  std::vector<Server> servers;

  for (size_t i = 0; i < serverConfigs.size(); i++) {
    std::string currentServerConfig = serverConfigs[i];
    Server server = createServer(currentServerConfig);
    servers.push_back(server);
  }

  return servers;
}
