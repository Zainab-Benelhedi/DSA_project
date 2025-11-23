#ifndef EMPLOYEEMETH_H
#define EMPLOYEEMETH_H

#include "employee.h"
void printEmployee(const Employee& e);
void addEmployee(Employee employees[], int& count, int MAX);
bool deleteEmployee(Employee employees[], int& count, int id);

bool isIdUnique(Employee employees[], int count, int id);
bool isValidName(const string& name);
bool isValidHireDate(const string& hiredate);
int findEmployeeIndex(Employee employees[], int count, int id);
#endif 
