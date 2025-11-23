#pragma once
#ifndef LOAN_H
#define LOAN_H
#include <iostream>
#include "linkedlistmeth.h"
using namespace std;
struct loan {
	int loan_ID;
	string Type;
	int Principal_amount;
	int Interest_rate;
	int Amount_paid;
	int Remaining_balance;
	string Start_date;
	string End_date;
	string Status;
};
#endif // !LOAN_H