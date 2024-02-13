///REZOLVARE DE 100 PUNCTE
#include <fstream>

using namespace std;

ifstream fin("ronti.in");
ofstream fout("ronti.out");

int dI[4] = { -1, 0, 1, 0 },
	dJ[4] = { 0, 1, 0, -1 };

int grad[105][105];
int n, m, k;
int nrMorcv, morcv_max;
int iS, jS;

void citire() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			fin >> grad[i][j];
}

void bordare() {
	for (int i = 0; i <= n + 1; i++)
		grad[i][0] = grad[i][m + 1] = -1;

	for (int j = 0; j <= m + 1; j++)
		grad[0][j] = grad[n + 1][j] = -1;
}

void get_Morcovi(int i, int j) {
	if (i < 0 || j < 0) return;
	if (grad[i][j] <= 0) return;

	nrMorcv += grad[i][j];
	grad[i][j] = -1;

	for (int l = 0; l < 4; l++) {
		for (int m = 1; m <= k; m++) {
			int ni = i + dI[l] * m;
			int nj = j + dJ[l] * m;

			get_Morcovi(ni, nj);
		}
	}

}

int main() {
	fin >> n >> m >> k;
	citire();
	bordare();

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++){
			nrMorcv = 0;
			if (grad[i][j] > 0)
				get_Morcovi(i, j);

			if (nrMorcv > morcv_max) {
				morcv_max = nrMorcv;
				iS = i; jS = j;
			}
		}

	fout << iS << " " << jS << "\n" << morcv_max;

	return 0;
}
