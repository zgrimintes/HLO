///REZOLVARE DE 50 DE PUNCTE - PRIMA CERINTA
#include <fstream>
#define MOD 20173333

typedef long long LL;

using namespace std;

ifstream fin("sir9.in");
ofstream fout("sir9.out");

int n, p, x;

LL factMod(int x) {
	LL rez = 1;
	for (int i = 1; i <= x; i++)
		rez = rez * i % MOD;

	return rez;
}

LL modPow(LL b, LL e) {
	LL rez = 1;

	while (e) {
		if (e & 1)
			rez = rez * b % MOD;
		b = b * b % MOD;
		e /= 2;
	}

	return rez;
}

LL solve1() {
	LL sus = 1, jos = 1;
	
	for (int i = 1; i < x; i++)
		sus = sus * (n + i) % MOD;

	jos = modPow(factMod(x - 1), MOD - 2);

	return sus * jos % MOD;
}

LL solve2() {
	LL r = 0;
	for (int i = 1; i <= n; i++) {
		int cpy_n = n - x;
	}
}

int main() {
	fin >> p >> n >> x;

	if (p == 1) {
		n -= x;
		fout << solve1();
	}
	else {
		fout << solve2();
	}

	return 0;
}
