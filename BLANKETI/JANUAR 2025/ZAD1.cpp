void partitionList(Node** head, int pivot)
{
    if (!head || !(*head)) return;

    Node *lessH = nullptr, *lessT = nullptr;   // < pivot
    Node *geH   = nullptr, *geT   = nullptr;   // >= pivot

    Node* cur = *head;
    while (cur)
    {
        Node* nxt = cur->next;  // sacuvaj sledeci
        cur->next = nullptr;    // odseci trenutni cvor

        if (cur->info < pivot)
        {
            if (!lessH) { lessH = lessT = cur; }
            else        { lessT->next = cur; lessT = cur; }
        }
        else
        {
            if (!geH)   { geH = geT = cur; }
            else        { geT->next = cur; geT = cur; }
        }
        cur = nxt;
    }

    // spoji dve liste i podesi novu glavu
    if (lessH)
    {
        lessT->next = geH;
        *head = lessH;
    }
    else
    {
        *head = geH; // nema elemenata < pivot
    }
}
