#ifndef STAFF_H
#define STAFF_H

#include "Person.h"
#include <string>

class Staff : public Person {
private:
	std::string role;

public:
	Staff(std::string name, int id, std::string role);

	void assignRole(std::string newRole);
	void displayInfo() const override;

	~Staff() {}
};

#endif