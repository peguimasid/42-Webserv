#pragma once
#include "Webserv.hpp"

class Server;

class Parser {
 private:
  std::vector<Server> _servers;

 public:
  Parser();
  ~Parser();

  void parseServerConfigFile(const std::string &filePath);

  size_t findStartServer(size_t start, const std::string &content);
  size_t findEndServer(size_t start, const std::string &content);

  const std::vector<std::string> splitServerConfigs(const std::string &fileContent);
  const std::vector<Server> createServers(const std::vector<std::string> &serverConfigs);

  const std::string sanitizeFileContent(const std::string &fileContent);
  const std::string removeComments(const std::string &string);
  const std::string trimString(const std::string &string);
};
