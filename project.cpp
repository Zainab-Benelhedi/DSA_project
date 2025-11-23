

#include <iostream>
using namespace std;
#include "customer.h"
#include "employee.h"
customer array_customer[5] = {
        { 1001, "Current", "TN59 1000 0000 0001 2345 6789", 1, "Ahmed Ben Salah", "01/01/2024", "Active", 2500 },
        { 1002, "Savings", "TN59 1000 0000 0002 9876 5432", 2, "Leila Trabelsi", "15/03/2024", "Active", 12000 },
        { 1003, "Business", "TN59 1000 0000 0003 4567 8910", 3, "karim kallel", "20/05/2024", "Active", 50000 },
        { 1004, "Student", "TN59 1000 0000 0004 1111 2222", 1, "Mariem Jlassi", "10/09/2024", "Inactive", 300 },
        { 1005, "Current", "TN59 1000 0000 0005 3333 4444", 2, "Hichem Kacem", "05/11/2024", "Closed", 10 }
};
employee array_employee [3]= {
        {1, "Ahmed", "Ben Salah", "12 Habib Bourguiba Avenue, Tunis", 2500.0, "01/01/2023", 1},
        {2, "Leila", "Trabelsi", "Marseille Street, Sfax", 3200.0, "15/03/2022", 2},
        {3, "Hichem", "Kacem", "Farhat Hached Avenue, Bizerte", 2800.0, "20/05/2024", 3}
};
// the customer interface 
int login(customer array_customer[], int acc_number, int size) {
    int test = -1;
    int i = 0;
    while (test==-1 && i < size) {
        if (array_customer [i].Number == acc_number)
            test = i;
        i++;
    };
    return test;
};
void customer_interface(customer array_customer [], int size, int c) {
    cout << "welcome to customer intefrace !" << endl;
    cout << "______________________________________________" << endl;
    cout << "______________________________________________" << endl;
    cout << "______________what do you want________________" << endl;
    cout << "______________________________________________" << endl;
    cout << "______________________________________________" << endl;
    cout << "         1- view the list of loans            " << endl;
    cout << "         2- submit a new loan                 " << endl;
    cout << "         3- Withdrow money                    " << endl;
    cout << "         4- Deposit money                     " << endl;
    cout << "______________________________________________" << endl;
    cout << "______________________________________________" << endl;
    int operation;
    cin >> operation;
    if (operation == 1) {
       //displayList(&L);//list of loans of the customer ;
    }
    else if (operation == 2) {
        cout << "________________________________________" << endl;
        cout << "________________________________________" << endl;
        cout << " enter the amount of money to withdraw :" << endl;
        cout << "________________________________________" << endl;
        cout << "________________________________________" << endl;
        cout << "            choice 1: 10                " << endl;
        cout << "            choice 2: 20                " << endl;
        cout << "            choice 3: 50                " << endl;
        cout << "________________________________________" << endl;
        cout << "________________________________________" << endl;
		int choice;
        cin >> choice;
        if (choice == 1) {
            //withdraw 10
			array_customer [c].Balance -= 10;
        }
        else if (choice == 2) {
            //withdraw 20
            array_customer [c].Balance -= 20;
        }
        else if (choice == 3) {
            //withdraw 50
            array_customer [c].Balance -= 50;
        }
    }
    else if (operation == 3) {
		cout << "_______________________________________" << endl;
        cout << "_______________________________________" << endl;
        cout << " enter the amount of money to deposit :" << endl;
        cout << "_______________________________________" << endl;
        cout << "_______________________________________" << endl;
        int amount;
        cin >> amount;
		//deposit amount
		array_customer [c].Balance += amount;
    }


}
int main()
{
    cout << "|____________________________________________________________| " << endl;
    cout << "|____________________________________________________________| " << endl;
    cout << "|__________welcome to the Banking Management System__________| " << endl;
    cout << "|____________________________________________________________| " << endl;
    cout << "|____________________________________________________________|" << endl;
    cout << "|                  1-Cutomer intefrace                       | " << endl;
    cout << "|                  1-Emplpyee intefrace                      |" << endl;
    cout << "|____________________________________________________________|" << endl;
    cout << "|____________________________________________________________| " << endl;
    cout << "|                  3-Exist                                   |" << endl;
    cout << "|____________________________________________________________|" << endl;
    cout << "|____________________________________________________________|" << endl;
    cout << "               where do you want to enter ?                   " << endl;
    int r;
    cin >> r;
    int size = sizeof(array_customer) / sizeof(array_customer[0]);
    if (r == 1) {
        cout << "enter your account number :";
        int acc_number;
        cin >> acc_number;
        int c = login(array_customer, acc_number, size);
        if (c>=0) {
            cout << "login successful!" << endl;
            customer_interface(array_customer, size, c);
        }
    }








}


