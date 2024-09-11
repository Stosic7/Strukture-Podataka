#include "LList.h"


LList::LList()
{
	head=NULL;
}


LList::~LList()
{
	while(!isEmpty())
	{
		int tmp = deleteFromHead();
	}
}


bool LList::isEmpty()
{
	return head==NULL;
}

void LList::addToHead(int el)
{
	head = new LListNode(el, head);
}

void LList::addToTail(int el)
{
	if(!isEmpty())
	{
		LListNode* tmp = head;
		while(tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new LListNode(el);
	}
	else
		addToHead(el);
}

int LList::deleteFromHead()
{
	if(isEmpty())
		throw new exception("List is empty");
	int el = head->info;
	LListNode *tmp = head;
	head = head->next;
	delete tmp;
	return el;
}

int LList::deleteFromTail()
{
	if(isEmpty())
		throw new exception("List is empty");
	int el;
	if (head->next == NULL)
	{
		el = head->info;
		delete head;
		head = NULL;
	}
	else
	{
		LListNode* prev = head;
		LListNode *tmp = head;
		while (tmp->next != NULL)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		el = tmp->info;
		delete tmp;
		prev->next = NULL;
	}
	return el;
}

LListNode* LList::findNodePtr(int el)
{
	if(isEmpty())
		throw new exception("List is empty");
	LListNode *ret = head;
	while(ret!=NULL && ret->info!=el)
	{
		ret = ret->next;
	}
	return ret;
}

LListNode* LList::getHead()
{
	return head;
}

LListNode* LList::getNext(LListNode* ptr)
{
	if(isEmpty())
		throw new exception("List is empty");
	return ptr->next;
}

int LList::getHeadEl()
{
	if(isEmpty())
		throw new exception("List is empty");
	return head->info;
}

int LList::getNextEl(int el)
{
	if(isEmpty())
		throw new exception("List is empty");
	LListNode* tmp = findNodePtr(el);
	if(tmp==NULL)
		throw new exception("Node doesn't exist");
	if(tmp->next == NULL)
		throw new exception("Element doesn't have next node");
	return tmp->next->info;
}

void LList::printAll()
{
	LListNode *tmp = head;
	while(tmp!=NULL)
	{
		cout<<tmp->print() << " ";
		tmp=tmp->next;
	}
	cout << endl;
}

bool LList::isInList(int el)
{
	if(isEmpty())
		return false;
	LListNode* tmp = findNodePtr(el);
	if(tmp==NULL)
		return false;
	else
		return true;
}

void LList::deleteEl(int el)
{
	if (!isEmpty())
	if (head->isEqual(el)) 
	{
		LListNode *tmp = head;
		head = head->next;
		delete tmp;
	}
	else 
	{
		LListNode *pred, *tmp; 
		for (pred = head, tmp = head->next; tmp != NULL && !(tmp->isEqual(el));
			  pred = pred->next, tmp = tmp->next);
		if (tmp != NULL) 
		{
			pred->next = tmp->next;
			delete tmp;
		}
    }
}

LListNode* LList::removeNodeFromHead()
{
	if(isEmpty())
		return NULL;
	LListNode *tmp = head;
	head = head->next;
	return tmp;
}



void LList::concatenateParts(LList* list2, int k)
{
	LListNode* tmp1 = head;
	LListNode* tmp2 = list2->head;
	
	LListNode* levo1;
	LListNode* levo2;
	LListNode* desno1;
	LListNode* desno4;
	LListNode* desno3;
	int i = 1;
	while (i < k)
	{
		i = 1;
		while (tmp1->info != tmp2->info)
		{
			//pred = tmp1;
			tmp1 = tmp1->next;
		}
		while (tmp1 != nullptr && tmp2 != nullptr && tmp1->info == tmp2->info)
		{
			i++;
			levo1 = tmp1;
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
		}
		levo2 = tmp1;
	}

	while (tmp1 != nullptr)
	{
		tmp2 = list2->head;
		i = 1;
		while (tmp1!= nullptr && tmp1->info != tmp2->info)
		{
			desno1 = tmp1;
			tmp1 = tmp1->next;
			
		}
		while (tmp1 != nullptr && tmp2 != nullptr && tmp1->info == tmp2->info)
		{
			i++;
			desno3 = tmp1;
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
		}
		if (tmp1 == nullptr)
			break;
		if (i < k)
		{
			tmp1 = tmp1->next;
		}
		else
		{
			desno4 = desno3->next;
			levo1->next = desno1->next;
			desno1->next = desno3->next;
			desno3->next = levo2;

			levo1 = desno3;
			levo2 = desno4;
		}
	}
}

bool LList::moveSectionToHead(int start, int end)
{
	LListNode* cur = head;
	LListNode* prev;
	LListNode* kraj = head;

	while (cur->info != start)
	{
		prev = cur;
		cur = cur->next;
		
	}

	while (kraj->info != end)
	{
		if (kraj->next == nullptr)
			return 0;
		kraj = kraj->next;
	}
	if (cur == head)
		return 1;

	prev->next = kraj->next;
	kraj->next = head;
	head = cur;

	return 1;
}

int LList::SwapPairs(int data1, int data2)
{
	int brojac = 0;
	LListNode* cur = head;
	LListNode* next;
	LListNode* prev;
	while (cur->info != data1)
	{
		prev = cur;
		cur = cur->next;
		if (cur == nullptr)
			return 0;
	}
	next = cur->next;
	while (cur->info != data2)
	{
		prev->next = next;
		cur->next = next->next;
		next->next = cur;

		prev = cur;
		cur = cur->next;
		next = cur->next;
		brojac++;
	}
	return brojac;
}

bool LList::reverseOrder(int first, int last)
{
	LListNode* cur = head;
	LListNode* prev;
	LListNode* end = head;
	int i = 0, j = 0;
	while (end->info != last)
	{
		i++;
		end = end->next;
	}
	while (cur->info != first)
	{
		j++;
		prev = cur;
		cur = cur->next;
	}
	if (i <= j || end == nullptr || cur == nullptr) // ako je end pre cur
		return false;
	if (cur == head)
	{
		LListNode* tmp;
		while (head != end)
		{
			tmp = head;
			head = head->next;
			tmp->next = end->next;
			end->next = tmp;
		}
		return true;
	}
	while (cur != end)
	{
		prev->next = cur->next;
		cur->next = end->next;
		end->next = cur;

		cur = prev->next;
	}
	return true;
}

void LList::groupElements()
{
	if (head == nullptr)
		return;

	LListNode* cur = head;

	while (cur != nullptr)
	{
		LListNode* tmp = cur;
		int i = 1;
		while (tmp->next != nullptr && tmp != nullptr)
		{
			if (tmp->next->info == cur->info)
			{
				LListNode* isti = tmp->next;
				tmp->next = isti->next;
				isti->next = cur->next;
				cur->next = isti;
				i++;
			}
			else
				tmp = tmp->next;
		}
		for (int j = 0; j < i; j++)
		{
			cur = cur->next;
		}
	}
}
void LList::moveSubToStart(int start, int end)
{
	LListNode* cur = head;
	LListNode* prev = nullptr;

	// pronalazak pocetka podliste
	while (cur->info != start)
	{
		prev = cur;
		cur = cur->next;
	}
	if (cur == nullptr)
		throw "Pocetak podliste nije pronadjen";

	LListNode* sublineStart = cur;

	// pronalazak kraja podliste
	while (cur->info != end)
	{
		cur = cur->next;
	}
	if (cur == nullptr)
		throw "Kraj podliste nije pronadjen";

	// u cur je sublineEnd
	// odvajam podlistu od listu
	if (prev != nullptr)
		prev->next = cur->next;
	else if (cur == tail)
		tail = prev;
	else
		head = cur->next;

	// dodavanje na glavu
	cur->next = head;
	head = sublineStart;

}

void LList::moveSubToTail(int start, int end)
{
	LListNode* sublineStart = head;
	LListNode* prev = nullptr;

	while (sublineStart->info != start)
	{
		prev = sublineStart;
		sublineStart = sublineStart->next;
	}
	if (sublineStart == nullptr)
		throw "Pocetak podliste nije pronadjen";

	LListNode* sublineEnd = findNodePtr(end);
	if (sublineEnd == nullptr)
		throw "Kraj podliste nije pronadjen";

	if (sublineEnd == tail)
		return;
	else if (prev == nullptr)
		head = sublineEnd->next;
	else
		prev->next = sublineEnd->next;

	LListNode* tmp = head;
	while (tmp->next != nullptr)
		tmp = tmp->next;
	tmp->next = sublineStart;
	sublineEnd->next = nullptr;
}

void LList::removeDuplicates()
{
	LListNode* cur = head;

	while (cur != nullptr)
	{
		LListNode* tmp = cur;

		while (tmp->next != nullptr)
		{
			if (tmp->next->info == cur->info)
			{
				LListNode* forDel = tmp->next;
				tmp->next = tmp->next->next;
				delete forDel;
			}
			else
				tmp = tmp->next;
		}
		cur = cur->next;
	}
}

void LList::reverse()
{
	LListNode* prev = nullptr;
	LListNode* cur = head;
	LListNode* next = nullptr;

	while (cur != nullptr)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	head = prev;
}

//void LList::reverseSub(int start, int end)
//{
//	LListNode* prev = nullptr;
//	LListNode* cur = head;
//	LListNode* next = nullptr;
//	
//	while (cur->info != start)
//	{
//		prev = cur;
//		cur = cur->next;
//	}
//	LListNode* startt = cur;
//	LListNode* prevstart = prev;
//
//
//	while (cur->info != end)
//	{
//		next = cur->next;
//		cur->next = prev;
//		prev = cur;
//		cur = next;
//	}
//
//	if (prevstart != nullptr)
//		prevstart->next = prev;
//	else
//		head = prev;
//
//	startt->next = cur;
//}
