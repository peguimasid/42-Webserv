#pragma once
#include "Webserv.hpp"

class ServerFactory {
 public:
  ServerFactory();
  ~ServerFactory();

  Server createServer(const std::string &serverConfig);
  std::vector<Server> createServers(std::vector<std::string> serverConfigs);
};
