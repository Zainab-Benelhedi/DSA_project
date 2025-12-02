#ifndef STACK_H
#define STACK_H
#include "transaction.h"
const int Max = 100;
struct stack {
	transaction  element[Max];
	int top;
};
#endif // !STACK_H
