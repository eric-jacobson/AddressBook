#include "Field.h"

Field::Field() : string()
{}

Field::Field(const char* c_str) : string(c_str)
{}

Field::Field(const string& str) : string(str)
{}

istream& operator >> (istream& is, Field& fld)
{
	if (is.peek() == '\n')
		is.ignore();
	getline(is, fld);
	return is;
}

ifstream& operator >> (ifstream& is, Field& fld)
{
	if (is.peek() == '\n')
		is.ignore();
	getline(is, fld, ',');
	return is;
}

Field toUpper(const Field& fld)
{
	Field tmp = fld;
	for (int i = 0; i < fld.length(); i++)
		tmp[i] = toupper(fld[i]);
	return tmp;
}