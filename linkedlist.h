#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include "customer.h"
#include "loan.h"
#include "employee.h"

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
#endif  // !LINKEDLIST_H