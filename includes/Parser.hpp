#pragma once
#include "Webserv.hpp"

class Parser {
 private:
  size_t _serverCount;

 public:
  Parser();
  ~Parser();

  void parseServerConfigFile(const std::string &filePath);

  const std::string sanitizeFileContent(const std::string &fileContent);
  const std::string removeComments(const std::string &string);
};
