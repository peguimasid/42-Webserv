#include "../../includes/Server.hpp"

// Constructors

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
  this->_locations = other._locations;
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
  this->_locations = other._locations;

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

// Getters

int Server::getFd() {
  return this->_listenFd;
}

const uint16_t &Server::getPort() {
  return this->_port;
}

const in_addr_t &Server::getHost() {
  return this->_host;
}

const bool &Server::getAutoIndex() {
  return this->_autoIndex;
}

const std::string &Server::getRoot() {
  return this->_root;
}

const std::string &Server::getIndex() {
  return this->_index;
}

const std::string &Server::getServerName() {
  return this->_serverName;
}

const std::vector<Location> &Server::getLocations() {
  return this->_locations;
}

const size_t &Server::getClientMaxBodySize() {
  return this->_clientMaxBodySize;
}

const std::string &Server::getPathErrorPage(short key) {
  std::map<short, std::string>::iterator it = this->_errorPages.find(key);
  if (it == this->_errorPages.end())
    throw Error("Error page does not exist");
  return (it->second);
}

const std::map<short, std::string> &Server::getErrorPages() {
  return this->_errorPages;
}

// Setters

void Server::setFd(int fd) {
  this->_listenFd = fd;
}

void Server::setPort(uint16_t port) {
  this->_port = port;
}

void Server::setHost(in_addr_t host) {
  this->_host = host;
}

void Server::setAutoIndex(bool autoIndex) {
  this->_autoIndex = autoIndex;
}

void Server::setRoot(const std::string &root) {
  this->_root = root;
}

void Server::setIndex(const std::string &index) {
  this->_index = index;
}

void Server::setServerName(const std::string &serverName) {
  this->_serverName = serverName;
}

void Server::setClientMaxBodySize(size_t maxBodySize) {
  this->_clientMaxBodySize = maxBodySize;
}

void Server::setErrorPages(const std::map<short, std::string> &errorPages) {
  this->_errorPages = errorPages;
}
