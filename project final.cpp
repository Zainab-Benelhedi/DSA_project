
#include <iostream>
using namespace std;
#include "doublylinkedlistmethode.h"
#include "singlylinkedlistmethode.h"
#include "stackmethode.h"
#include "employee.h"
#include "customer.h"
#include "datacustomer.cpp"
#include "employeedata.cpp"
int count = 5;
doublylist* loan_request = createdoublylist();
// the customer interface 
int login(Account Accounts[], int acc_number, int size) {
    int test = -1;
    int i = 0;
    while (test == -1 && i < size) {
        if (Accounts[i].Number == acc_number)
            test = i;
        i++;
    };
    return test;
};
int loginemployee(Employee employees[], int emp_id , int size) {
    int test = -1;
    int i = 0;
    while (test == -1 && i < size) {
        if (Accounts[i].Number == emp_id )
            test = i;
        i++;
    };
    return test;
};

void customer_interface(Account Accounts[], int maxaccount, int c, doublylist * loan_request ) {
    cout << "        welcome to customer intefrace !"        << endl;
    cout << "______________________________________________" << endl;
    cout << "______________________________________________" << endl;
    cout << "______________what do you want________________" << endl;
    cout << "______________________________________________" << endl;
    cout << "______________________________________________" << endl;
    cout << "         1- view the list of loans            " << endl;
    cout << "         2- submit a new loan                 " << endl;
    cout << "         3- Withdrow money                    " << endl;
    cout << "         4- Deposit money                     " << endl;
    cout << "         5- view transaction history          " << endl;
    cout << "         6- undo last transaction             " << endl;
    cout << "______________________________________________" << endl;
    cout << "______________________________________________" << endl;
    int operation;
    cin >> operation;
    if (operation == 1) {
        doublylist* l = Accounts[c].loan;
        //displayList(&L);//list of id  loans of the customer ;
        displayList(*l);
    }
    else if (operation == 3) {
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
            Accounts[c].Balance -= 10;
        }
        else if (choice == 2) {
            //withdraw 20
            Accounts[c].Balance -= 20;
        }
        else if (choice == 3) {
            //withdraw 50
            Accounts[c].Balance -= 50;
        }
    }
    else if (operation == 4) {
        cout << "_______________________________________" << endl;
        cout << "_______________________________________" << endl;
        cout << " enter the amount of money to deposit :" << endl;
        cout << "_______________________________________" << endl;
        cout << "_______________________________________" << endl;
        int amount;
        cin >> amount;
        //deposit amount
        Accounts[c].Balance += amount;
    }
    else if (operation == 2) {
        cout << "loan submission :" << endl;
        loan loan_req = {};
        cin .ignore();
        cout << "enter the type of loan :" << endl;
		getline (cin, loan_req.Type);
        cout << "enter the principal amount :" << endl;
        cin >> loan_req.Principal_amount;
        cout << "enter the amount paid : " << endl;
        cin >> loan_req.Amount_paid;
		insertdoublylist(loan_request, loan_req, loan_request->size +11);
    }
    else if (operation == 5) {
        cout << "transaction history :" << endl;
        stack* s = Accounts[c].transaction;
        displayStack(s);
    }
    else if (operation == 6) {
        cout << "undo last transaction :" << endl;
        stack* s = Accounts[c].transaction;
		transaction t = {};
        t=pop(s);
        if (t.Type == "Deposit") {
            Accounts[c].Balance -= t.Amount;
        }
        else if (t.Type == "Withdrawal") {
            Accounts[c].Balance += t.Amount;
        }
    }
    else {
        cout << "verify your choice";
    }
};
void employee_interface(Employee employees[], int count, int e, Account Accounts[], int maxaccount, doublylist* loan_request) {
    cout << "        welcome to employee intefrace !       " << endl;
	cout << "_____________________________________________________________" << endl;
    cout << "_____________________________________________________________" << endl;
    cout << "_____________________________________________________________" << endl;
	cout << "        1- add new customer account          " << endl;
	cout << "        2- view customer accounts            " << endl;
	cout << "        3- change the status of an account   " << endl;
	cout << "        4- display the list of loans for a specific customer.       " << endl; 
	cout << "        5-  Change the status of a loan      " << endl;
	cout << "        6- approve or reject loan requests   " << endl;
	cout << "        7- manage a daily stack of transactions  " << endl;
    cout << "_____________________________________________________________" << endl;
    cout << "_____________________________________________________________" << endl;
    cout << "        8_exist                                     " << endl;
	cout << "_____________________________________________________________" << endl;
	cout << "_____________________________________________________________" << endl;
    cout << "               where do you want to enter ?                   " << endl;
	int operation;
	cin >> operation ;

}
int main() {
    cout << "|____________________________________________________________| " << endl;
    cout << "|____________________________________________________________| " << endl;
    cout << "|__________welcome to the Banking Management System__________| " << endl;
    cout << "|____________________________________________________________| " << endl;
    cout << "|____________________________________________________________|" << endl;
    cout << "|                  1-Cutomer intefrace                       | " << endl;
    cout << "|                  2-Emplpyee intefrace                      |" << endl;
    cout << "|____________________________________________________________|" << endl;
    cout << "|____________________________________________________________| " << endl;
    cout << "|                  3-Exist                                   |" << endl;
    cout << "|____________________________________________________________|" << endl;
    cout << "|____________________________________________________________|" << endl;
    cout << "               where do you want to enter ?                   " << endl;
    int r;
    cin >> r;

    if (r == 1) {
        cout << "enter your account number :";
        int acc_number;
        cin >> acc_number;
        int c = login(Accounts, acc_number, maxaccount);
        if (c >= 0) {
            cout << "-------------------login successful!-----------------" << endl;
            customer_interface(Accounts, maxaccount, c, loan_request);
        }
        
    }
    else if (r == 2) {
        cout << "---------------employee interface--------------- "<< endl;
		cout << "------------------------------------------------" << endl;
        cout << "             enter your employee ID :           " << endl;
		int emp_id;
		cin >> emp_id;
        int e = loginemployee(employees , emp_id, count );
        if (e >= 0) {
            cout << "login successful!" << endl;
			employee_interface(employees, count, e, Accounts, maxaccount, loan_request);
		}
    }
    else if (r == 3) {
        cout << "exist the system !" << endl;
    }
    else {
		cout << "verify your choice !" << endl;
       

}


