
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
using namespace std;
#include "doublylinkedlist.h"
#include "stack.h"
struct Account {
	int Number;
	string Type;
	string IBAN;
	int Branch_code;
	string Name;
	string Date;
	string Statue;
	int Balance;
	doublylist* loan;
	stack* transaction;
};
#endif // !COSTOMER_H
