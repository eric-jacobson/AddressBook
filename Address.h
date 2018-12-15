// Address.h class declarations

#ifndef ADDRESS_H
#define ADDRESS_H

#include <fstream>
#include <iostream>
#include <string>
using namespace std;
#include "Field.h"

class Address
{
public:
	Address();
	Address(Field streetAddressIn, Field cityIn, Field stateIn, Field zipIn);

	// Access function prototypes
	Field getStreetAddress() const;
	Field getCity() const;
	Field getState() const;
	Field getZip() const;

	// Set function prototypes
	void setStreetAddress(Field streetAddressIn);
	void setCity(Field cityIn);
	void setState(Field stateIn);
	void setZip(Field zipIn);

	// Other member function prototypes
	Field toString() const; 
	Field toFileString() const;

	// Operator overloaded functions
	friend ostream &operator << (ostream &os, const Address &out_addr);
	friend istream &operator >> (istream &is, Address &in_addr);
	friend ofstream &operator << (ofstream &os, const Address &out_addr);
	friend ifstream &operator >> (ifstream &is, Address &in_addr);


protected:
	Field streetAdress;
	Field city;
	Field state;
	Field zip;
};
#endif
