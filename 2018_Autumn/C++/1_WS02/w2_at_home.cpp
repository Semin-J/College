/***********************************************************
// Workshop 2: Dynamic Memory
// File w2_at_home.cpp
// Version 2.0
// Date 2018/09/17
// Author Semin Jeon
// Description
// ?????????????????????
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name         Date        Reason
// Semin Jeon   2018/09/17
///////////////////////////////////////////////////////////
***********************************************************/

#include <iostream>
#include "Kingdom.h"
#include <cstring>

using namespace std;
using namespace sict;

void read(Kingdom&);

int main() {
	int count = 0;

	// TODO: declare the pKingdom pointer here (don't forget to initialize it)
  Kingdom* pKingdom;
  pKingdom = nullptr;

	cout << "==========\n"
		<< "Input data\n"
		<< "==========\n"
		<< "Enter the number of Kingdoms: ";
	cin >> count;
	cin.ignore();

	if (count < 1) return 1;

	// TODO: allocate dynamic memory here for the pKingdom pointer
  pKingdom = new Kingdom[count];

	for (int i = 0; i < count; ++i) {
		cout << "Kingdom #" << i + 1 << ": " << endl;
		// TODO: add code to accept user input for Kingdom i
    read(pKingdom[i]);
	}
	cout << "==========" << endl << endl;

	cout << "------------------------------" << endl
		<< "The 1st Kingdom entered is" << endl
		<< "------------------------------" << endl;
	display(pKingdom[0]);
	cout << "------------------------------" << endl << endl;

	// expand the array of Kingdoms by 1 element

	// TODO: allocate dynamic memory for count + 1 Kingdoms
  Kingdom* nKingdom = new Kingdom[count + 1];

	// TODO: copy elements from original array into this newly allocated array
  for(int i = 0; i < count; i++){
    nKingdom[i] = pKingdom[i];
  }

	// TODO: deallocate the dynamic memory for the original array
  delete[]pKingdom;
  
	// TODO: copy the address of the newly allocated array into pKingdom pointer
  pKingdom = nKingdom;
  
  //when delete first, the linked array disappeared even there is one more pointer
  //so if I want to remove the pointer, make it nullptr first, and then delete that
  nKingdom = nullptr;
  delete[]nKingdom;
 
  
	cout << "==========\n"
		<< "Input data\n"
		<< "==========\n"
		<< "Kingdom #" << count + 1 << ": " << endl;
	// TODO: accept input for the new element in the array
  read(pKingdom[count]);
	count++;
	cout << "==========\n" << endl;

	// testing that the overload of "display(...)" works
	display(pKingdom, count);
	cout << endl;

	// TODO: deallocate the dynamic memory here
  
  delete[]pKingdom;
  pKingdom = nullptr;

	return 0;
}

// read accepts data for a Kingdom from standard input
//
void read(Kingdom& kingdom) {
	cout << "Enter the name of the Kingdom: ";
	cin.get(kingdom.m_name, 32, '\n');
	cin.ignore(2000, '\n');
	cout << "Enter the number of people living in " << kingdom.m_name << ": ";
	cin >> kingdom.m_population;
	cin.ignore(2000, '\n');
}
