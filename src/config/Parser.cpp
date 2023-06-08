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

size_t findStartServer(size_t start, const std::string &content) {
  size_t i = start;

  while (i < content.size()) {
    if (content[i] == 's') break;
    if (!std::isspace(content[i]))
      throw std::invalid_argument("Wrong character out of server scope{} 1");
    i++;
  }

  if (i == content.size())
    return start;
  if (content.compare(i, 6, "server") != 0)
    throw std::invalid_argument("Wrong character out of server scope{} 2");
  i += 6;
  while (i < content.size() && std::isspace(content[i]))
    i++;
  if (i == content.size() || content[i] != '{')
    throw std::invalid_argument("Wrong character out of server scope{} 3");

  return i;
}

size_t findEndServer(size_t start, const std::string &content) {
  size_t i;
  size_t scope;

  scope = 0;
  for (i = start + 1; content[i]; i++) {
    if (content[i] == '{')
      scope++;
    if (content[i] == '}') {
      if (!scope)
        return (i);
      scope--;
    }
  }
  return (start);
}

std::vector<std::string> Parser::splitServerConfigs(const std::string &fileContent) {
  std::vector<std::string> result;

  if (fileContent.find("server") == std::string::npos) {
    throw std::invalid_argument("Server not found in the content");
  }

  size_t start = 0;
  size_t end = 1;

  while (start != end && start < fileContent.length()) {
    start = findStartServer(start, fileContent);
    end = findEndServer(start, fileContent);
    if (start == end) throw std::invalid_argument("problem with scope");
    result.push_back(fileContent.substr(start, end - start + 1));
    start = end + 1;
  }

  return result;
}

void Parser::parseServerConfigFile(const std::string &filePath) {
  File configFile(filePath);

  FileType fileType = configFile.getType();

  if (fileType == INVALID_TYPE) {
    throw std::invalid_argument("File is invalid");
  }

  bool isFileReadable = configFile.isAccessibleInMode(R_OK);

  if (!isFileReadable) {
    throw std::invalid_argument("File is not accessible");
  }

  const std::string fileContent = configFile.getFileContent();

  if (fileContent.empty()) {
    throw std::invalid_argument("File is empty");
  }

  const std::string fileContentSanitized = this->sanitizeFileContent(fileContent);

  std::vector<std::string> serverConfigs = splitServerConfigs(fileContentSanitized);

  for (size_t i = 0; i < serverConfigs.size(); i++) {
    std::cout << "-----------------Start-----------------" << std::endl;
    std::cout << serverConfigs[i] << std::endl;
    std::cout << "------------------End------------------" << std::endl;
  }
}
