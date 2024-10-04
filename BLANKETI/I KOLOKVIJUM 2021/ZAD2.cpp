void DList::exchange(int a, int b)
{
	// radi za apsolutnos ve slucajeve

	if (isEmpty())
		return;

	if (head->next == nullptr)
		return;

	if (a == b)
		return;

	DListNode* temp1 = head;
	DListNode* temp2 = head;

	while (temp1 != nullptr && temp2 != nullptr && (temp1->info != a || temp2->info != b)) {
		if (temp1->info != a)
			temp1 = temp1->next;
		if (temp2->info != b)
			temp2 = temp2->next;
	}

	DListNode* temp1next = nullptr;
	DListNode* temp1prev = nullptr;
	DListNode* temp2next = nullptr;
	DListNode* temp2prev = nullptr;

	if (temp1->prev != nullptr) {
		temp1->prev->next = temp2;
		temp1prev = temp1->prev;
	}
	else
		head = temp2;

	if (temp2->prev != nullptr) {
		temp2->prev->next = temp1;
		temp2prev = temp2->prev;
	}
	else
		head = temp1;

	if (temp1->next != nullptr) {
		temp1->next->prev = temp2;
		temp1next = temp1->next;
	}

	if (temp2->next != nullptr) {
		temp2->next->prev = temp1;
		temp2next = temp2->next;
	}

	temp1->next = temp2next;
	temp1->prev = temp2prev;
	temp2->next = temp1next;
	temp2->prev = temp1prev;
}
