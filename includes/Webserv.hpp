#pragma once
#include <sys/stat.h>
#include <unistd.h>

#include <fstream>
#include <iostream>
#include <sstream>

#include "ConfigFile.hpp"
#include "ConfigParser.hpp"

bool error(std::string errorMessage);
