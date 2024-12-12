#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
protected:
	std::string name;
	int id;

public:
	Person(std::string name, int id) : name(name), id(id) {}
	virtual void displayInfo() const = 0;
	virtual ~Person() {}
};

#endif