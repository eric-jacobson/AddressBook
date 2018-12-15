// Name.cpp class implementation

#include "Name.h"

// Constructors
Name::Name()
{
	firstName = "Unkown";
	lastName = "Unkown";
}

Name::Name(Field firstNameIn, Field lastNameIn)
{
	firstName = firstNameIn;
	lastName = lastNameIn;
}

// Access functions
Field Name::getFirstName() const
{
	return firstName;
}

Field Name::getLastName() const
{
	return lastName;
}

// Set functions
void Name::setFirstName(Field firstNameIn)
{
	firstName = firstNameIn;
}

void Name::setLastName(Field lastNameIn)
{
	lastName = lastNameIn;
}

// Other member functions
Field Name::toString() const
{
	Field fullName;
	fullName = lastName + ", " + firstName;
	return fullName;	
}

Field Name::toFileString() const
{
	Field fullName;
	fullName = lastName + "," + firstName + ",";
	return fullName;
}

// Function overloads

bool operator==(const Name& name1, const Name& name2)
{
	if (name1.lastName == name2.lastName && name1.firstName == name2.firstName)
		return(true);
	return(false);
}

bool operator!=(const Name& name1, const Name& name2)
{
	return !(name1 == name2);
}

bool operator<(const Name& name1, const Name& name2)
{
	string full1 = name1.lastName + name1.firstName;
	string full2 = name2.lastName + name2.firstName;

	if (full1 < full2)
		return(true);
	return(false);
}

bool operator<=(const Name& name1, const Name& name2)
{
	return (name1 < name2 || name1 == name2);
}

bool operator>(const Name& name1, const Name& name2)
{
	return !(name1 > name2);
}

bool operator>=(const Name& name1, const Name& name2)
{
	return !(name1 <= name2);
}

ostream &operator << (ostream &os, const Name &out_name)
{
	os << out_name.toString() << endl;
	return(os);
}

istream &operator >> (istream &is, Name &in_name)
{
	Field tmp;

	is >> tmp;
	in_name.setLastName(tmp);

	is >> tmp;
	in_name.setFirstName(tmp);

	return(is);
}

ofstream &operator << (ofstream &os, const Name &out_name)
{
	os << out_name.toFileString() << endl;
	return(os);
}

ifstream &operator >> (ifstream &is, Name &in_name)
{
	Field tmp;

	is >> tmp;
	in_name.setLastName(tmp);

	is >> tmp;
	in_name.setFirstName(tmp);

	return(is);
}