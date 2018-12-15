// AddrBook.h AddrBook class declarations

#ifndef ADDRBOOK_H
#define ADDRBOOK_H
#define _SCL_SECURE_NO_WARNINGS

#include <algorithm>	// used for copy function
#include <cstdlib>		// NULL
#include <fstream>	
#include <iostream>
#include <string>
using namespace std;
#include "Address.h"
#include "CategorizedContact.h"
#include "Contact.h"
#include "Field.h"
#include "Name.h"

//#define MAX 5 // fixed array size	

class AddrBook
{
public:
	AddrBook();  // Empty container to start
	AddrBook(const AddrBook & source);	// copy constructor
	AddrBook& operator=(const AddrBook& source);	// assignment operator
	~AddrBook();

	void AddContact(CategorizedContact contactToAdd); // add one contact 
	void PrintAllContacts(); // print all items to console window
	void PrintByCategorizedContact(Field category); // print all items from a given category selected by the user
	void RemoveByIndex(int index);
	void RemoveByItem(CategorizedContact contactToRemove);
	int FindItem(CategorizedContact contactToFind);
	int CountItems() const { return used; } // getUsed

	CategorizedContact getItem(int index);

	void readFile(Field fileName, char delimeter = ',');
	void writeFile(Field fileName, char delimeter = ',');

private:
	CategorizedContact* contactsPtr;	// static array - fixed size of max
	int used; // track how many items are in the array
	int max; // variable for array size
	
	void alloc(int sizeToIncrease);
	void free();
};
#endif
