#include "../../includes/Location.hpp"

Location::Location() {
  this->_locationPath = "";
  this->_rootDirectory = "";
  this->_enableAutoIndex = false;
  this->_defaultIndex = "";
  this->_returnPath = "";
  this->_aliasPath = "";
  this->_maxRequestBodySize = MAX_BODY_SIZE;

  this->_allowedMethods.push_back(1);
  this->_allowedMethods.push_back(0);
  this->_allowedMethods.push_back(0);
  this->_allowedMethods.push_back(0);
  this->_allowedMethods.push_back(0);
}

Location::Location(const Location &other) {
  this->_locationPath = other._locationPath;
  this->_rootDirectory = other._rootDirectory;
  this->_enableAutoIndex = other._enableAutoIndex;
  this->_defaultIndex = other._defaultIndex;
  this->_returnPath = other._returnPath;
  this->_aliasPath = other._aliasPath;
  this->_maxRequestBodySize = other._maxRequestBodySize;
  this->_allowedMethods = other._allowedMethods;

  this->_cgiPaths = other._cgiPaths;
  this->_cgiExtensions = other._cgiExtensions;
  this->_fileExtensionPaths = other._fileExtensionPaths;
}

Location &Location::operator=(const Location &other) {
  if (this == &other) return *this;

  this->_locationPath = other._locationPath;
  this->_rootDirectory = other._rootDirectory;
  this->_enableAutoIndex = other._enableAutoIndex;
  this->_defaultIndex = other._defaultIndex;
  this->_returnPath = other._returnPath;
  this->_aliasPath = other._aliasPath;
  this->_maxRequestBodySize = other._maxRequestBodySize;
  this->_allowedMethods = other._allowedMethods;

  this->_cgiPaths = other._cgiPaths;
  this->_cgiExtensions = other._cgiExtensions;
  this->_fileExtensionPaths = other._fileExtensionPaths;

  return *this;
}

Location::~Location() {}

const std::string &Location::getLocationPath() const {
  return this->_locationPath;
}

const std::string &Location::getRootDirectory() const {
  return this->_rootDirectory;
}

const bool &Location::isAutoIndexEnabled() const {
  return this->_enableAutoIndex;
}

const std::string &Location::getDefaultIndex() const {
  return this->_defaultIndex;
}

const std::vector<short> &Location::getAllowedMethods() const {
  return this->_allowedMethods;
}

const std::string &Location::getReturnPath() const {
  return this->_returnPath;
}

const std::string &Location::getAliasPath() const {
  return this->_aliasPath;
}

const std::vector<std::string> &Location::getCgiPaths() const {
  return this->_cgiPaths;
}

const std::vector<std::string> &Location::getCgiExtensions() const {
  return this->_cgiExtensions;
}

const std::map<std::string, std::string> &Location::getFileExtensionPaths() const {
  return this->_fileExtensionPaths;
}

const unsigned long &Location::getMaxRequestBodySize() const {
  return this->_maxRequestBodySize;
}

void Location::setLocationPath(const std::string &locationPath) {
  this->_locationPath = locationPath;
}

void Location::setRootDirectory(const std::string &rootDirectory) {
  this->_rootDirectory = rootDirectory;
}

void Location::setAutoIndexEnabled(bool isAutoIndexEnabled) {
  this->_enableAutoIndex = isAutoIndexEnabled;
}

void Location::setDefaultIndex(const std::string &defaultIndex) {
  this->_defaultIndex = defaultIndex;
}

void Location::setAllowedMethods(const std::vector<std::string> &allowedMethods) {
  (void)allowedMethods;
  // TODO: Run through every item in vector and set in position or throw error if is not valid
}

void Location::setReturnPath(const std::string &returnPath) {
  this->_returnPath = returnPath;
}

void Location::setAliasPath(const std::string &aliasPath) {
  this->_aliasPath = aliasPath;
}

void Location::setCgiPaths(const std::vector<std::string> &cgiPaths) {
  this->_cgiPaths = cgiPaths;
}

void Location::setCgiExtensions(const std::vector<std::string> &cgiExtensions) {
  this->_cgiExtensions = cgiExtensions;
}

void Location::setMaxRequestBodySize(unsigned long maxRequestBodySize) {
  this->_maxRequestBodySize = maxRequestBodySize;
}

// Utils

std::string join(const std::vector<std::string> &strings, const std::string &separator) {
  std::string result;
  for (size_t i = 0; i < strings.size(); ++i) {
    result += strings[i];
    if (i < strings.size() - 1)
      result += separator;
  }
  return result;
}

std::string Location::getFormattedAllowedMethods() const {
  std::vector<std::string> methods;

  std::cout << this->_allowedMethods.size() << std::endl;
  if (this->_allowedMethods[0]) methods.push_back("GET");
  if (this->_allowedMethods[1]) methods.push_back("POST");
  if (this->_allowedMethods[2]) methods.push_back("DELETE");
  if (this->_allowedMethods[3]) methods.push_back("PUT");
  if (this->_allowedMethods[4]) methods.push_back("HEAD");

  return join(methods, ", ");
}
