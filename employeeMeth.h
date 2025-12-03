#ifndef EMPLOYEEMETH_H
#define EMPLOYEEMETH_H
#include "employee.h"

void printEmployee(const Employee& e);
void addEmployee(Employee employees[], int& count, int MAX);
bool deleteEmployee(Employee employees[], int& count, int id);
bool modifyEmployee(Employee employees[], int count, int id);
void displayEarliestRecruitedEmployee(Employee employees[], int count);
void DisplayemployeesSortedByLastName(Employee employees[], int count);
void DisplayEmployeesByBranch(Employee employees[], int count);

bool isIdUnique(Employee employees[], int count, int id);
bool isValidName(const string& name);
bool isValidHireDate(const string& hiredate);
int findEmployeeIndex(Employee employees[], int count, int id);

void DisplayemployeesSortedByLastName(Employee employees[], int count);
void DisplayEmployeesByBranch(Employee employees[], int count);
void displayCustomerLoan(const Account& acc);
void ChangeLoanStatus(Account& acc);
void extractCompletedLoans(doublylist* source, singlylist* completed_loans) ;

#endif 



