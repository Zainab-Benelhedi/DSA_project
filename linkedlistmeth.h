#ifndef LINKEDLISTMETH_H
#define LINKEDLISTMETH_H
#include <iostream>
#include "linkedlist.h"
using namespace std;

node_loan* createnode(loan loan);
node_loan_completed* createnodeloan_complete(loan loan);


void destroynode_loan (node_loan* p);
void destroynode_loan_completed (node_loan_completed* p);


singlylist createsinglylist();
doublylist createdoublylist();


bool isEmptys(const singlylist& L);
bool isEmptyd(const doublylist& L);


int listSize(const singlylist& L);
int listSize(const doublylist& L);


int insertsinglylist(singlylist* L, loan l, int pos);
int insertdoublylist(doublylist* L, loan l, int pos);


int removeAtsinglylist(singlylist* L, int pos);
int removeAtdoublylist(doublylist* L, int pos);


loan getElementsinglylist(const singlylist& L, int pos);
loan getElementdoublylist(const doublylist& L, int pos);


void displayList(const singlylist& L);
void displayList(const doublylist& L);



#endif

