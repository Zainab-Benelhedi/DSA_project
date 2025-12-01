
#include <iostream>
#include <new>
#include "linkedlistmeth.h"
#include "linkedlist.h"
using namespace std;
node_loan* createnode( loan l) {
	node_loan * p = new (nothrow) node_loan { l , nullptr , nullptr };
	if (!p) {
		cerr << "\nMemoryallocation failed for node\n";
	};
	return p;
};
node_loan_completed* createnodeloan_complete(loan l) {
	node_loan_completed* p = new (nothrow) node_loan_completed{ l , nullptr };
	if (!p) {
		cerr << "\nMemoryallocation failed for node\n";
	};
	return p;
};

void destroynode_loan(node_loan* p) {
	delete p;
};
void destroynode_loan_completed(node_loan_completed* p) {
	delete p;
};
singlylist createsinglylist() {
	singlylist l = singlylist{};
	return l ;
};
doublylist createdoublylist() {
	return doublylist{};
};
bool isEmptys(const singlylist& L) {
	return L.size == 0;
}
bool isEmptyd(const doublylist& L) {
	return L.size == 0;
}
int listSize(const singlylist& L) {
	return L.size;
}
int listSize(const doublylist& L) {
	return L.size;
}
//displaylist of loan it display id of loan
void displayList(const singlylist& L) {
	if (isEmptys(L)) {
		cout << "List is empty\n";
		return;
	}
	node_loan_completed* current = L.head;
	while (current) {
		cout << current->completed_loan.loan_ID << " -> ";
		current = current->next;
	}
	cout << "NULL\n";
}
void displayList(const doublylist& L) {
	if (isEmptyd(L)) {
		cout << "List is empty\n";
		return;
	}
	node_loan* current = L.head;
	while (current) {
		cout << current->l.loan_ID << " -> ";
		current = current->next;
	}
	cout << "NULL\n";
};
int removeAtdoublylist(doublylist* L, int pos) {
	if (!L || isEmptyd(*L)) {
		cout << "\nListis empty";
		return 0;
	}
	if (pos < 1 || pos > L->size) {
		cout << "\nInvalidposition";
		return 0;
	}
	node_loan* current;
	if (L->size == 1) {
		current = L->head;
		L->head = nullptr;
		L->tail = nullptr;
	}
	else if (pos == 1) {
		current = L->head;
		L->head = L->head->next;
		L->head->prv = nullptr;
	}
	else if (pos == L->size) {
		current = L->tail;
		L->tail = L->tail->prv;
		L->tail->next = nullptr;
	}
	else {
		node_loan* prevNode = nullptr;
		current = L->head;         
		for (int i = 1; i < pos; i++) {
			prevNode = current;
			current = current->next;
		}
		current->next->prv = prevNode;
		prevNode->next = current->next;
	}
	destroynode_loan(current);
	L->size--;
	return 1;
};
int removeAtsinglylist(singlylist* L, int pos) {

	if (!L || isEmptys(*L)) {
		cerr << "\nListis empty";
		return 0;
	}
	if (pos < 1 || pos > L->size) {
		cerr << "\nInvalidposition";
		return 0;
	}
	node_loan_completed* prev = nullptr;
	node_loan_completed* current = L->head;

	if (pos == 1) {
		L->head = current->next;
	}
	else {
		for (int i = 1; i < pos; i++) {
			prev = current;
			current = current->next;
		}
		prev->next = current->next;
	}
	destroynode_loan_completed(current);
	L->size--;
	return 1;
};


int insertdoublylist(doublylist* L, loan loan, int pos) {
	if (!L) return 0;
	if (pos < 1 || pos > L->size + 1) {
		cout << "\nInvalidposition";
		return 0;
	}
	node_loan* n = createnode(loan);
	if (!n) return 0;
	if (isEmptyd(*L)) {
		L->head = n;
		L->tail = n;
	}
	else if (pos == 1) {
		n->next = L->head;
		L->head->prv = n;
		L->head = n;
	}
	else if (pos == L->size + 1) {
		n->prv = L->tail;
		L->tail->next = n;
		L->tail = n;
	}
};
int insertsinglylist(singlylist* L, loan loan , int pos) {
	if (!L) return 0;
	if (pos < 1 || pos > L->size + 1) {
		cerr << "\nInvalidposition";
		return 0;
	}
	node_loan_completed* n = createnodeloan_complete(loan);
	if (!n) return 0;
	if (pos == 1) {
		n->next = L->head;
		L->head = n;
	}

	else {
		node_loan_completed* prv = nullptr;
		node_loan_completed* current = L->head;
		for (int i = 1; i < pos; i++) {
			prv = current;
			current = current->next;
		}
		prv->next = n;
		n->next = current;
	}
	L->size++;
	return 1;
}
loan getElementsinglylist(const singlylist& L, int pos ){
	if (isEmptys(L)) {
		cerr << "\nList is empty\n";
		return loan{};
	}
	if (pos < 1 || pos > L.size) {
		cerr << "\nInvalid position\n";
		return loan{};
	}
	node_loan_completed* current = L.head;
	for (int i = 1; i < pos; i++) {
		current = current->next;
	}
	return current->completed_loan;

};

loan getElementdoublylist(const doublylist& L, int pos) {
	if (isEmptyd(L)) {
		cerr << "\nList is empty\n";
		return loan{};
	}
	if (pos < 1 || pos > L.size) {
		cerr << "\nInvalid position\n";
		return loan{};
	}
	node_loan* current = L.head;
	for (int i = 1; i < pos; i++) {
		current = current->next;
	}
	return current->l;

};


	

		

