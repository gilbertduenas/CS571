#ifndef cs571HW81_CPP
#define cs571HW81_CPP
#include<iostream>
#include"llist.h"

using namespace std;

int main()
{
	string userInput;
  llist cs571hw81;
  //Not all methods are called by the transaction file.
  cs571hw81.ReadTransactionFile("nlpProb.txt");
	cs571hw81.displayAll();
	
	cout << "\nPlease enter a string using only the following characters: \n a, b, c > "; 
	cin >> userInput;
  return 0;
} 
#endif //cs571HW81_CPP

