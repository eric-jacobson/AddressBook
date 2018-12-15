// CategorizedContact class declarations

#ifndef CATEGORIZEDCONTACT_H
#define CATEGORIZEDCONTACT_H

#include <fstream>
#include <iostream>
using namespace std;
#include "Contact.h"
#include "Field.h"

class CategorizedContact : public Contact
{
public:
	CategorizedContact();
	CategorizedContact(Field categoryIn);
	
	// Access functions
	Field getCategorizedContact() const;

	// Set functions
	void setCategorizedContact(Field categoryIn);

	// Other member functions
	Field toString() const;
	Field toFileString() const;

	// Operator overloaded functions
	friend ostream &operator << (ostream &os, const CategorizedContact &out_catCon);
	friend istream &operator >> (istream &is, CategorizedContact &in_catCon);
	friend ofstream &operator << (ofstream &os, const CategorizedContact &out_catCon);
	friend ifstream &operator >> (ifstream &is, CategorizedContact &in_catCon);

private:
	Field category;
		
};
#endif