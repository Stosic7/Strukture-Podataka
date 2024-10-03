#pragma once
#include "HashTable.h"
#include "ScatterObject.h"
class OpenScatterTable :
	public HashTable
{
protected:
	ScatterObject* array;
public:
	OpenScatterTable(unsigned int length);
	~OpenScatterTable();
	unsigned int c(unsigned int i);
	void print();

  // ovde zadajete funkcije koja se trazi u zadatku i impelemenirate je u .cpp fajl i pozovete u main.
};
