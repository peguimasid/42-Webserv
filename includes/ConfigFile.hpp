#pragma once
#include "Webserv.hpp"

enum FileType {
  FILE_TYPE = 1,
  DIRECTORY_TYPE = 2,
  OTHER_TYPE = 3,
  INVALID_TYPE = -1,
};

class ConfigFile {
 private:
  std::string _filePath;
  size_t _fileSize;

 public:
  ConfigFile();
  ConfigFile(const std::string& filePath);
  ~ConfigFile();

  static FileType getType(const std::string& filePath);
  std::string getPath();
  int getSize();
};
