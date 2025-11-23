#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;

struct Employee {
    int id;
    string name, lastName, hireDate, address;
    double salary;
    int branchCode; //Store the code of the branch or 1 for head office
};

#endif