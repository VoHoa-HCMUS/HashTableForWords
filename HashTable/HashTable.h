#pragma once
#include<iostream>
#include<list>
using namespace std;
struct Node{
	string data;
	Node* pNext;
};
struct List{
	Node* pHead;
};
void AddHead(List&l,string s);
int EncodeString(string s);
void LinearInsert(string s, string* HashTable);
int HashFunction(string s);
int Hash2Function(string s);
bool LinearSearch(string s, string* HashTable);
void SeperateChaining(string s, List*&HashTable);
void AllocateList(List*&l, int n);
bool SearchSeperateChaining(string s, List* HashTable);
void QuadraticProbing(string s, string* HashTable);
bool QuadraticSearch(string s, string* HashTable);
void DoubleHash(string s, string* HashTable);
bool DoubleHashSearch(string s, string* HashTable);

