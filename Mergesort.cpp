#include <iostream>
using namespace std;

struct node {
	int val;
	node* next;
};

void show(node *H);
void add(node *&H, int x);
void delNode(node *&H);
void mergesort(node * &H);
void merge(node *&H, node *&P, node *&E);
void divide(node *&H, node *&P, node *&E);
void addToEnd(node *&T, node *&P);


int main()
{
	node * H = NULL;
	add(H, 11);
	add(H, 15);
	add(H, 1);
	add(H, 13);
	add(H, 3);
	add(H, 8);
	add(H, 23);
	add(H, 0);
	add(H, 1);
	show(H);
	mergesort(H);
	show(H);

	system("pause");
}

void show(node *H) {
	node *P = H;
	while (P != NULL) {
		cout << P->val << " -> ";
		P = P->next;
	}
	cout << "NULL" << endl;
}

void add(node *&H, int x) {
	node * P = new node;
	P->val = x;
	P->next = H;
	H = P;
}

void delNode(node *&H) {
	if (H != NULL) {
		node * P = H;
		H = H->next;
		delete P;
	}
}

void mergesort(node *&H) {
	if (H != NULL && H->next != NULL) {

		node * L = NULL;
		node * R = NULL;

		divide(H, L, R);

		mergesort(L);
		mergesort(R);

		merge(H, L, R);
	}
}

void merge(node *&H, node *&L, node *&R) {
	add(H, 0);
	node * T = H;
	while (L != NULL && R != NULL) {
		if (L->val <= R->val) {
			addToEnd(T, L);
		}
		else {
			addToEnd(T, R);
		}
	}
	if (L != NULL) {
		T->next = L;
		L = NULL;
	}
	if (R != NULL) {
		T->next = R;
		R = NULL;
	}
	delNode(H);
}

void divide(node *&H, node *&L, node *&R) {
	add(L, 0);
	node * T1 = L;

	add(R, 0);
	node * T2 = R;

	while (H != NULL) {
		addToEnd(T1, H);
		if (H != NULL) {
			addToEnd(T2, H);
		}
	}
	delNode(L);
	delNode(R);
}

void addToEnd(node *&T, node *&P) {
	T->next = P;
	P = P->next;
	T = T->next;
	T->next = NULL;
}