//Address.cpp class implementation 

#include "Address.h"

// Constructor prototypes
Address::Address()
{
	streetAdress = "Unkown";
	city = "Unkown";
	state = "Unkown";
	zip = "Unkown";
}

Address::Address(Field streetAddressIn, Field cityIn, Field stateIn, Field zipIn)
{
	streetAdress = streetAddressIn;
	city = cityIn;
	state = stateIn;
	zip = zipIn;
}

// Access function prototypes
Field Address::getStreetAddress() const
{
	return streetAdress;
}

Field Address::getCity() const
{
	return city;
}

Field Address::getState() const
{
	return state;
}

Field Address::getZip() const
{
	return zip;
}

// Set function prototypes
void Address::setStreetAddress(Field streetAddressIn)
{
	streetAdress = streetAddressIn;
}

void Address::setCity(Field cityIn)
{
	city = cityIn;
}

void Address::setState(Field stateIn)
{
	state = stateIn;
}

void Address::setZip(Field zipIn)
{
	zip = zipIn;
}

 //Other member function prototypes
Field Address::toString() const
{
	Field fullAddress;
	fullAddress = streetAdress + "\n          " + city + ", " + state + " " + zip;
	return fullAddress;
}

Field Address::toFileString() const
{
	Field fullAddress;
	fullAddress = streetAdress + "," + city + "," + state + "," + zip + ",";
	return fullAddress;
}

// Operator overloaded functions
ostream &operator << (ostream &os, const Address &out_addr)
{
	os << out_addr.toString() << endl;
	return (os);
}
istream &operator >> (istream &is, Address &in_addr)
{
	Field tmp;

	is >> tmp;
	in_addr.setStreetAddress(tmp);

	is >> tmp;
	in_addr.setCity(tmp);
	
	is >> tmp;
	in_addr.setState(tmp);

	is >> tmp;
	in_addr.setZip(tmp);

	return (is);
}
ofstream &operator << (ofstream &os, const Address &out_addr)
{
	os << out_addr.toFileString() << endl;
	return (os);
}
ifstream &operator >> (ifstream &is, Address &in_addr)
{
	Field tmp;

	is >> tmp;
	in_addr.setStreetAddress(tmp);

	is >> tmp;
	in_addr.setCity(tmp);

	is >> tmp;
	in_addr.setState(tmp);

	is >> tmp;
	in_addr.setZip(tmp);

	return (is);
}