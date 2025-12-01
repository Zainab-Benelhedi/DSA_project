#include "account.h"
#include <iostream>
using namespace std;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

bool addAccount(const Account& acc) {
    if (accountCount >= MAX_ACCOUNTS) {
        cout << "Error: Maximum number of accounts reached.\n";
        return false;
    }

    if (findAccount(acc.accountNumber) != nullptr) {
        cout << "Error: Account number already exists.\n";
        return false;
    }

    accounts[accountCount++] = acc;
    return true;
}

void displayAccounts() {
    if (accountCount == 0) {
        cout << "No accounts to display.\n";
        return;
    }

    for (int i = 0; i < accountCount; i++) {
        cout << "-----------------------------\n";
        cout << "Account Number: " << accounts[i].accountNumber << "\n";
        cout << "Holder Name:    " << accounts[i].holderName << "\n";
        cout << "IBAN:           " << accounts[i].IBAN << "\n";
        cout << "Account Type:   " << accounts[i].accountType << "\n";
        cout << "Branch Code:    " << accounts[i].branchCode << "\n";
        cout << "Opening Date:   " << accounts[i].openingDate << "\n";
        cout << "Status:         " << accounts[i].status << "\n";
        cout << "Balance:        " << accounts[i].balance << " TND\n";
    }
}

bool changeAccountStatus(int accNum, const string& newStatus) {
    Account* acc = findAccount(accNum);

    if (!acc) {
        cout << "Error: Account not found.\n";
        return false;
    }

    acc->status = newStatus;
    return true;
}

void archiveClosedAccounts() {
    int i = 0;

    while (i < accountCount) {
        if (accounts[i].status == "closed") {
            cout << "Archiving account " << accounts[i].accountNumber << endl;

            archivedAccounts[archivedCount++] = accounts[i];

            // Remove from active list (shift left)
            for (int j = i; j < accountCount - 1; j++) {
                accounts[j] = accounts[j + 1];
            }

            accountCount--;
        }
        else {
            i++;
        }
    }
}

Account* findAccount(int accNum) {
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accNum) {
            return &accounts[i];
        }
    }
    return nullptr;
}
