#pragma once
#ifndef COSTOMER_H
#define COSTOMER_H
#include <iostream>

using namespace std;
struct customer {
	int Number;
	string Type;
	string IBAN;
	int Branch_code;
	string Name;
	string Date;
	string Statue;
	int Balance;
};
#endif // !COSTOMER_H
