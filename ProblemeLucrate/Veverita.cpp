///REZOLVARE DE 100 DE PUNCTE
#include <iostream>
#include <fstream>
#define MOD 666013

using namespace std;

ifstream fin("veverita.in");
ofstream fout("veverita.out");

long long n;
int nrMare[1005];

void multiply(int n) {
	int t = 0;
	for (int i = 1; i <= nrMare[0]; i++) {
		t += nrMare[i] * n;
		nrMare[i] = t % 10;
		t /= 10;
	}

	while (t) {
		nrMare[0]++;
		nrMare[nrMare[0]] = t % 10;
		t /= 10;
	}
}

void afisare() {
	for (int i = nrMare[0]; i > 0; i--)
		fout << nrMare[i];
}

long long modPow(long long b, long long e) {
	long long rez = 1;

	while (e) {
		if (e % 2 == 1)
			rez = b * rez % MOD;
		b = b * b % MOD;
		e /= 2;
	}

	return rez % MOD;
}

int main() {
	fin >> n;

	if (n <= 1000) {
		nrMare[0] = 1;
		nrMare[1] = (n % 2 == 0) ? 2 : 3;
		n /= 2;
		for (int i = 1; i <= n; i++)
			multiply(2);
		afisare();
	}
	else {
		long long rez = (n % 2 == 0) ? 2 : 3;

		n /= 2;
		rez = rez * modPow(2, n) % MOD;
		fout << rez % MOD;
	}

	return 0;
}
