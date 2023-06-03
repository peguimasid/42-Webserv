#include "../../includes/Parser.hpp"

Parser::Parser() {
  this->_serverCount = 0;
}

Parser::~Parser() {}

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

  std::cout << fileContent << std::endl;
}
