#include"HashTable.h"
#include<fstream>
#include<string>
#define MAX 400000
int main(){
	ifstream filein;
	filein.open("words.txt");
	string input;
	cout << "Chon chien luoc giai quyet dung do:" << endl;
	cout << "1. Noi ket" << endl;
	cout << "2. Do tuyen tinh" << endl;
	cout << "3. Do bac hai" << endl;
	cout << "4. Bam kep" << endl;
	int op;
	cin >> op;
	switch (op)
	{
	case 1:
	{
		int num = 0;
		List* HashTable = new List[MAX];
		AllocateList(HashTable, MAX);
		cout << "Hashing please wait..." << endl;
		while (!filein.eof()) {
			if (filein.tellg() == -1) {
				break;
			}
			string temp;
			filein >> temp;
			SeperateChaining(temp, HashTable);
		}
		filein.close();
		while (true) {
			int op1;
			cout << "Nhap tu can tim:";  
			cin.clear();
			cin.ignore();
			getline(cin, input);
			if (SearchSeperateChaining(input, HashTable))
				cout << input << " La Tu Tieng Anh" << endl;
			else
				cout << input << " Ko La Tu Tieng Anh" << endl;
			cout << "Nhap 1 de tiep tuc tim, 0 de thoat:";
			cin.clear();
			cin >> op1;
			if (op1 == 0)
				break;
		}
		delete[]HashTable;
	}
	break;
	case 2:
	{
		string* HashTable = new string[MAX];
		int num=0;
		while (!filein.eof()) {
			if (filein.tellg() == -1) {
				break;
			}
			string temp;
			filein >> temp;
			LinearProbing(temp, HashTable);
		}
		filein.close();
		while (true) {
			cout << "Nhap tu can tim:";
			cin.clear();
			cin.ignore();
			getline(cin, input);
			if (LinearSearch(input, HashTable))
				cout << input << " La Tu Tieng Anh" << endl;
			else
				cout << input << " Ko La Tu Tieng Anh" << endl;
			int op1;
			cout << "Nhap 1 de tiep tuc tim, 0 de thoat:";
			cin.clear();
			cin >> op1;
			if (op1 == 0)
				break;
		}
		delete[]HashTable;
	}
	break;
	case 3:
	{
		string* HashTable = new string[MAX];
		while (!filein.eof()) {
			if (filein.tellg() == -1) {
				break;
			}
			string temp;
			filein >> temp;
			QuadraticProbing(temp, HashTable);
		
		}
		filein.close();
		while (true) {
			cout << "Nhap tu can tim:";
			cin.clear();
			cin.ignore();
			getline(cin, input);
			if (QuadraticSearch(input, HashTable))
				cout << input << " La Tu Tieng Anh" << endl;
			else
				cout << input << " Ko La Tu Tieng Anh" << endl;
			int op1;
			cout << "Nhap 1 de tiep tuc tim, 0 de thoat:";
			cin >> op1;
			if (op1 == 0)
				break;
		}
		delete[]HashTable;
	}
	break;
	case 4:
	{
		string* HashTable = new string[MAX];
		int num = 0;
		while (!filein.eof()) {
			if (filein.tellg() == -1) {
				break;
			}
			string temp;
			filein >> temp;
			DoubleHash(temp, HashTable);
		}
		filein.close();
		while (true) {
			cout << "Nhap tu can tim:";
			cin.clear();
			cin.ignore();
			getline(cin, input);
			if (DoubleHashSearch(input, HashTable))
				cout << input << " La Tu Tieng Anh" << endl;
			else
				cout << input << " Ko La Tu Tieng Anh" << endl;
			int op1;
			cout << "Nhap 1 de tiep tuc tim, 0 de thoat:";
			cin >> op1;
			if (op1 == 0)
				break;
		}
		delete[]HashTable;
	}
	default:
		break;
	}
	return 0;
}