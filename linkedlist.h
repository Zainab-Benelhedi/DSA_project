#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include "customer.h"
#include "loan.h"
#include "employee.h"
#include "transaction.h"

struct node_loan {
	loan l;
	node_loan* next;
	node_loan* prv;
};

struct node_loan_completed {
	loan completed_loan ;
	node_loan_completed* next;
};

struct singlylist {
	node_loan_completed* head;
	int size;
};

struct doublylist {
	node_loan* head;
	node_loan* tail;
	int size;
};
 const int Max = 1000;
struct stack {
	transaction  element[Max];
	transaction  top;
	
};

#endif 
