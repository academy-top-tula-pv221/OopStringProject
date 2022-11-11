#include <iostream>
#pragma once
class String
{
	char* cstr;
	int length;
public:
	String();
	String(const char*);
	String(const String&);
	String(char, int);
	~String();

	String operator=(const char*);
	String operator=(const String&);
	char& operator[](int);
	char& At(int);

	int Length() const;

	friend String operator+(String, String);
	friend std::ostream& operator<<(std::ostream&, String&);

	String operator+=(String);
	String operator*(int);

	friend bool operator>(String, String);
	friend bool operator<(String, String);
	friend bool operator>=(String, String);
	friend bool operator<=(String, String);
	friend bool operator==(String, String);
	friend bool operator!=(String, String);

	void Clear();
	void Append(char);
	void Append(String);

	void Insert(int, char);
	void Insert(int, String);

	String Replace(int index, int count);
	String Substr(int index, int count);
	
	int Find(String str, int index = 0);
	int ReverseFind(String str, int index = 0);
};

