#pragma once
#include "Webserv.hpp"

class ServerFactory {
 public:
  ServerFactory();
  ~ServerFactory();

  std::vector<Server> createServers(std::vector<std::string> serverConfigs);
};
