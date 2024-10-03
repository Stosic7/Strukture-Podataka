#pragma once
class HashObject
{
private:
	char* key;
public:
	HashObject();
	HashObject(const char* k);
	HashObject(HashObject const& obj);
	~HashObject();
	HashObject& operator = (HashObject const& obj);
	bool operator == (HashObject const& obj);
	void deleteRecord();
	char* getKey() { return key; }
	bool isEqualKey(const char* k) { return strcmp(key, k) == 0; }
	void print();
};
