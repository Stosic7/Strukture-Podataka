#include <cstring>
#include "OpenScatterTable.h"

inline unsigned int hKeyLetters(const char* s, unsigned int mod)
{
    unsigned long long h = 0ULL;
    while (*s) {
        char c = *s++;
        if (c >= 'a' && c <= 'z') c -= 32;
        int v = (c - 'A' + 1);      // A=1..Z=26
        h = h * 31ULL + (unsigned long long)v;
    }
    return (unsigned int)(h % mod);
}

unsigned int OpenScatterTable::h(ScatterObject o)
{
    return hKeyLetters(o.key, (unsigned int)m);
}

bool OpenScatterTable::isIn(char* key)
{
    if (!key || !key[0]) return false;

    int bucket = (int)hKeyLetters(key, (unsigned int)m);
    if (a[bucket].key == nullptr) return false;

    for (int i = bucket; i != -1; i = a[i].next)
        if (a[i].key && std::strcmp(a[i].key, key) == 0)
            return true;

    return false;
}

void OpenScatterTable::deleteKey(char* key)  
{
    if (!key || !key[0]) return;

    int bucket = (int)hKeyLetters(key, (unsigned int)m);
    if (a[bucket].key == nullptr) return;

    if (std::strcmp(a[bucket].key, key) == 0)
    {
        int nxt = a[bucket].next;
        if (nxt == -1) {
            a[bucket].key = nullptr;
            a[bucket].next = -1;
            return;
        }
        a[bucket].key  = a[nxt].key;
        a[bucket].next = a[nxt].next;

        a[nxt].key = nullptr;
        a[nxt].next = -1;
        return;
    }

    int prev = bucket;
    int cur  = a[bucket].next;
    while (cur != -1 && !(a[cur].key && std::strcmp(a[cur].key, key) == 0)) {
        prev = cur;
        cur  = a[cur].next;
    }
    if (cur == -1) return;

    a[prev].next = a[cur].next;

    a[cur].key = nullptr;
    a[cur].next = -1;
}
