// CategorizedContact class implementation

#include "CategorizedContact.h"

CategorizedContact::CategorizedContact() : Contact()
{
	category = "Unknown";
}

CategorizedContact::CategorizedContact(Field categoryIn)
{
	category = categoryIn;
}

// Access functions
Field CategorizedContact::getCategorizedContact() const
{
	return category;
}

// Set functions
void CategorizedContact::setCategorizedContact(Field categoryIn)
{
	category = categoryIn;
}

// Other member functions
Field CategorizedContact::toString() const
{
	Field categorizedContact;
	categorizedContact = "Category: " + category + "\n" + Contact::toString();
	return categorizedContact;
}

Field CategorizedContact::toFileString() const
{
	Field categorizedContact;
	categorizedContact = category + "," + Contact::toFileString();
	return categorizedContact;
}

// Operator overloaded functions
ostream &operator << (ostream &os, const CategorizedContact &out_catCon)
{
	os << out_catCon.toString() << endl;
	return (os);
}
istream &operator >> (istream &is, CategorizedContact &in_catCon)
{
	Contact tmpContact;

	is >> in_catCon.category;

	is >> tmpContact;

	in_catCon.setFullName(tmpContact.getFullName());
	in_catCon.setFullAddress(tmpContact.getFullAddress());
	in_catCon.setPhoneNumber(tmpContact.getPhoneNumber());
	in_catCon.setEmail(tmpContact.getEmail());
	in_catCon.setBirthday(tmpContact.getBirthday());
	in_catCon.setPictureFile(tmpContact.getPictureFile());
	
	return (is);
}
ofstream &operator << (ofstream &os, const CategorizedContact &out_catCon)
{
	os << "" << out_catCon.toFileString() << endl;
	return (os);
}
ifstream &operator >> (ifstream &is, CategorizedContact &in_catCon)
{
	Contact tmpContact;

	is >> in_catCon.category;

	is >> tmpContact;

	in_catCon.setFullName(tmpContact.getFullName());
	in_catCon.setFullAddress(tmpContact.getFullAddress());
	in_catCon.setPhoneNumber(tmpContact.getPhoneNumber());
	in_catCon.setEmail(tmpContact.getEmail());
	in_catCon.setBirthday(tmpContact.getBirthday());
	in_catCon.setPictureFile(tmpContact.getPictureFile());

	return (is);
}
