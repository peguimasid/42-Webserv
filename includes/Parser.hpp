#pragma once
#include "Webserv.hpp"

class Parser {
 private:
  size_t _serverCount;

 public:
  Parser();
  ~Parser();

  void parseServerConfigFile(const std::string &filePath);
};
