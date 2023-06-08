#pragma once
#include "Webserv.hpp"

enum FileType {
  FILE_TYPE = 1,
  DIRECTORY_TYPE = 2,
  OTHER_TYPE = 3,
  INVALID_TYPE = -1,
};

class File {
 private:
  std::string _filePath;

 public:
  File();
  File(const std::string& filePath);
  ~File();

  std::string getPath();
  FileType getType();

  bool isAccessibleInMode(int mode);
  const std::string getFileContent();
};
