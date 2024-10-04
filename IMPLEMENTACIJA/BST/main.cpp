#include "BSTreeInt.h"

void main()
{
	BSTreeInt stablo;

	
	stablo.insert(4);
	stablo.insert(3);
	stablo.insert(6);
	stablo.insert(7);
	stablo.insert(5);
	stablo.insert(8);

	stablo.preorder();
	cout << "\n\n";


	/*
	
	    4
     / \
    3   6            <- izgled stabla
       / \
      5   7
           \
            8
	*/

}
