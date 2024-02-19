///REZOLVARE C1, C2 neeficient.
#include <fstream>

#define MOD 1000000007

typedef long long LL;

using namespace std;

ifstream fin("transport.in");
ofstream fout("transport.out");

struct Statie
{
	int x, d;
	LL vD, vS;
};

Statie s[2000001];
LL t, n, c;
LL ind_St;
LL cnt_rute;

void citire() {
	int cn = n;

	while (cn) {
		fin >> s[ind_St].x >> s[ind_St].d;
		s[ind_St].vD = s[ind_St].x * c - s[ind_St].d;
		s[ind_St].vS = s[ind_St].x * c + s[ind_St].d;
		ind_St++;
		cn--;
	}
}

LL powMod2(LL e) {
	LL rez = 2;
	LL b = 2;
	while (e) {
		if (e & 1)
			rez = rez * b % MOD;

		b = b * b % MOD;
		e /= 2;
	}

	return rez % MOD;
}

LL solve1() {
	for (int i = ind_St - 1; i > 1; i--) {
		for (int j = 0; j < i; j++) {
			if (s[i].vD != s[j].vS) continue;

			cnt_rute = (cnt_rute + 1) % MOD;
		}
	}

	return cnt_rute % MOD;
}

LL solve2() {
	for (int i = ind_St - 1; i > 1; i--) {
		for (int j = 0; j < i; j++) {
			if (s[i].vD != s[j].vS) continue;

			cnt_rute = (cnt_rute + powMod2(i - j - 2)) % MOD;
		}
	}

	return cnt_rute % MOD;
}

int main() {
	fin >> t >> n >> c;
	citire();

	if (t == 1)
		fout << solve1();
	else
		fout << solve2();

	return 0;
}
