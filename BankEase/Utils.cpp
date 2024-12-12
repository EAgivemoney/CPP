#include "Utils.h"
#include <cctype>

namespace Utils {
	
	bool isValidName(const std::string& name) {
		for (char c : name) {
			if (!std::isalpha(c) && c != ' ') return false;
		}
		return !name.empty();
	}

	bool isValidAmmount(double amount) {
		return amount >= 0;
	}

	bool isValidId(int id) {
		return id > 0;
	}
}