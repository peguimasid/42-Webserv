#pragma once
#include "Webserv.hpp"

class Server {
 private:
  int _listenFd;
  uint16_t _port;
  in_addr_t _host;
  bool _autoIndex;
  std::string _root;
  std::string _index;
  std::string _serverName;
  unsigned long _clientMaxBodySize;
  struct sockaddr_in _serverAddress;
  std::map<short, std::string> _errorPages;

 public:
  // Constructors
  Server();
  Server(const Server &other);
  Server &operator=(const Server &rhs);
  ~Server();

  // Utils
  void initErrorPages(void);

  // Getters
  int getFd();
  const uint16_t &getPort();
  const in_addr_t &getHost();
  const bool &getAutoIndex();
  const std::string &getRoot();
  const std::string &getIndex();
  const std::string &getServerName();
  const size_t &getClientMaxBodySize();
  const std::string &getPathErrorPage(short key);
  const std::map<short, std::string> &getErrorPages();
};
