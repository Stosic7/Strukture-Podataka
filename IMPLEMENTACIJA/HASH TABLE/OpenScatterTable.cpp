#include "OpenScatterTable.h"
using namespace std;


OpenScatterTable::OpenScatterTable(unsigned int length)
{
	count = 0;
	m = length;
	array = new ScatterObject[m];
}


OpenScatterTable::~OpenScatterTable()
{
	if (array) delete[] array;
}

unsigned int OpenScatterTable::c(unsigned int i)
{
	return 3 * i;
}

void OpenScatterTable::print()
{
	for (unsigned int i = 0; i < m; i++)
	{
		cout << i << " ";
		array[i].print();
	}
}
