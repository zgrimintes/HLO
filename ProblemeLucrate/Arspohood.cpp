///DE TERMINAT SI INTELES
#include <fstream>
#define MOD 666013

typedef long long LL;

using namespace std;

ifstream fin("arpsohood.in");
ofstream fout("arpsohood.out");

int n, k;
int mat[505][505];

LL factMod(LL x) {
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

	return rez % MOD;
}

LL comb(LL n, LL k) {
	LL sus = factMod(n);
	LL jos = modPow(factMod(n - k) * factMod(k) % MOD, MOD - 2);

	return sus * jos % MOD;
}

void solve() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			LL sum = 0;

			for (int l = 1; l < j; l++) {
				sum += comb(j, l) * mat[i][l] & MOD;
			}

			mat[i][j] = modPow(j, i) - sum;
		}
	}
}

int main() {
	fin >> n >> k;
	solve();
	fout << mat[n][k];

	return 0;
}
