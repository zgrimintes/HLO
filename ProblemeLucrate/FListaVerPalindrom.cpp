#include <iostream>

using namespace std;

struct Node {
	int val;
	Node* adr;
};

void addToFront(Node* &p, int x) {
	if (p == 0) {
		p = new Node;
		p->val = x;
		p->adr = 0;
		return;
	}

	Node* q = p;
	while (q->adr) q = q->adr;

	q->adr = new Node;
	q = q->adr;
	q->val = x;
	q->adr = 0;
}

void addToBack(Node*& p, int x) {
	if (p == 0) {
		p = new Node;
		p->val = x;
		p->adr = 0;
		return;
	}

	Node* q = new Node;
	q->adr = p;
	q->val = x;
	p = q;
}

bool palindrom(Node* l) {
	Node* f = new Node;
	Node* q = l;

	while (q) {
		addToBack(f, q->val);
		q = q->adr;
	}

	while (f && l) {
		if (f->val != l->val) return false;
		
		f = f->adr;
		l = l->adr;
	}

	return true;
}

int main() {
	int n;
	cin >> n;

	Node* p;
	p = NULL;

	while (n) {
		int x; cin >> x;
		addToFront(p, x);
		n--;
	}

	cout << palindrom(p);
	return 0;
}
