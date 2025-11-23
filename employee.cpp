#include "employee.h"
#include "employeeMeth.h"
#include <iostream>
using namespace std;

void printEmployee(const Employee& e) {
	cout << "Employee ID: " << e.id << endl;
	cout << "Name: " << e.name << " " << e.lastName << endl;
	cout << "Address: " << e.address << endl;
	cout << "Salary: " << e.salary << endl;
	cout << "Hire Date: " << e.hireDate << endl;
	cout << "Branch Code: " << e.branchCode << endl;
}

void addEmployee(Employee employees[], int& count, int MAX) {
	// Check if we can add more employees
    if (count >= MAX) {
        cout << "Error: employee array is full." << endl;
        return;
    }

	Employee e; // Declare a new Employee object

    do {
        cout << "Enter ID: ";
        cin >> e.id;

        if (cin.fail() || e.id <= 0) {   // Check if input failed (typed letters instead of a number) or ID is not positive
            cout << "Invalid ID. Enter a positive number.\n";
            cin.clear();            
            cin.ignore(10000000, '\n'); // Discard invalid input
            continue;                // Restart the loop and retry input 
        }

        if (!isIdUnique(employees, count, e.id)) {
            cout << "ID already exists. Enter a unique ID.\n";
            continue; 
        }

        break; // stops the loop when the ID is valid and unique
	} while (true); // Infinite loop until valid input is received

    do {
        cout << "Enter first name: ";
		getline(cin, e.name); // allows names with spaces

        if (!isValidName(e.name)) {
            cout << "Invalid first name. Only letters, spaces, and hyphens are allowed.\n";
            continue;
        }

        break;
    } while (true);

    do {
        cout << "Enter last name: ";
        getline(cin, e.lastName);

        if (!isValidName(e.lastName)) {
            cout << "Invalid last name. Only letters, spaces, and hyphens are allowed.\n";
            continue;
        }

        break;
    } while (true);

    do {
        cout << "Enter address: ";
        cin.ignore();
        getline(cin, e.address);
	} while (e.address.empty());

    do {
        cout << "Enter salary: ";
        cin >> e.salary;
        if (cin.fail() || e.salary < 0) {
            cout << "Invalid salary. Enter a non-negative number.\n";
            cin.clear();
            cin.ignore(10000000, '\n');
            continue;
        }
        break;
	} while (true);

    /*
    or 
    do {
        cout << "Enter salary: ";
        cin >> e.salary;
	} while (e.salary < 0);
    */

    do {
        cout << "Enter hire date (YYYY-MM-DD): ";
        cin >> e.hireDate;
	} while (e.hireDate.empty() || !isValidHireDate(e.hireDate));

    do {
        cout << "Enter branch code: ";
        cin >> e.branchCode;
	} while (e.branchCode <= 0);

    employees[count++] = e;

    cout << "Employee added successfully." << endl;
}

int findEmployeeIndex(Employee employees[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (employees[i].id == id)
            return i;
    }
    return -1;
}

bool deleteEmployee(Employee employees[], int& count, int id) {
    int pos = findEmployeeIndex(employees, count, id);

    if (pos == -1) {
        cout << "Employee not found.\n";
        return false;
    }

    for (int i = pos; i < count - 1; i++)
        employees[i] = employees[i + 1];

    count--;
    cout << "Employee deleted.\n";
    return true;
}

bool modifyEmployee(Employee employees[], int count, int id) { // modify an employee by ID
    int pos = findEmployeeIndex(employees, count, id);

    if (pos == -1) {
        cout << "Employee not found.\n";
        return false;
    }

    Employee& e = employees[pos];  // Using a reference 'e' to modify the original employee directly

    do {
        cout << "Modify first name (" << e.name << "): ";
        cin.ignore();
        getline(cin, e.name);
        if (!isValidName(e.name)) {
            cout << "Invalid first name. Only letters, spaces, and hyphens are allowed.\n";
            continue;
        }
        break;
	} while (true);

    do {
        cout << "Modify last name (" << e.lastName << "): ";
        getline(cin, e.lastName);
        if (!isValidName(e.lastName)) {
            cout << "Invalid last name. Only letters, spaces, and hyphens are allowed.\n";
            continue;
        }
        break;
	} while (true);

    do {
        cout << "Modify address (" << e.address << "): ";
        getline(cin, e.address);
    } while (e.address.empty());

    do {
        cout << "Modify salary (" << e.salary << "): ";
        cin >> e.salary;
        if (cin.fail() || e.salary < 0) {
            cout << "Invalid salary. Enter a non-negative number.\n";
            cin.clear();
            cin.ignore(10000000, '\n');
            continue;
        }
		break;
	} while (true);

    do {
        cout << "Modify hire date (" << e.hireDate << "): ";
        cin >> e.hireDate;
	} while (e.hireDate.empty() || !isValidHireDate(e.hireDate));

    do {
        cout << "Modify branch code (" << e.branchCode << "): ";
        cin >> e.branchCode;
    } while (e.branchCode <= 0);

    cout << "Employee modified.\n";
    return true;
}

void displayEarliestRecruitedEmployee(Employee employees[], int count) {
    if (count == 0) {
        cerr << "No employees available.\n";
        return;
	}
	// TO BE COMPLETED
}


bool isIdUnique(Employee employees[], int count, int id) {
    for (int i = 0; i < count; ++i) {
        if (employees[i].id == id) {
            return false;
        }
    }
    return true;
}

bool isValidName(const string& name) {
    if (name.empty()) return false;

    for (char c : name) {
        if (!isalpha(c) && c != ' ' && c != '-')  // Allow letters, spaces, and hyphens
            return false;
    }
    return true;
}

bool isValidHireDate(const string& hiredate) {
    if (hiredate.length() != 10 || hiredate[4] != '-' || hiredate[7] != '-') return false;
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) continue; // Skip dashes
        if (!isdigit(hiredate[i])) return false;
    }

    return true;
}




