#include "HashTable.h"
#define prime 399989
#define prime2 372637
int EncodeString(string s){
	int code = 0;
	for (int i = 0; i < s.length(); i++) {
		code += toascii(s[i]) * (i + 1);
	}
	return code;
}
void LinearProbing(string s, string* HashTable) {
    int k = HashFunction(s);
	int i = 0;
	while (HashTable[k] != "") {
		k = (k + i) % prime;
		i++;
	}
	HashTable[k] = s;
	cout << "Hashed " << HashTable[k] << " in " << k << endl;
}
int HashFunction(string s){
	return EncodeString(s) % prime;
}
bool LinearSearch(string s, string* HashTable) {
	int k = HashFunction(s);
	int i = 0;
	while (HashTable[k] != s && HashTable[k] != "") {
		k = (k + i) % prime;
		i++;
	}
	if (HashTable[k] == s)
		return true;
	return false;
}
void SeperateChaining(string s, List*& HashTable){
	int k = HashFunction(s);
	AddHead(HashTable[k], s);

}
bool SearchSeperateChaining(string s, List* HashTable){
	int k = HashFunction(s);
	if (HashTable[k].pHead == NULL)
		return false;
	for (Node* p = HashTable[k].pHead; p; p = p->pNext)
	{
		if (p->data == s)
			return true;
	}
	return false;
}
void AddHead(List& l, string s) {
	Node* p = new Node;
	p->data = s;
	p->pNext = NULL;
	if (l.pHead == NULL)
		l.pHead = p;
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void AllocateList(List*& l, int n){
	for (int i = 0; i < n; i++)
		l[i].pHead = NULL;
}
void QuadraticProbing(string s, string* HashTable) {
	int k = HashFunction(s);
	int i=0;
	while (HashTable[k] != ""){
		k = (k + i*i) % prime;
		i++;
	}
	HashTable[k] = s;
	cout << "Hashed " << HashTable[k] << " in " << k << endl;
}
bool QuadraticSearch(string s, string* HashTable) {
	int k = HashFunction(s);
	int i = 0;
	while (HashTable[k] != s && HashTable[k] != "") {
		k = (k + i*i) % prime;
		i++;
	}
	if (HashTable[k] == s)
		return true;
	return false;
}
int Hash2Function(string s) {
	return prime2+EncodeString(s)%prime2;
}
void DoubleHash(string s, string* HashTable) {
	int k1 = HashFunction(s), k2 = Hash2Function(s);
	int i = 0;
	int k = (k1 + i * k2) % prime;
	while (HashTable[k] != "") {
	    k = (k1 + i * k2) % prime;
		i++;
	}
	HashTable[k] = s;
	cout << "Hashed " << HashTable[k] << " in " << k << endl;

}
bool DoubleHashSearch(string s, string* HashTable) {
	int k1 = HashFunction(s), k2 = Hash2Function(s);
	int i = 0;
	int k = (k1 + i * k2) % prime;
	while (HashTable[k] != "") {
		k = (k1 + i * k2) % prime;
		i++;
	}
	if (HashTable[k] == s)
		return true;
	return false;
}