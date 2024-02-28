///REZOLVARE DE 48 DE PUNCTE - C1, C2 parital
#include <fstream>
#include <cstring>
#include <limits.h>

#define MOD 666013

using namespace std;

ifstream fin("circular.in");
ofstream fout("circular.out");

int c, t_min = INT_MAX, cnt_sol = 1, t_tot;
int dp[30][30];
char a[50001];
char r[26];
char sol[50030], ind_sol;

void solve1() {
	t_min = 0;
	char limba = 'A';
	for (int i = 0; a[i]; i++) {
		t_min += min(abs(limba - a[i]), 26 - abs(limba - a[i]));
		limba = a[i];
	}
}

void precalc() {
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			dp[i][j] = min(abs(('A' - i) - ('A' - j)), 26 - abs((('A' - i) - ('A' - j))));
		}
	}
}

void solve2() {
	for (int i = 0; a[i + 1]; i++) {
		sol[ind_sol++] = a[i];
		t_min = INT_MAX;
		int cnt_same = 0;
		for (int j = 0; r[j]; j++) {
			if ((dp[a[i] - 'A'][r[j] - 'A'] + dp[r[j] - 'A'][a[i + 1] - 'A']) < t_min) {
				sol[ind_sol] = r[j];
				t_min = (dp[a[i] - 'A'][r[j] - 'A'] + dp[r[j] - 'A'][a[i + 1] - 'A']);
				cnt_same = 1;
			}
			else if ((dp[a[i] - 'A'][r[j] - 'A'] + dp[r[j] - 'A'][a[i + 1] - 'A']) == t_min) cnt_same = (cnt_same + 1) % MOD;
		}

		cnt_sol = cnt_sol * cnt_same % MOD;
		t_tot = (t_min + t_tot) % MOD;
		ind_sol++;
	}

	sol[ind_sol] = a[strlen(a) - 1];
	t_tot = (t_tot + min(abs('A' - a[0]), 26 - abs('A' - a[0]))) % MOD;
}

int main() {
	fin >> c;
	fin.get();
	fin.getline(a, 50001);
	fin.getline(r, 26);
	precalc();

	if (c == 1) {
		solve1();
		fout << t_min;
	}
	else {
		solve2();
		fout << t_tot << "\n" << cnt_sol << "\n" << sol;
	}

	return 0;
}
