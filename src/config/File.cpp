#include "../../includes/File.hpp"

File::File() {
  this->_filePath = "";
}

File::File(const std::string& filePath) {
  this->_filePath = filePath;
}

File::~File() {}

FileType File::getType() {
  struct stat buffer;

  int result = stat(this->_filePath.c_str(), &buffer);

  if (result != 0) return INVALID_TYPE;

  if (S_ISREG(buffer.st_mode))
    return FILE_TYPE;

  if (S_ISDIR(buffer.st_mode))
    return DIRECTORY_TYPE;

  return OTHER_TYPE;
}

std::string File::getPath() {
  return this->_filePath;
}

bool File::isFileAccessibleInMode(int mode) {
  return access(this->_filePath.c_str(), mode) != -1;
}

const std::string File::getFileContent() {
  if (this->_filePath.empty()) {
    return std::string();
  }

  std::ifstream file(this->_filePath.c_str());
  if (!file) {
    throw std::runtime_error("Failed to open file: " + this->_filePath);
  }

  std::stringstream streamBinding;
  streamBinding << file.rdbuf();
  return streamBinding.str();
}
