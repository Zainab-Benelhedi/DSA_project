#ifndef ACCOUNTMETH_H
#define ACCOUNTMETH_H
#include "account.h"

bool addAccount(const Account& acc);
void displayAccounts();
bool changeAccountStatus(int accNum, const string& newStatus);
void archiveClosedAccounts();


Account* findAccount(int accNum);

#endif