#pragma once
#include "Webserv.hpp"

class Server;

class Parser {
 public:
  Parser();
  ~Parser();

  const std::vector<Server> parseServerConfigFile(const std::string &filePath);

  size_t findStartServer(size_t start, const std::string &content);
  size_t findEndServer(size_t start, const std::string &content);
  const std::vector<std::string> splitServerConfigs(const std::string &fileContent);

  const std::string sanitizeFileContent(const std::string &fileContent);
  const std::string removeComments(const std::string &string);
  const std::string trimString(const std::string &string);
};
