#include <iostream>

using namespace std;

struct nod {
	int val;
	nod* adr;
};

void citire(nod * u, int n) {
	for (int i = 1; i < n; i++) {
		nod* temp = new nod;
		cin >> temp->val;
		temp->adr = 0;
		u->adr = temp;
		u = temp;
	}
}

void afisare(nod* p) {
	for (nod* temp = p; temp; temp = temp->adr)
		cout << temp->val << " ";
}

int suma(nod* p) {
	nod* prev = p;
	int sum = 0;

	for (nod* temp = p->adr; temp->adr; temp = temp->adr) {
		if (prev->val % 2 == 0 && temp->adr->val % 2 == 0) sum += temp->val;

		prev = temp;
	}

	return sum;
}

void ad_icp(nod* &p, const int val) {
	nod* temp = new nod;
	temp->val = val;

	if (p == NULL) temp->adr = 0;
	else temp->adr = p;
	
	p = temp;
}

int main() {
	nod *p, *u;
	p = new nod;
	int n; cin >> n;
	cin >> p->val;
	p->adr = 0;
	u = p;
	citire(u, n);
	//cout << suma(p);
	int val; cin >> val;
	ad_icp(p, val);
	afisare(p);
	return 0;
}
