#include "../../includes/ConfigFile.hpp"

ConfigFile::ConfigFile() {
  this->_fileSize = 0;
}

ConfigFile::ConfigFile(const std::string& filePath) {
  this->_filePath = filePath;
  this->_fileSize = 0;
}

ConfigFile::~ConfigFile() {}

FileType ConfigFile::getType(const std::string& filePath) {
  struct stat buffer;

  int result = stat(filePath.c_str(), &buffer);

  if (result != 0) return INVALID_TYPE;

  if (S_ISREG(buffer.st_mode))
    return FILE_TYPE;

  if (S_ISDIR(buffer.st_mode))
    return DIRECTORY_TYPE;

  return OTHER_TYPE;
}

bool ConfigFile::isFileAccessibleInMode(const std::string& path, int mode) {
  return access(path.c_str(), mode) != -1;
}

std::string ConfigFile::getPath() {
  return this->_filePath;
}

int ConfigFile::getSize() {
  return this->_fileSize;
}
