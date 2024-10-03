#include"HashTable.h"

unsigned int HashTable::h(const char* key)
{
	return g(f(key));
}

unsigned int HashTable::f(const char* key)
{
	
	unsigned int h = 0;
	for (int i = 0; i < strlen(key); i++)
		h += key[i];
	return h;
}

unsigned int HashTable::g(unsigned int key)
{
	
	return key % m;
}
