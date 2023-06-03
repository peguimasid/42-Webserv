#pragma once
#include <sys/stat.h>
#include <unistd.h>

#include <fstream>
#include <iostream>
#include <sstream>

// Config
#include "File.hpp"
#include "Parser.hpp"

bool error(std::string errorMessage);
