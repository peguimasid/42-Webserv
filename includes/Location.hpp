#pragma once
#include "Webserv.hpp"

class Location {
  std::string _locationPath;
  std::string _rootDirectory;
  bool _enableAutoIndex;
  std::string _defaultIndex;
  std::vector<short> _allowedMethods;
  std::string _returnPath;
  std::string _aliasPath;
  std::vector<std::string> _cgiPaths;
  std::vector<std::string> _cgiExtensions;
  unsigned long _maxRequestBodySize;

 public:
  std::map<std::string, std::string> _fileExtensionPaths;

  // Constructors
  Location();
  Location(const Location &other);
  Location &operator=(const Location &other);
  ~Location();

  // Getters
  const std::string &getLocationPath() const;
  const std::string &getRootDirectory() const;
  const bool &isAutoIndexEnabled() const;
  const std::string &getDefaultIndex() const;
  const std::vector<short> &getAllowedMethods() const;
  const std::string &getReturnPath() const;
  const std::string &getAliasPath() const;
  const std::vector<std::string> &getCgiPaths() const;
  const std::vector<std::string> &getCgiExtensions() const;
  const std::map<std::string, std::string> &getFileExtensionPaths() const;
  const unsigned long &getMaxRequestBodySize() const;

  // Setters
  void setLocationPath(const std::string &locationPath);
  void setRootDirectory(const std::string &rootDirectory);
  void setAutoIndexEnabled(bool isAutoIndexEnabled);
  void setDefaultIndex(const std::string &defaultIndex);
  void setAllowedMethods(const std::vector<std::string> &allowedMethods);
  void setReturnPath(const std::string &returnPath);
  void setAliasPath(const std::string &aliasPath);
  void setCgiPaths(const std::vector<std::string> &cgiPaths);
  void setCgiExtensions(const std::vector<std::string> &cgiExtensions);
  void setMaxRequestBodySize(unsigned long maxRequestBodySize);

  // Utils
  std::string getFormattedAllowedMethods() const;
};
