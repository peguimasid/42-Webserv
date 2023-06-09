#include "../../includes/Server.hpp"

Server::Server() {
  this->_port = 0;
  this->_host = 0;
  this->_listenFd = 0;
  this->_clientMaxBodySize = MAX_BODY_SIZE;
  this->_serverName = "";
  this->_root = "";
  this->_index = "";
  this->_autoIndex = false;
  this->initErrorPages();
}

Server::Server(const Server &other) {
  if (this == &other) return;

  this->_port = other._port;
  this->_host = other._host;
  this->_listenFd = other._listenFd;
  this->_clientMaxBodySize = other._clientMaxBodySize;
  this->_serverName = other._serverName;
  this->_root = other._root;
  this->_index = other._index;
  this->_autoIndex = other._autoIndex;
  this->_errorPages = other._errorPages;
  this->_serverAddress = other._serverAddress;
}

Server &Server::operator=(const Server &other) {
  if (this == &other) return *this;

  this->_port = other._port;
  this->_host = other._host;
  this->_listenFd = other._listenFd;
  this->_clientMaxBodySize = other._clientMaxBodySize;
  this->_serverName = other._serverName;
  this->_root = other._root;
  this->_index = other._index;
  this->_autoIndex = other._autoIndex;
  this->_errorPages = other._errorPages;
  this->_serverAddress = other._serverAddress;

  return *this;
}

Server::~Server() {}

void Server::initErrorPages(void) {
  this->_errorPages[301] = "";
  this->_errorPages[302] = "";
  this->_errorPages[400] = "";
  this->_errorPages[401] = "";
  this->_errorPages[402] = "";
  this->_errorPages[403] = "";
  this->_errorPages[404] = "";
  this->_errorPages[405] = "";
  this->_errorPages[406] = "";
  this->_errorPages[500] = "";
  this->_errorPages[501] = "";
  this->_errorPages[502] = "";
  this->_errorPages[503] = "";
  this->_errorPages[505] = "";
}