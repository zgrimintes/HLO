#include <iostream>
#include <fstream>

std::ifstream cin("nrmari.in");
std::ofstream cout("nrmari.out");

struct NrMare
{
	int nr[1001];

	NrMare(int n){
		nr[0] = n;
		//nr[1] = n;
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
		cout << "\n";
	}

	void operator +(NrMare Nr2) {

		int lng = std::max(nr[0], Nr2.nr[0]);

		for (int i = nr[0] + 1; i <= lng; i++) nr[i] = 0;
		for (int i = Nr2.nr[0] + 1; i <= lng; i++) Nr2.nr[i] = 0;

		nr[0] = lng;
		int t = 0;

		for (int i = 1; i <= nr[0]; i++) {
			nr[i] = nr[i] + Nr2.nr[i] + t;
			t = nr[i] / 10;
			nr[i] = nr[i] % 10;
		}

		if (t != 0) {
			nr[0]++;
			nr[nr[0]] = t;
		}
	}

	void operator *(int n) {
		int t = 0;
		for (int i = 1; i <= nr[0]; i++) {
			nr[i] = nr[i] * n + t;
			nr[i] %= 10;
			t /= 10;
		}

		while (t) {
			nr[0]++;
			nr[nr[0]] = t % 10;
			t /= 10;
		}
	}

	NrMare operator *(NrMare Nr2) {
		NrMare rez(nr[0] + Nr2.nr[0] - 1);

		for (int i = 1; i <= rez.nr[0] + 1; i++)
			rez.nr[i] = 0;

		for (int i = 1; i <= nr[0]; i++) 
			for (int j = 1; j <= Nr2.nr[0]; j++) 
				rez.nr[i + j - 1] += nr[i] * Nr2.nr[j];
			
		int t = 0;
		for (int i = 1; i <= rez.nr[0]; i++) {
			rez.nr[i] += t;
			t = rez.nr[i] / 10;
			rez.nr[i] %= 10;
		}

		if (t != 0) {
			rez.nr[0]++;
			rez.nr[rez.nr[0]] = t;
		}

		return rez;
	}

	void operator -(NrMare Nr2) {
		///presupun ca nr > Nr2.nr

		for (int i = Nr2.nr[0] + 1; i <= nr[0]; i++)
			Nr2.nr[i] = 0;

		int t = 0;
		for (int i = 1; i <= nr[0]; i++) {
			nr[i] = nr[i] - Nr2.nr[i] - t;
			if (nr[i] < 0) {
				t = 1;
				nr[i] += 10;
			}
			else t = 0;
		}

		while (nr[nr[0]] == 0 && nr[0] > 1) {
			nr[0]--;
		}
	}

	void operator /(int n) {
		int r = 0;
		for (int i = nr[0]; i > 0; i--) {
			r = r * 10 + nr[i];
			nr[i] = r / n;
			r = r % n;
		}

		while (nr[nr[0]] == 0 && nr[0] > 1)
			nr[0]--;
	}

	void operator =(NrMare Nr2) {
		nr[0] = Nr2.nr[0];

		for (int i = 1; i <= nr[0]; i++) 
			nr[i] = Nr2.nr[i];
		
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

	n1 * 2;
	n1.afisare();

	n1 = n1 * n2;
	n1.afisare();

	n1 - n2;
	n1.afisare();
	
	n1 / 100;
	n1.afisare();

	return 0;
}
