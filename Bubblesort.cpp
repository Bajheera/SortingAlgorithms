#include <iostream>
using namespace std;

struct node {
	int val;
	node* next;
};

void show(node *H);
void add(node *&H, int x);
void bubblesort(node *&H);
void swap(node *&P, node *&E);


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
	bubblesort(H);
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

void bubblesort(node *&H) {
	if (H != NULL && H->next != NULL) {
		node * T = H;
		while (T->next != NULL) {
			T = T->next;
		}
		bool count = true;
		do {
			count = false;
			if (H->val > H->next->val) {
				node * P = H;
				H = H->next;
				P->next = H->next;
				H->next = P;
				count = true;
			}
			else {
				if (H->next->next != NULL) {
					node * P = H;
					node * E = H->next->next;
					while (E != T) {
						if (P->next->val > E->val) {
							swap(P, E);
							count = true;
						}
						P = P->next;
						E = E->next;
					}
					if (P->next->val > T->val) {
						swap(P, T);
						count = true;
						continue;
					}
					T = P->next;
				}
			}
		} while (count == true);
	}
}

void swap(node *&P, node *&E) {
	P->next->next = E->next;
	E->next = P->next;
	P->next = E;
	E = E->next;
}
