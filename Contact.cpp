// Contact.cpp  Contact class implementation

#include "Contact.h"

// Constructors
Contact::Contact()
{
	phoneNumber = "Unknown";
	emailAddress = "Unknown";
	birthday = "Unknown";
	pictureFile = "Unknown";
}

Contact::Contact(Field phoneIn, Field emailIn, Field birthdayIn, Field pictureIn)
{
	phoneNumber = phoneIn;
	emailAddress = emailIn;
	birthday = birthdayIn;
	pictureFile = pictureIn;
}

Contact::Contact(Address fullAddrIn, Name fullNameIn)
{
	fullAddress = fullAddrIn;
	fullName = fullNameIn;
	
}

// Access functions
Field Contact::getPhoneNumber() const
{
	return phoneNumber;
}

Field Contact::getEmail() const
{
	return emailAddress;
}

Field Contact::getBirthday() const
{
	return birthday;
}

Field Contact::getPictureFile() const
{
	return pictureFile;
}

Name Contact::getFullName() const
{
	return fullName;
}

Address Contact::getFullAddress()const
{
	return fullAddress;
}
// Set functions
void Contact::setPhoneNumber(Field phoneIn)
{
	phoneNumber = phoneIn;
}

void Contact::setEmail(Field emailIn)
{
	emailAddress = emailIn;
}

void Contact::setBirthday(Field birthdayIn)
{
	birthday = birthdayIn;
}

void Contact::setPictureFile(Field pictureIn)
{
	pictureFile = pictureIn;
}

void Contact::setFullName(Name fullNameIn)
{	
	fullName = fullNameIn;
}

void Contact::setFullAddress(Address fullAddressIn)
{
	fullAddress = fullAddressIn;
}

Field Contact::toString() const
{
	Field contact;
	contact = "    Name: " + fullName.toString() + "\n Address: " + fullAddress.toString() + "\n   Phone: "
		+ phoneNumber + "\n   Email: " + emailAddress + "\nBirthday: " + birthday + "\nPictFile: " + pictureFile + "\n";
	return contact;
}

Field Contact::toFileString() const
{
	Field contact;
	contact = fullName.toFileString() + fullAddress.toFileString() + phoneNumber + "," 
		+ emailAddress + "," + birthday + "," + pictureFile + ",";
	return contact;
}

// Operator overloaded functions
bool operator==(const Contact& contact1, const Contact& contact2)
{
	if (contact1.fullName == contact2.fullName)
		return(true);
	return(false);
}
bool operator!=(const Contact& contact1, const Contact& contact2)
{
	return!(contact1.fullName == contact2.fullName);
}
bool operator<(const Contact& contact1, const Contact& contact2)
{
	if (contact1.fullName < contact2.fullName)
		return(true);
	return(false);
}
bool operator<=(const Contact& contact1, const Contact& contact2)
{
	return(contact1.fullName < contact2.fullName || contact1.fullName == contact2.fullName);
}
bool operator>(const Contact& contact1, const Contact& contact2)
{
	if (contact1.fullName > contact2.fullName)
		return(true);
	return(false);
}
bool operator>=(const Contact& contact1, const Contact& contact2)
{
	return(contact1.fullName > contact2.fullName || contact1.fullName == contact2.fullName);
}

ostream &operator << (ostream &os, const Contact &out_contact)
{
	os << out_contact.toString() << endl;
	return (os);
}
istream &operator >> (istream &is, Contact &in_contact)
{
	Field tmp;

	is >> in_contact.fullName;

	is >> in_contact.fullAddress;

	is >> tmp;
	in_contact.setPhoneNumber(tmp);

	is >> tmp;
	in_contact.setEmail(tmp);

	is >> tmp;
	in_contact.setBirthday(tmp);

	is >> tmp;
	in_contact.setPictureFile(tmp);

	return (is);
}
ofstream &operator << (ofstream &os, const Contact &out_contact)
{
	os << out_contact.toFileString() << endl;
	return (os);
}
ifstream &operator >> (ifstream &is, Contact &in_contact)
{
	Field tmp;

	is >> in_contact.fullName;

	is >> in_contact.fullAddress;

	is >> tmp;
	in_contact.setPhoneNumber(tmp);

	is >> tmp;
	in_contact.setEmail(tmp);

	is >> tmp;
	in_contact.setBirthday(tmp);

	is >> tmp;
	in_contact.setPictureFile(tmp);

	return (is);
}