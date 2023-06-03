#pragma once
#include "Webserv.hpp"

class ConfigParser {
 private:
  size_t _serverCount;

 public:
  ConfigParser();
  ~ConfigParser();

  void parseServerConfigFile(const std::string &filePath);
};
