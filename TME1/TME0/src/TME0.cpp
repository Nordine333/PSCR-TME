//============================================================================
// Name        : TME0.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	int tab[10];

	for(int i=0; i<10; i=i+1)
	{
		tab[i]= i;
	}
	for(int i=0; i<10; i=i+1)
	{
		cout<<tab[i]<<endl;
	}
	for (int i=9; i >= 0 ; i--)
	{
		if (tab[i] - tab[i-1] != 1) {
		cout << "probleme !";
		}
	}
	return 0;
}
