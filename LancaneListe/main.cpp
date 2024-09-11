//Proba commita
#include "LList.h"

int main()
{
	LList *list = new LList();
	list->addToHead(0);
	list->addToHead(9);
	list->addToHead(6);
	list->addToHead(8);
	list->addToHead(8);
	list->addToHead(9);
	list->addToHead(1);
	list->addToHead(8);
	list->addToHead(0);
	list->addToHead(1);

	
	list->printAll();
	/*LList* list2 = new LList();
	list2->addToHead(5);
	list2->addToHead(4);
	list2->addToHead(3);
	list2->addToHead(2);
	list2->addToHead(1);
	list2->printAll();*/
	
	list->groupElements();
	list->printAll();
	return 0;
}
