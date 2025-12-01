#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "linkedlist.h"
#include <string>
using namespace std;

struct Account {
    int accountNumber;
    string accountType;
    string IBAN;
    int branchCode;
    string holderName;
    string openingDate;
    string status;           // active, inactive, closed
    double balance;
    doublylist* loan;
    stack* transaction;
};

const int MAX_ACCOUNTS = 1000;

extern Account accounts[MAX_ACCOUNTS];
extern int accountCount;

extern Account archivedAccounts[MAX_ACCOUNTS];
extern int archivedCount;

#endif
