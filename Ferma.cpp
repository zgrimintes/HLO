//REZOLVARE DE 80 DE PUNCTE
#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("ferma.in");
ofstream fout("ferma.out");

char ferm[405][405];
char cferm[405][405];
int ferm2[405][405];
int sup_all[160002], ind_s = 1;
int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };
int cnt_sup = 0, sup_max = 0;
int cnt_sup2 = 0, sup_max2 = 0;
char c_cel, c_cel_max;
int i_fill, j_fill;

void citire(int n, int m) {
	char c;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			fin >> c;
			ferm[i][j] = cferm[i][j] = c;
		}
}

void bordare(int n, int m) {
	for (int i = 0; i < n; i++)
		ferm[i][0] = ferm[i][m] = -1;

	for (int i = 0; i < m; i++)
		ferm[0][i] = ferm[n][i] = -1;
}

void fill(int i, int j, char c) {
	if (ferm[i][j] != c) return;

	cnt_sup++;
	ferm[i][j] = '!';
	ferm2[i][j] = ind_s;

	for (int k = 0; k < 4; k++)
		fill(i + di[k], j + dj[k], c);
}

void checkVec(int i, int j, int d) {
	char vec[4] = { 0 };
	int vecc[4] = { 0 };
	int temp_max = 0;

	for (int k = 0; k < 4; k++) {
		int ni = i + di[k],
			nj = j + dj[k];
		if (ferm2[ni][nj] != 0 && ferm2[ni][nj] != d) {
			vec[k] = cferm[ni][nj];
			vecc[k] = ferm2[ni][nj];
		}
	}

	int cnt_temp = 0;
	for (int k = 0; k < 4; k++) if (vec[k] == 0)  cnt_temp++;

	if (cnt_temp < 3) {
		for (int k = 0; k < 3; k++) {
				int nik = i + di[k],
					njk = j + dj[k];
				cnt_sup2 = sup_all[ferm2[nik][njk]];

				for (int l = 1; l < 4 - k; l++) {
					if (k != l) {
						if (vec[k] != 0 && vec[k] == vec[l]) {
							int nil = i + di[l],
								njl = j + dj[l];

							if (vecc[k] != vecc[l]) cnt_sup2 += sup_all[ferm2[nil][njl]];

							c_cel = cferm[nik][njk];
						}
					}
				}

				if (cnt_sup2 > temp_max) temp_max = cnt_sup2;
			}

		cnt_sup2 = max(temp_max, cnt_sup2);
		cnt_sup2++;
	}
}

int main() {
	int C, n, m;
	fin >> C >> n >> m;
	citire(n, m);
	bordare(n + 1, m + 1);
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (ferm[i][j] != '!') {
				fill(i, j, ferm[i][j]);
				sup_all[ind_s++] = cnt_sup;
			}
			if (sup_max < cnt_sup) sup_max = cnt_sup;
			cnt_sup = 0;
		}
	}

	ind_s = 1;
	for (int i = 10; i <= n; i++)
		for (int j = 24; j <= m; j++) {
			cnt_sup2 = 0;
			checkVec(i, j, ferm2[i][j]);
			if (cnt_sup2 > sup_max2) {
				sup_max2 = cnt_sup2;
				i_fill = i;
				j_fill = j;
				c_cel_max = c_cel;
			}
		}

	if (C == 1) fout << sup_max;
	else if (C == 2) fout << i_fill << " " << j_fill << "\n" << c_cel_max;

	return 0;
}
