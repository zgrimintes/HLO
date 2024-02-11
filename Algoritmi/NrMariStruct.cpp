#include <iostream>
#include <fstream>

std::ifstream cin("nrmari.in");
std::ofstream cout("nrmari.out");

struct NrMare
{
	int nr[1001];

	NrMare(int n){
		nr[0] = 1;
		nr[1] = n;
	}

	NrMare(int n, int cif[1000]) {
		nr[0] = n;

		for (int i = 1; i <= nr[0]; i++) {
			nr[i] = cif[i];
		}
	}

	void afisare() {
		for (int i = nr[0]; i > 0; i--)
			cout << nr[i];
	}

	NrMare operator +(NrMare Nr2) {
		NrMare rez(0);

		int lng = std::max(nr[0], Nr2.nr[0]);

		for (int i = nr[0] + 1; i <= lng; i++) nr[i] = 0;
		for (int i = Nr2.nr[0] + 1; i <= lng; i++) Nr2.nr[i] = 0;

		rez.nr[0] = lng;
		nr[0] = lng;
		int t = 0;

		for (int i = 1; i <= rez.nr[0]; i++) {
			rez.nr[i] = nr[i] + Nr2.nr[i] + t;
			t = rez.nr[i] / 10;
			rez.nr[i] = rez.nr[i] % 10;
		}

		if (t != 0) {
			rez.nr[0]++;
			rez.nr[rez.nr[0]] = t;
		}

		return rez;
	}
};

void citire(int n, int *nr) {
	for (int i = 1; i <= n; i++)
		cin >> nr[i];
}

int main() {
	int n;
	int cif[1000];
	cin >> n; 
	citire(n, cif);

	NrMare n1(n, cif);
	
	cin >> n;
	citire(n, cif);

	NrMare n2(n, cif);

	n1 + n2;

	n1.afisare();

	return 0;
}
