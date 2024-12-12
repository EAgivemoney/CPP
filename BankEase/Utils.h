#ifndef UTILS_H
#define UTILS_H

#include <string>

namespace Utils {
	bool isValidName(const std::string& name);
	bool isValidAmount(double amount);
	bool isValidID(int id);
}

#endif