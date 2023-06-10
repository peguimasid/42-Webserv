#include "../../includes/Parser.hpp"

Parser::Parser() {}

Parser::~Parser() {}

const std::string Parser::removeComments(const std::string &string) {
  std::string result = string;

  int hashTagIndex = result.find('#');
  while (hashTagIndex >= 0) {
    int newLineIndex = result.find('\n', hashTagIndex);
    result.erase(hashTagIndex, newLineIndex - hashTagIndex);
    hashTagIndex = result.find('#');
  }

  return result;
}

const std::string Parser::trimString(const std::string &string) {
  std::string result = string;

  size_t start = 0;

  while (start < result.size() && std::isspace(result[start])) {
    start++;
  }

  result.erase(0, start);

  size_t end = result.size() - 1;

  while (end > 0 && std::isspace(result[end])) {
    end--;
  }

  result.erase(end + 1);

  return result;
}

const std::string Parser::sanitizeFileContent(const std::string &fileContent) {
  std::string contentWithoutComments = this->removeComments(fileContent);
  std::string contentTrimmed = this->trimString(contentWithoutComments);

  return contentTrimmed;
}

size_t Parser::findStartServer(size_t start, const std::string &content) {
  size_t i = start;

  while (i < content.size() && std::isspace(content[i])) {
    i++;
  }

  if (i == content.size() || content.compare(i, 6, "server") != 0) {
    throw Error("Invalid server scope: 'server' keyword not found");
  }

  i += 6;

  while (i < content.size() && std::isspace(content[i])) {
    i++;
  }

  if (i == content.size() || content[i] != '{') {
    throw Error("Invalid server scope: Opening brace '{' not found");
  }

  return i;
}

size_t Parser::findEndServer(size_t start, const std::string &content) {
  size_t i = start + 1;
  size_t openBraces = 0;

  while (i < content.size()) {
    if (content[i] == '{') {
      openBraces++;
    }
    if (content[i] == '}') {
      if (openBraces == 0) return i;
      openBraces--;
    }
    i++;
  }

  throw Error("Invalid server scope: Closing brace '}' not found");
}

const std::vector<std::string> Parser::splitServerConfigs(const std::string &fileContent) {
  std::vector<std::string> result;

  if (fileContent.find("server") == std::string::npos) {
    throw Error("Server not found in the content");
  }

  size_t start = 0;
  size_t end = 1;

  while (start != end && start < fileContent.size()) {
    start = this->findStartServer(start, fileContent);
    end = this->findEndServer(start, fileContent);
    if (start == end) {
      throw Error("Invalid server scope: Empty server configuration found.");
    }
    result.push_back(fileContent.substr(start, end - start + 1));
    start = end + 1;
  }

  return result;
}

const std::vector<Server> Parser::createServers(const std::vector<std::string> &serverConfigs) {
  std::vector<Server> result;

  for (size_t i = 0; i < serverConfigs.size(); i++) {
    Server currentServer;
    result.push_back(currentServer);
  }

  return result;
}

void Parser::parseServerConfigFile(const std::string &filePath) {
  File configFile(filePath);

  FileType fileType = configFile.getType();

  if (fileType == INVALID_TYPE) {
    throw Error("File is invalid");
  }

  bool isFileReadable = configFile.isAccessibleInMode(R_OK);

  if (!isFileReadable) {
    throw Error("File is not accessible");
  }

  const std::string fileContent = configFile.getFileContent();

  if (fileContent.empty()) {
    throw Error("File is empty");
  }

  const std::string fileContentSanitized = this->sanitizeFileContent(fileContent);

  const std::vector<std::string> serverConfigs = splitServerConfigs(fileContentSanitized);

  this->_servers = createServers(serverConfigs);

  for (size_t i = 0; i < this->_servers.size(); i++) {
    std::cout << "-----------------Start-----------------" << std::endl;
    std::cout << this->_servers[i].getPort() << std::endl;
    std::cout << "------------------End------------------" << std::endl;
  }
}
