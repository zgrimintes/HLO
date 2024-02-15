///REZOLVARE DE 100 DE PUNCTE
#include <fstream>

using namespace std;

ifstream fin("bile1.in");
ofstream fout("bile1.out");

int M[1001];
int n;

void multiply(int nb) {
	int t = 0;
	for (int i = 1; i <= M[0]; i++) {
		t += M[i] * nb;
		M[i] = t % 10;
		t /= 10;
	}

	while (t) {
		M[0]++;
		M[M[0]] = t % 10;
		t /= 10;
	}
}

void afisare() {
	for (int i = M[0]; i > 0; i--)
		fout << M[i];
}

void solve() {
	for (int i = 2; i <= n; i++)
		multiply(2);

	afisare();
}

int main() {
	M[0] = 1;
	M[1] = 3;

	fin >> n;
	solve();
	
	return 0;
}
