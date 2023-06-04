#include "../../includes/Parser.hpp"

Parser::Parser() {
  this->_serverCount = 0;
}

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

void Parser::parseServerConfigFile(const std::string &filePath) {
  File configFile(filePath);

  FileType fileType = configFile.getType();

  if (fileType == INVALID_TYPE) {
    throw std::invalid_argument("File is invalid");
  }

  bool isFileReadable = configFile.isFileAccessibleInMode(R_OK);

  if (!isFileReadable) {
    throw std::invalid_argument("File is not accessible");
  }

  const std::string fileContent = configFile.getFileContent();

  if (fileContent.empty()) {
    throw std::invalid_argument("File is empty");
  }

  const std::string fileContentSanitized = this->sanitizeFileContent(fileContent);

  std::cout << fileContentSanitized << std::endl;
}
