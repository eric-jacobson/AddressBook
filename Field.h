#ifndef FIELD_H
#define FIELD_H
#include <cctype> //toupper
#include <fstream> // ifstream
#include <iostream>	// istream
#include <string>
using namespace std;

class Field : public string 
{
public:
	Field(); // default constructor
	Field(const char* c_str);
	Field(const string& str); // Field(string str)
private: 
	// no data members
};

istream& operator >> (istream& is, Field& fld);
ifstream& operator >> (ifstream& is, Field& fld);
Field toUpper(const Field& fld);

#endif

