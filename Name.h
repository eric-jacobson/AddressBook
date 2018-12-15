// Name.h class declarations

#ifndef NAME_H
#define NAME_H

#include <fstream>
#include <iostream>
#include <string>
using namespace std;
#include "Field.h"


class Name
{
public:
	// Constructor prototypes
	Name();
	Name(Field firstNameIn, Field lastNameIn);

	// Access function prototypes
	Field getFirstName() const;
	Field getLastName() const;
	
	// Set function prototypes
	void setFirstName(Field firstNameIn);
	void setLastName(Field lastNameIn);

	// Other member function prototypes 
	Field toString() const;
	Field toFileString() const;

	// Function overloads
	friend bool operator==(const Name& name1, const Name& name2);
	friend bool operator!=(const Name& name1, const Name& name2);
	friend bool operator<(const Name& name1, const Name& name2);
	friend bool operator<=(const Name& name1, const Name& name2);
	friend bool operator>(const Name& name1, const Name& name2);
	friend bool operator>=(const Name& name1, const Name& name2);

	friend ostream &operator << (ostream &os, const Name &out_name);
	friend istream &operator >> (istream &is, Name &in_name);
	friend ofstream &operator << (ofstream &os, const Name &out_name);
	friend ifstream &operator >> (ifstream &is, Name &in_name);

protected:
	Field firstName;
	Field lastName;
};
#endif
