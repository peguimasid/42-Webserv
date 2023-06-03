#include "../../includes/ConfigParser.hpp"

ConfigParser::ConfigParser() {
  this->_serverCount = 0;
}

ConfigParser::~ConfigParser() {}

void ConfigParser::parseServerConfigFile(const std::string &filePath) {
  std::cout << filePath << std::endl;
}
