#include "String.h"
#include <iostream>

String::String() : length{ 0 }, cstr{ nullptr } {}

String::String(const char* cstr) : length{ (int)strlen(cstr) }
{
	this->cstr = new char[length + 1];
	for (int i = 0; i < length; i++)
		this->cstr[i] = cstr[i];
	this->cstr[length] = '\0';
}

String::String(const String& str) : String(str.cstr) {}
/*
String::String(const String& str) : length{ str.length }
{
	this->cstr = new char[length + 1];
	for (int i = 0; i < length; i++)
		this->cstr[i] = str.cstr[i];
	this->cstr[length] = '\0';
}
*/

String::String(char symbol, int count) : length{ count }
{
	this->cstr = new char[length + 1];
	for (int i = 0; i < length; i++)
		this->cstr[i] = symbol;
	this->cstr[length] = '\0';
}

String::~String()
{
	if (cstr)
		delete[] cstr;
}

String String::operator=(const char* cstr)
{
	if (this->cstr)
		delete[] this->cstr;

	this->length = strlen(cstr);
	this->cstr = new char[length + 1];

	for (int i = 0; i < length; i++)
		this->cstr[i] = cstr[i];
	this->cstr[length] = '\0';

	return *this;
}

String String::operator=(const String& str)
{
	if (&str != this)
		*this = str.cstr;

	return *this;
}

char& String::operator[](int index)
{
	return cstr[index];
}

char& String::At(int index)
{
	if (index >= 0 && index < length)
		return cstr[index];
}

int String::Length() const
{
	return length;
}

String String::operator+=(String str)
{
	*this = *this + str;
	return *this;
}

String String::operator*(int count)
{
	String strResult;
	strResult.length = this->length * count;
	strResult.cstr = new char[strResult.length + 1];
	
	int index{};
	for (int c = 0; c < count; c++)
		for (int i = 0; i < this->length; i++)
			strResult[index++] = this->cstr[i];

	strResult.cstr[strResult.length] = '\0';

	return strResult;
}

String operator+(String str1, String str2)
{
	String strResult;
	strResult.length = str1.length + str2.length;

	strResult.cstr = new char[strResult.length + 1];
	
	int index{};
	for (int i = 0; i < str1.length; i++)
		strResult.cstr[index++] = str1.cstr[i];
	for (int i = 0; i < str2.length; i++)
		strResult.cstr[index++] = str2.cstr[i];

	strResult.cstr[strResult.length] = '\0';

	return strResult;
}

std::ostream& operator<<(std::ostream& out, String& str)
{
	out << str.cstr;
	return out;
}
