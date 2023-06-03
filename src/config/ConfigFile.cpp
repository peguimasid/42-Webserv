#include "../../includes/ConfigFile.hpp"

ConfigFile::ConfigFile() {
  this->_fileSize = 0;
}

ConfigFile::ConfigFile(const std::string& filePath) {
  this->_filePath = filePath;
  this->_fileSize = 0;
}

ConfigFile::~ConfigFile() {}

FileType ConfigFile::getType() {
  struct stat buffer;

  int result = stat(this->_filePath.c_str(), &buffer);

  if (result != 0) return INVALID_TYPE;

  if (S_ISREG(buffer.st_mode))
    return FILE_TYPE;

  if (S_ISDIR(buffer.st_mode))
    return DIRECTORY_TYPE;

  return OTHER_TYPE;
}

std::string ConfigFile::getPath() {
  return this->_filePath;
}

int ConfigFile::getSize() {
  return this->_fileSize;
}

bool ConfigFile::isFileAccessibleInMode(int mode) {
  return access(this->_filePath.c_str(), mode) != -1;
}

const std::string ConfigFile::getFileContent() {
  if (this->_filePath.empty()) {
    return std::string();
  }

  std::ifstream configFile(this->_filePath.c_str());
  if (!configFile) {
    throw std::runtime_error("Failed to open file: " + this->_filePath);
  }

  std::stringstream streamBinding;
  streamBinding << configFile.rdbuf();
  return streamBinding.str();
}
