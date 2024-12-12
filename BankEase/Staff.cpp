#include "Staff.h"
#include <iostream>

Staff::Staff(std::string name, int id, std::string role)
	: Person(name, id), role(role) {}

void Staff::assignRole(std::string newRole) {
	role = newRole;
	std::cout << "Role updated to: " << role << "\n";
}

void Staff::displayInfo() const {
	std::cout << "Staff ID: " << id << ", Name: " << name << ", Role: " << role << "\n";
}