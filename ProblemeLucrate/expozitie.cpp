///REZOLVARE DE 100 DE PUNCTE
#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("expozitie.in");
ofstream fout("expozitie.out");

int n, d, k;
int nrMare[1001];

void multiplication(int nb) {
	int t = 0;
	for (int i = 1; i <= nrMare[0]; i++) {
		t += nrMare[i] * nb;
		nrMare[i] = t % 10;
		t /= 10;
	}

	while (t) {
		nrMare[0]++;
		nrMare[nrMare[0]] = t % 10;
		t /= 10;
	}
}

void division(int nb) {
	int r = 0;
	for (int i = nrMare[0]; i > 0; i--) {
		r = r * 10 + nrMare[i];
		nrMare[i] = r / nb;
		r = r % nb;
	}

	while (nrMare[nrMare[0]] == 0 && nrMare[0] > 1)
		nrMare[0]--;
}

void afisare() {
	for (int i = nrMare[0]; i > 0; i--)
		fout << nrMare[i];
}

void solve(int n, int k) {
	nrMare[0] = 1;
	nrMare[1] = 1;

	for (int i = 1; i <= k; i++) {
		multiplication(i + n);
		division(i);
	}

	afisare();
}

int main() {
	fin >> n >> d >> k;

	if (n - d * k >= 0)
		solve(n - d * k, d - 1);
	else
		fout << 0;

	return 0;
}
