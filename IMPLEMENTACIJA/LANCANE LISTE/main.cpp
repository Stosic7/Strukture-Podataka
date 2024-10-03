#include "LList.h"

int main()
{
	LList* list = new LList();
	list->addToHead(3);
	list->addToHead(4);
	list->addToHead(2);
	list->addToHead(3);
	list->addToHead(2);
	list->addToHead(1);
	list->printAll();


	LList* list2 = new LList();
	list2->addToHead(4);
	list2->addToHead(3);
	list2->addToHead(2);
  list2->printAll();

	return 0;
}
