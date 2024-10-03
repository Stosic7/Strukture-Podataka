#pragma once
#include "LListNode.h"
class LList
{
protected:
	LListNode* head, * tail;
public:
	LList();
	~LList();
	bool isEmpty();
	void addToHead(int el);
	void addToTail(int el);
	int deleteFromHead();
	int deleteFromTail();
	LListNode* findNodePtr(int el);
	LListNode* getHead();
	LListNode* getNext(LListNode* ptr);
	int getHeadEl();
	int getNextEl(int el);
	void printAll();
	bool isInList(int el);
	void deleteEl(int el);
	LListNode* removeNodeFromHead();

  // ovde sada dodajete funkcije koje se treba uraditi u zadatku. Npr:
  // I KOL 2024
  // void concatenateParts(LList* list2, int k); 
  // i nju implementirate u LList.cpp, u mainu je startujete preko list->

};
