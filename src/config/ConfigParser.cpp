#include "../../includes/ConfigParser.hpp"

ConfigParser::ConfigParser() {
  this->_serverCount = 0;
}

ConfigParser::~ConfigParser() {}

void ConfigParser::parseServerConfigFile(const std::string &filePath) {
  ConfigFile configFile(filePath);

  FileType fileType = configFile.getType(configFile.getPath());

  if (fileType == INVALID_TYPE) {
    throw std::invalid_argument("File is invalid");
  }

  bool isFileReadable = configFile.isFileAccessibleInMode(configFile.getPath(), R_OK);

  if (!isFileReadable) {
    throw std::invalid_argument("File is not accessible");
  }
}
