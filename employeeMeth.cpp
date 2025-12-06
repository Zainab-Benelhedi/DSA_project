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



void DisplayemployeesSortedByLastName(Employee employees[], int count) {
    Employee temp[100]; // Copy of original array

    // Copy employees array
    for (int i = 0; i < count; i++) {
        temp[i] = employees[i];
    }

    // Sort alphabetically by last name
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (temp[i].lastName > temp[j].lastName) {
                Employee exchange = temp[i];
                temp[i] = temp[j];
                temp[j] = exchange;
            }
        }
    }

    // Display sorted employees
    for (int i = 0; i < count; i++) {
        cout << "ID : " << temp[i].id << endl;
        cout << "Name : " << temp[i].name << endl;
        cout << "Last Name : " << temp[i].lastName << endl;
        cout << "Salary : " << temp[i].salary << endl;
        cout << "---------------------------" << endl;
    }
}



void DisplayEmployeesByBranch(Employee employees[], int count) {
    for (int branch = 1; branch <= 3; branch++) {
        cout << "========== Branch " << branch << " ==========" << endl;

        bool found = false;
        for (int i = 0; i < count; i++) {
            if (employees[i].branchCode == branch) {
                found = true;
                cout << "ID: " << employees[i].id << endl;
                cout << "Name: " << employees[i].name << endl;
                cout << "Last Name: " << employees[i].lastName << endl;
                cout << "Salary: " << employees[i].salary << endl;
                cout << "-------------------------------" << endl;
            }
        }

        if (!found) {
            cout << "No employees in this branch.\n";
        }
    }
}



void displayCustomerLoan(const Account& acc) {
    cout << "Account number : " << acc.Number << " | Name : " << acc.Name << endl;

    if (acc.loan == nullptr) {
        cout << "No loan list found for this account" << endl;
        return;
    }

    node_loan* node = acc.loan->head;

    if (node == nullptr) {
        cout << "This account has no loans." << endl;
        return;
    }

    cout << "-------------------- Loans for this customer --------------------" << endl;
    while (node != nullptr) {
        const loan& L = node->l;

        cout << "Loan ID : " << L.loan_ID << endl;
        cout << "Loan Type : " << L.Type << endl;
        cout << "Principal: " << L.Principal_amount << " TND" << endl;
        cout << "Interest rate: " << L.Interest_rate << "%" << endl;
        cout << "Amount paid: " << L.Amount_paid << " TND" << endl;
        cout << "Remaining balance: " << L.Remaining_balance << " TND" << endl;
        cout << "Start date: " << L.Start_date << endl;
        cout << "End date: " << L.End_date << endl;
        cout << "Status: " << L.Status << endl;
        cout << "-------------------------------------------------------------" << endl;

        node = node->next;
    }
    cout << "End of loan list." << endl;
}


void ChangeLoanStatus(Account& acc) {
    cout << "Account number: " << acc.Number << " | Name: " << acc.Name << endl;

    if (acc.loan == nullptr) {
        cout << "No loan list found for this account." << endl;
        return;
    }

    node_loan* node = acc.loan->head;

    if (node == nullptr) {
        cout << "This account has no loans." << endl;
        return;
    }

    int Loan_ID;
    cout << "Enter the Loan ID you want to modify: ";
    cin >> Loan_ID;

    string NewStatus;
    do {
        cout << "Enter new status (active / completed / overdue): ";
        cin >> NewStatus;

        for (char& c : NewStatus) c = tolower(c);

        if (NewStatus != "active" && NewStatus != "completed" && NewStatus != "overdue") {
            cout << "Invalid status, please try again!" << endl;
        }
    } while (NewStatus != "active" && NewStatus != "completed" && NewStatus != "overdue");

    while (node != nullptr) {
        if (node->l.loan_ID == Loan_ID) {
            cout << "Current status: " << node->l.Status << endl;
            node->l.Status = NewStatus;
            cout << "Status updated successfully!" << endl;
            return;
        }
        node = node->next;
    }

    cout << "Loan with ID " << Loan_ID << " not found." << endl;
}



void extractCompletedLoans(doublylist* source, singlylist* completed_loans) {
    if (source == nullptr || isEmptyd(*source)) return;
    if (completed_loans == nullptr) return;

    int i = 1;

    while (i <= source->size) {
        loan currentLoan = getElementdoublylist(*source, i);
        string status = currentLoan.Status;

        
        for (char& c : status) c = tolower(c);

        if (status == "completed") {
            insertsinglylist(completed_loans, currentLoan, completed_loans->size + 1);
            removeAtdoublylist(source, i);
        }
        else {
            i++;
        }
    }
}


