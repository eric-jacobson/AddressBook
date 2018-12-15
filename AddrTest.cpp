/*
Name: Eric Jacobson
Course: CSC 161-001
Program Name: AddrBook Project 4
Program Description: Address book to store contact information including a category, first name, last name, street address, city, state,
					 zip code, phone number, email address, birthday and a picture file. Contacts can be displayed by category or the full
					 list can be displayed at one time. Contact data is stored in file "address.csv", data from this file will be read when 
					 program executes, the entire file will be written over when program exits. 
Program Date: 11/9/2016

Main Source:
	Developer:		Scott Miner
	Scott's Source: http://stackoverflow.com/questions/1798112/removing-leading-and-trailing-spaces-from-a-string,
					Jones, B. L., Aitken, P., & Miller, D. (2014). Sames Teach Yourself C Programming In One Hour a Day (7th ed.). Indianapolis, IN: Sams Publishing.
					Forouzan, B. A., & Gilberg, R. F. (2007). Computer science: A structured programming approach using C. Boston, MA: Thomson Course Technology.
*/

#include <cstdlib>
#include <fstream>
#include <iostream> //provides cout and cin
#include <sstream>  //provides stringstream
#include <string>
using namespace std;
#include "AddrBook.h"
#include "Address.h"
#include "CategorizedContact.h"
#include "Contact.h"
#include "Field.h"
#include "Name.h"

using namespace std;

//PROTOTYPES for functions used by this demonstration program:

int menu(void);
//Postcondition: An integer is returned representing the user's menu choice

void delay(void);
//Postcondition: The program has been delayed for the specified amount of time

void addNewContact(AddrBook& myAddrBook);
//Precondition: getUsed() <= Capacity
//Postcondition: A new contact has been added into the bag

void printUsed(AddrBook& myAddrBook);
//Postcondition: The number of entries in the address book is printed to the console window

void removeContacts(AddrBook& myAddrBook);
//Postcondition: If the entry is a valid entry, the entry is removed from the address book

string trim(const std::string& str, const std::string& whitespace = " \t");
//Postcondition: leading and trailing white space have been removed from the string

string reduce(const std::string& str, const std::string& fill = " ", const std::string& whitespace = " \t");
//Postcondition: leading and trailing white space have been removed from the string and any additional spaces
//between words have been removed from the string as well

int main(int argc, const char * argv[])
{
	int command = 0;
	Field catTmp;
	AddrBook myAddrBook;

	//open the file for reading
	myAddrBook.readFile("address.csv");

	//call the menu function and get response
	command = menu();

	//take appropriate action based on user response
	while (command != 5)
	{
		switch (command)
		{
		case 1:
			addNewContact(myAddrBook);
			break;
		case 2:
			printUsed(myAddrBook);
			break;

		case 3:// !!!! NEED TO FINSIH FOR PRINTING BY CATEGORY !!!!
		{
			cout << "\n\tPrinting...\n";
			delay();

			//for (int i = 0; i < MAX; i++)
			//	if (category == myAddrBook.getItem(i).getCategorizedContact())
			//		myAddrBook.PrintByCategorizedContact();

			myAddrBook.PrintAllContacts();
			cout << "\tReturning to Main Menu...\n\n";
			delay();
			break;
		}
		case 4:
			removeContacts(myAddrBook);
			break;

		default:
			cout << "\n\tInvalid entry, please try again.\n";
			cout << "\tReturning to Main Menu...\n";
			delay();
			break;
		}

		command = menu();
	}

	//when program is exited, write the file before leaving
	myAddrBook.writeFile("address.csv");
	delay();

	return 0;
}

int menu(void)
{
	Field reply;
	int choice;

	cout << "\t****************************************************************" << endl;
	cout << "\t*                          MENU                                *" << endl;
	cout << "\t*                                                              *" << endl;
	cout << "\t*   1.  Add a new Contact to the Address Book                  *" << endl;
	cout << "\t*   2.  Find out how many Contacts are in this AddressBook     *" << endl;
	cout << "\t*   3.  Print out all the contacts in the AddressBook          *" << endl;
	cout << "\t*   4.  Delete a Contact from the AddressBook                  *" << endl;
	cout << "\t*   5.  Exit the Program                                       *" << endl;
	cout << "\t*                                                              *" << endl;
	cout << "\t****************************************************************" << endl;
	cout << "\n\tPlease enter your selection: ";

	cin >> reply;

	//converts the number into an integer for processing
	stringstream(reply) >> choice;

	return choice;
}

void printUsed(AddrBook& myAddrBook)
{
	//Prints a message to the console window

	cout << "\n";
	cout << "\t****************************************************************\n";
	cout << "\t*                                                              *\n";
	cout << "\t*  Address Book contains " << myAddrBook.CountItems() << " contact(s).                         *\n";
	cout << "\t*                                                              *\n";
	cout << "\t****************************************************************\n";

	cout << "\n\tReturning to Main Menu....\n\n";
	delay();
}

void addNewContact(AddrBook& myAddrBook)
{
	
	Name newName;
	Address newAddress;
	Contact newContact;
	Field answer;
	Field category;
	Field choice;
	CategorizedContact newCategorizedContact;

	cout << "\n";
		
	//Get all the contact user from the user, trim and reduce white space, set contact information for the new contact
	
	// Category menu options
	cout << "\t****************************************************************" << endl;
	cout << "\t*															   " << endl;
	cout << "\t*   Categories:												   " << endl;
	cout << "\t*   a) Work                                                     " << endl;
	cout << "\t*   b) Family												   " << endl;
	cout << "\t*   c) Friend												   " << endl;
	cout << "\t*   d) Other 												   " << endl;
	cout << "\t*															   " << endl;
	cout << "\t****************************************************************" << endl;
	cout << "\n\t*   Select a category: ";
	
	cin >> choice;		
	
	if (choice == "a")
	{
		category = "Work";
	}
	else if (choice == "b")
	{
		category = "Family";
	}
	else if (choice == "c")
	{
		category = "Friend";
	}
	else 
	{
		category = "Other";
	}

	cout << "\t*\n";

	cout << "\t*   Enter First Name: ";
	getline(cin, answer);
	answer = reduce(answer);
	newName.setFirstName(answer);
	cout << "\t*\n";

	cout << "\t*   Enter Last Name: ";
	getline(cin, answer);
	answer = reduce(answer);
	newName.setLastName(answer);
	cout << "\t*\n";

	cout << "\t*   Enter Street Address: ";
	getline(cin, answer);
	answer = reduce(answer);
	newAddress.setStreetAddress(answer);
	cout << "\t*\n";

	cout << "\t*   Enter City: ";
	getline(cin, answer);
	answer = reduce(answer);
	newAddress.setCity(answer);
	cout << "\t*\n";

	cout << "\t*   Enter State: ";
	getline(cin, answer);
	answer = reduce(answer);
	newAddress.setState(answer);
	cout << "\t*\n";

	cout << "\t*   Enter Zip: ";
	getline(cin, answer);
	answer = trim(answer);
	newAddress.setZip(answer);
	cout << "\t*\n";

	cout << "\t*   Enter Phone Number: ";
	getline(cin, answer);
	answer = trim(answer);
	newCategorizedContact.setPhoneNumber(answer);
	cout << "\t*\n";

	cout << "\t*   Enter Email Address: ";
	getline(cin, answer);
	answer = trim(answer);
	newCategorizedContact.setEmail(answer);
	cout << "\t*\n";

	cout << "\t*   Enter Birthday: ";
	getline(cin, answer);
	answer = trim(answer);
	newCategorizedContact.setBirthday(answer);
	cout << "\t*\n";

	cout << "\t*   Enter Picture File: ";
	getline(cin, answer);
	answer = trim(answer);
	newCategorizedContact.setPictureFile(answer);
	cout << "\t*\n";
	cout << "\t****************************************************************\n\n";

	//update full name and address for the new contact
	newCategorizedContact.setCategorizedContact(category);
	newCategorizedContact.setFullName(newName);
	newCategorizedContact.setFullAddress(newAddress);

	//add the contact to the address book
	myAddrBook.AddContact(newCategorizedContact);

	//confirmation of contact added
	cout << "\tContact has been added.\n";
	cout << "\tReturning to Main Menu...\n\n";

	delay();
}

void removeContacts(AddrBook& myAddrBook)
{
	Field answer;
	int choiceRemove = 0;

	cout << "\n\tPrinting Contacts...\n";
	delay();

	//print the contacts so user has a reference of what he is removing
	myAddrBook.PrintAllContacts();

	//if user attempts to remove 0 entries from the address book
	if (myAddrBook.CountItems() == 0) {
		cout << "\tPlease add a contact to the address book before proceeding.";
		cout << "\n\tReturning to Main Menu....\n\n";
		delay();
		return;
	}

	//prompt for entry number
	cout << "\tEnter the number of the entry you would like to delete: ";
	getline(cin, answer);

	//convert the string into an integer for processing
	stringstream(answer) >> choiceRemove;
	choiceRemove--;

	//call remove by index function, error processing is handled in the function
	myAddrBook.RemoveByIndex(choiceRemove);

	delay();
}

string reduce(const std::string& str, const std::string& fill, const std::string& whitespace)
{
	//function from http://stackoverflow.com/questions/1798112/removing-leading-and-trailing-spaces-from-a-string
	// removes trailing and leading white spaces and any additional spaces the user might hit between words
	// (ie. [  Scott       Miner   ] = [Scott Miner]

	// trim first
	auto result = trim(str, whitespace);

	// replace sub ranges
	auto beginSpace = result.find_first_of(whitespace);
	while (beginSpace != std::string::npos)
	{
		const auto endSpace = result.find_first_not_of(whitespace, beginSpace);
		const auto range = endSpace - beginSpace;

		result.replace(beginSpace, range, fill);

		const auto newStart = beginSpace + fill.length();
		beginSpace = result.find_first_of(whitespace, newStart);
	}

	return result;
}

string trim(const string& str, const string& whitespace)
{
	//function from http://stackoverflow.com/questions/1798112/removing-leading-and-trailing-spaces-from-a-string
	// removes trailing and leading white spaces
	// ie. [   Scott Miner     ] = [Scott Miner]

	const auto strBegin = str.find_first_not_of(whitespace);
	if (strBegin == string::npos)
		return ""; // no content

	const auto strEnd = str.find_last_not_of(whitespace);
	const auto strRange = strEnd - strBegin + 1;

	return str.substr(strBegin, strRange);
}

void delay(void)
{
	long DELAY = 1500000000;

	long x;

	for (x = 0; x < DELAY; x++)
	{
		;
	}
}






// OLD ADDRBOOK FULL MESSAGE
//
//
//if the address book is full, alert the user - !!!!! CHANGING TO DYNAMIC ARRAY !!!!!
//if (myAddrBook.CountItems() >= max)
//{
//	cout << "\t****************************************************************\n";
//	cout << "\t*                                                              *\n";
//	cout << "\t*   Address Book is full.                                      *\n";
//	cout << "\t*   Please remove 1 or more entries before adding any more.    *\n";
//	cout << "\t*                                                              *\n";
//	cout << "\t****************************************************************\n";
//	cout << "\n\tReturning to Main Menu....\n\n";
//	delay();
//	return;
//}