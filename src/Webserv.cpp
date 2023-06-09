#include "../includes/Webserv.hpp"

Error::Error(const std::string &errorMessage) throw() {
  this->_errorMessage = errorMessage;
}

Error::~Error() throw() {}

const char *Error::Error::what() const throw() {
  return this->_errorMessage.c_str();
}
