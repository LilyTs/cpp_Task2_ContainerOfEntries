#pragma once
#include "Entry.h"

int inputIntValue(const std::string msg = "", const int min = INT_MIN, const int max = INT_MAX);
int inputIntValue(const int default, bool &def, const std::string msg = "", const int min = INT_MIN, const int max = INT_MAX);
std::string inputStringValue(const std::string default, const std::string msg, bool &def);

bool inputEditedEntry(Entry &en, bool def);