#pragma once
#include <sys/stat.h>
#include <unistd.h>

#include <fstream>
#include <iostream>
#include <sstream>

// Config
#include "File.hpp"
#include "Parser.hpp"

class Error : public std::exception {
 private:
  std::string _errorMessage;

 public:
  Error(const std::string& errorMessage) throw();
  virtual const char* what() const throw();
  virtual ~Error() throw();
};
