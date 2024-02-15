///REZOLVARE DE 50 DE PUNCTE
#include <fstream>
#include <iostream>

typedef long long LL;

using namespace std;

ifstream fin("arhitect.in");
ofstream fout("arhitect.out");

int n;
pair<LL, LL> m[100001];
bool verif[100001];
int max_parallel;

void citire() {
	int cn = n, ind_m = 0;
	while (cn) {
		int x1, y1, x2, y2;
		fin >> x1 >> y1 >> x2 >> y2;

		m[ind_m++] = { y1 - y2, x1 - x2 };
		if (m[ind_m - 1].first < 0 && m[ind_m - 1].second < 0)
			m[ind_m - 1].first = 0 - m[ind_m - 1].first, 
			m[ind_m - 1].second = 0 - m[ind_m - 1].second;

		cn--;
	}
}

bool isParallel(pair <LL, LL> m1, pair <LL, LL> m2) {
	return (m1.first * m2.second) == (m1.second * m2.first);
}

bool isPerpendicular(pair <LL, LL> m1, pair <LL, LL> m2) {
	if (m1.first == 0 || m1.second == 0)
		return (m2.first == 0 || m2.second == 0);

	if (m2.first == 0 || m2.second == 0)
		return (m1.first == 0 || m1.second == 0);

	return (((m1.first * m2.first) / (m1.second * m2.second)) == -1) && (((m1.first * m2.first) % (m1.second * m2.second)) == 0);
}

int solve() {
	int cnt_prll = 0;

	for (int i = 0; i < n; i++) {
		cnt_prll = 1;

		if (verif[i]) continue;

		verif[i] = true;
		pair <LL, LL> local_m = m[i];

		for (int j = i + 1; j < n; j++) {
			if (verif[j]) continue;

			if (isParallel(local_m, m[j]) || isPerpendicular(local_m, m[j])) {
				verif[i] = true;
				cnt_prll++;
			}
		}

		if (cnt_prll > max_parallel) max_parallel = cnt_prll;
		
	}

	return max_parallel;
}

int main() {

	fin >> n;
	citire();
	fout << solve();

	return 0;
}
