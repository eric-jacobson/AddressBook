// Contact.h Contact class declarations

#ifndef CONTACT_H
#define CONTACT_H

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#include "Name.h"
#include "Address.h"
#include "Field.h"

class Contact
{
public:
	// Constructors
	Contact();	// Empty container
	Contact(Field phoneIn, Field emailIn, Field birthdayIn, Field pictureIn);
	Contact(Address fullAddrIn, Name fullNameIn);

	// Access function prototypes
	Field getPhoneNumber() const;
	Field getEmail() const;
	Field getBirthday() const;
	Field getPictureFile() const;
	Name getFullName() const;
	Address getFullAddress()const;

	// Set function prototypes
	void setPhoneNumber(Field phoneIn);
	void setEmail(Field emailIn);
	void setBirthday(Field birthdayIn);
	void setPictureFile(Field pictureIn);
	void setFullName(Name fullNameIn);
	void setFullAddress(Address fullAddressIn);

	Field toString() const;
	Field toFileString() const;

	// Operator overloaded functions
	friend bool operator==(const Contact& contact1, const Contact& contact2);
	friend bool operator!=(const Contact& contact1, const Contact& contact2);
	friend bool operator<(const Contact& contact1, const Contact& contact2);
	friend bool operator<=(const Contact& contact1, const Contact& contact2);
	friend bool operator>(const Contact& contact1, const Contact& contact2);
	friend bool operator>=(const Contact& contact1, const Contact& contact2);

	friend ostream &operator << (ostream &os, const Contact &out_contact);
	friend istream &operator >> (istream &is, Contact &in_contact);
	friend ofstream &operator << (ofstream &os, const Contact &out_contact);
	friend ifstream &operator >> (ifstream &is, Contact &in_contact);

protected:
	Name fullName;
	Address fullAddress;
	Field phoneNumber;
	Field emailAddress;
	Field birthday;
	Field pictureFile;
};
#endif
