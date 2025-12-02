#include <iostream>
using namespace std;
#include "customer.h"
int number_loan (Account Accounts [],int accountCount){
	int sum =0;
	for (int i =0; i< accountCount; i++){
		sum += Accounts[i].loan->size;
	}
	return sum;
}