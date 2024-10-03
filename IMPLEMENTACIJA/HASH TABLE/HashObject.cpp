#define _CRT_SECURE_NO_WARNINGS
#include "HashObject.h"
using namespace std;
HashObject::HashObject()
{
	key = new char[1];
	key[0] = '\0';
}

HashObject::HashObject(const char* k)
{
	key = new char[strlen(k) + 1];
	strcpy(key, k);
}

HashObject::~HashObject()
{
	if (key) delete[] key;
}

HashObject::HashObject(HashObject const& obj)
{
	key = strcpy(new char[strlen(obj.key) + 1], obj.key);
}

HashObject& HashObject::operator = (HashObject const& obj)
{
	if (this != &obj)
	{
		if (key) delete[] key;
		  key = new char[strlen(obj.key) + 1];
		  strcpy(key, obj.key);
	return *this;
}

bool HashObject::operator == (HashObject const& obj)
{
	return (strcmp(this->key, obj.key) == 0)
}

void HashObject::deleteRecord() {
}

void HashObject::print()
{
	if (key != NULL)
	{
		cout << key;
	}
	cout << endl;
}
