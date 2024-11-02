#include"LinkList.h"
#include<iostream>
#include<string>
using namespace std;
Status PrintElement(ELemType elem) {
	cout << elem << " ";
	return OK;
}
void print() {

}
int main() {
	string s;
	LinkList L;
	InitList(L);
	int cur = 1;

	while (cin >> s)
	{
		ClearList(L);
		int length = s.length();
		for (int i = 0; i < length; i++)
		{
			if (s[i] == '[')cur = 1;
			else if (s[i] == ']')cur = L.len + 1;
			else
			{
				ListInsert_L(L, cur, s[i]);
				cur++;
			}
		}

		ListTraverse(L, PrintElement);
	}
}