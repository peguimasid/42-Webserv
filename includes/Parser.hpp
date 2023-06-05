#pragma once
#include "Webserv.hpp"

class Parser {
 public:
  Parser();
  ~Parser();

  void parseServerConfigFile(const std::string &filePath);

  std::vector<std::string> splitServerConfigs(const std::string &fileContent);

  const std::string sanitizeFileContent(const std::string &fileContent);
  const std::string removeComments(const std::string &string);
  const std::string trimString(const std::string &string);
};
