///REZOLVARE DE 54 DE PUNCTE
#include <fstream>

using namespace std;

ifstream fin("alinieri.in");
ofstream fout("alinieri.out");

int n, p, z;
int vel[181], poz[181];
int cnt_aln;

void citire() {
	int cn = n;
	while (cn) {
		int v;
		fin >> v;
		vel[v%180]++;

		cn--;
	}
}

void solve() {
	for (int d = 1; d <= z; d++) {
		int temp_aln = 0;
		for (int i = 0; i < 180; i++) poz[i] = 0;

		for (int i = 0; i < 180; i++)
			if (vel[i]) poz[(i * d) % 180] += vel[i];

		for (int i = 0; i < 180; i++)
			if (poz[i] >= p) temp_aln++;

		cnt_aln += temp_aln;
	}
}

int main() {
	fin >> n >> p >> z;
	citire();
	solve();

	fout << cnt_aln;

	return 0;
}

///REZOLVARE DE 100 DE PUNCTE
#include <fstream>

using namespace std;

ifstream fin("alinieri.in");
ofstream fout("alinieri.out");

int n, p, z;
int vel[181], poz[181];
int cnt_aln;

void citire() {
	int cn = n;
	while (cn) {
		int v;
		fin >> v;
		vel[v%180]++;

		cn--;
	}
}

void solve() {
	for (int d = 1; d <= 180; d++) {
		int temp_aln = 0;
		for (int i = 0; i < 180; i++) poz[i] = 0;

		for (int i = 0; i < 180; i++)
			if (vel[i]) poz[(i * d) % 180] += vel[i];

		for (int i = 0; i < 180; i++)
			if (poz[i] >= p) temp_aln++;

		cnt_aln += temp_aln;
	}

	cnt_aln *= (z / 360) * 2;

	for (int d = 1; d <= z % 360; d++) {
		int temp_aln = 0;
		for (int i = 0; i < 180; i++) poz[i] = 0;

		for (int i = 0; i < 180; i++)
			if (vel[i]) poz[(i * d) % 180] += vel[i];

		for (int i = 0; i < 180; i++)
			if (poz[i] >= p) temp_aln++;

		cnt_aln += temp_aln;
	}
}

int main() {
	fin >> n >> p >> z;
	citire();
	solve();

	fout << cnt_aln;

	return 0;
}
