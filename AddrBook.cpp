// AddrBook.cpp AddrBook class implementations

#include "AddrBook.h"

AddrBook::AddrBook()
{
	contactsPtr = NULL;
	used = 0;
	max = 0;
}

AddrBook::AddrBook(const AddrBook & source)	// copy constructor
{
	contactsPtr = new CategorizedContact[source.max];
	used = 0;
	max = source.max;
	for (int i = 0; i < source.used; i++)
		AddContact(source.contactsPtr[i]);
}

AddrBook& AddrBook::operator=(const AddrBook& source)	// assignment operator
{
	// check for self assignment
	if (this == &source)
		return (*this);
	// remove all existing memory for this
	free();
	used = 0;
	max = source.max;
	contactsPtr = new CategorizedContact[max];
	for (int i = 0; i < source.used; i++)
		AddContact(source.contactsPtr[i]);
}

AddrBook::~AddrBook()	// Destructor
{
	free();
}

void AddrBook::AddContact(CategorizedContact contactToAdd)
{
	if (used == max)		// check to see if full or no memory
		alloc(2);
	contactsPtr[used++] = contactToAdd;	

}

void AddrBook::alloc(int sizeIncrease)
{
	max += sizeIncrease;
	CategorizedContact * tmp = new CategorizedContact[max];
	copy(contactsPtr, contactsPtr + used, tmp);	// algorithm library
	free();
	contactsPtr = tmp;
}

void AddrBook::free()
{
	if (contactsPtr != NULL)
	{
		delete[] contactsPtr;
		contactsPtr = NULL;
	}
}

void AddrBook::PrintAllContacts()
{
	if (used == 0)
	{
		cout << "\t****************************************************************\n";
		cout << "\t*                                                              *\n";
		cout << "\t*   No contacts.					                              *\n";
		cout << "\t*                                                              *\n";
		cout << "\t****************************************************************\n";

		return;
	}
	/*cout << "\nContacts List\n";*/
	for (int i = 0; i < used; i++)
		cout << (i + 1) << ")\n" << contactsPtr[i].toString() << endl;

}

void AddrBook::PrintByCategorizedContact(Field category)
{
	if (used == 0)
	{
		cout << "\t****************************************************************\n";
		cout << "\t*                                                              *\n";
		cout << "\t*   No contacts.					                              *\n";
		cout << "\t*                                                              *\n";
		cout << "\t****************************************************************\n";
		
		return;
	}
	for (int i = 0; i < used; i++)
		cout << (i + 1) << ")\n" << contactsPtr[i].toString() << endl;
}

void AddrBook::RemoveByIndex(int index)
{
	if (index >= 0 && index < used)
		contactsPtr[index] = contactsPtr[--used];
}

void AddrBook::RemoveByItem(CategorizedContact contactToRemove)
{
	int index = FindItem(contactToRemove);
	if (index != -1)
		RemoveByIndex(index);

}

int AddrBook::FindItem(CategorizedContact contactToFind)
{
	int index = 0;
	for (int i = 0; i < used; i++) // traverse through the array
		if (contactToFind.toString() == contactsPtr[i].toString())
			return i; // index of the array found
	cout << "\t****************************************************************\n";
	cout << "\t*                                                              *\n";
	cout << "\t*   Item not found.                                            *\n";
	cout << "\t*                                                              *\n";
	cout << "\t****************************************************************\n";

	return -1;
}



CategorizedContact AddrBook::getItem(int index)
{
	return CategorizedContact();
}

void AddrBook::readFile(Field fileName, char delimeter)
{
	CategorizedContact categorizedContactTmp;

	ifstream inFile(fileName.c_str());
	if (!inFile)
	{
		cout << "\t****************************************************************\n";
		cout << "\t*                                                              *\n";
		cout << "\t*   Error opening file for reading.                            *\n";
		cout << "\t*                                                              *\n";
		cout << "\t****************************************************************\n";
		return;
	}
	inFile >> categorizedContactTmp;
	while (!inFile.fail())
	{
		//add the categorized contact to the address book from read file
		AddContact(categorizedContactTmp);

		//get the next contact from file
		inFile >> categorizedContactTmp;
	}
	
	inFile.close();
}

void AddrBook::writeFile(Field fileName, char delimeter)
{
	ofstream outFile(fileName.c_str());
	if (!outFile)
	{
		cout << "\t****************************************************************\n";
		cout << "\t*                                                              *\n";
		cout << "\t*   Error opening file for writing.                            *\n";
		cout << "\t*                                                              *\n";
		cout << "\t****************************************************************\n";
			return;
	}
	for (int i = 0; i < used; i++)
		outFile << "" << contactsPtr[i].toFileString() << endl;
	outFile.close();
}




// OLD READFILE CODE
/*
getline(inFile, tmpField, ',');
categorizedContactTmp.setCategorizedContact(tmpField);

getline(inFile, tmpField, ',');
nameTmp.setFirstName(tmpField);

getline(inFile, tmpField, ',');
nameTmp.setLastName(tmpField);

getline(inFile, tmpField, ',');
addrTmp.setStreetAddress(tmpField);

getline(inFile, tmpField, ',');
addrTmp.setCity(tmpField);

getline(inFile, tmpField, ',');
addrTmp.setState(tmpField);

getline(inFile, tmpField, ',');
addrTmp.setZip(tmpField);

getline(inFile, tmpField, ',');
categorizedContactTmp.setPhoneNumber(tmpField);

getline(inFile, tmpField, ',');
categorizedContactTmp.setEmail(tmpField);

getline(inFile, tmpField, ',');
categorizedContactTmp.setBirthday(tmpField);

getline(inFile, tmpField, ',');
categorizedContactTmp.setPictureFile(tmpField);

//update full name and address for the new contact from read file
categorizedContactTmp.setFullName(nameTmp);
categorizedContactTmp.setFullAddress(addrTmp);

*/