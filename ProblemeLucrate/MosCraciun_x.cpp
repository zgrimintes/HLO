///REZOLVARE DE 100 DE PUNCTE
#include <fstream>

using namespace std;

ifstream fin("moscraciun_x.in");
ofstream fout("moscraciun_x.out");

int mat[1005][1005];
int n, m;
int cnt_spir, max_spir;

int dI[4] = { -1, 0, 1, 0 },
dJ[4] = { 0, 1, 0, -1 };

void bordare() {
	for (int i = 0; i <= n + 1; i++)
		mat[i][0] = mat[i][m + 1] = -1;

	for (int i = 0; i <= m + 1; i++)
		mat[0][i] = mat[n + 1][i] = -1;
}

void citire() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			fin >> mat[i][j];
}

void fill(int i, int j) {
	if (mat[i][j] < 1) return;

	if (mat[i][j] == 2) cnt_spir++;
	mat[i][j] = 0;

	for (int k = 0; k < 4; k++) {
		int in = i + dI[k],
			jn = j + dJ[k];
		fill(in, jn);
	}
}

int main() {
	fin >> n >> m;
	citire();
	bordare();

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cnt_spir = 0;

			if (mat[i][j] >= 1)
				fill(i, j);

			if (cnt_spir > max_spir) max_spir = cnt_spir;
		}
	
	fout << max_spir;

	return 0;
}
