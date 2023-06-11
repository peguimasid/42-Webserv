#pragma once
#include <netinet/in.h>
#include <sys/stat.h>
#include <unistd.h>

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

// Config
#include "File.hpp"
#include "Location.hpp"
#include "Parser.hpp"
#include "Server.hpp"
#include "ServerFactory.hpp"

#define MAX_BODY_SIZE 30000000

class Error : public std::exception {
 private:
  std::string _errorMessage;

 public:
  Error(const std::string& errorMessage) throw();
  virtual const char* what() const throw();
  virtual ~Error() throw();
};
