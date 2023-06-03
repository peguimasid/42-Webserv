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
  size_t _fileSize;

 public:
  File();
  File(const std::string& filePath);
  ~File();

  int getSize();
  std::string getPath();
  FileType getType();

  bool isFileAccessibleInMode(int mode);
  const std::string getFileContent();
};
