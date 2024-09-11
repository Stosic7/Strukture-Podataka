#pragma once
#include "LListNode.h"
class LList
{
protected:
	LListNode *head, *tail;
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
	
	// I kol 2024
	void concatenateParts(LList* list2, int k);
	// jun2 2023
	bool moveSectionToHead(int start, int end);
	// I kol 2023 // treba jos nesto
	int SwapPairs(int data1, int data2);
	// decembar 2023
	bool reverseOrder(int first, int last);
	// jun 2024
	void groupElements();
	// nesto za lab
	void moveSubToStart(int start, int end);
	void moveSubToTail(int start, int end);
	void removeDuplicates();
	void reverse();
	//	void reverseSub(int start, int end); ne radi kako treba
};

