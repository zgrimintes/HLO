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
int chars[27];
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
	for (int k = 0; k < 4; k++) {
		int ni = i + di[k],
			nj = j + dj[k];
		if (ferm2[ni][nj] != 0 && ferm2[ni][nj] != d) {
			vec[k] = cferm[ni][nj];
			vecc[k] = ferm2[ni][nj];
		}
	}

	if (vec[0] != 0 && vec[0] == vec[1]) {
		if (vecc[0] != vecc[1]) cnt_sup2 = 1 + sup_all[ferm2[i - 1][j]] + sup_all[ferm2[i][j + 1]];
		else cnt_sup2 = 1 + sup_all[ferm2[i - 1][j]];
		c_cel = cferm[i - 1][j];
	}
	else if (vec[0] != 0 && vec[0] == vec[2]) {
		if (vecc[0] != vecc[2]) cnt_sup2 = 1 + sup_all[ferm2[i - 1][j]] + sup_all[ferm2[i + 1][j]];
		else cnt_sup2 = 1 + sup_all[ferm2[i - 1][j]];
		c_cel = cferm[i - 1][j];
	}
	else if (vec[0] != 0 && vec[0] == vec[3]) {
		if (vecc[0] != vecc[3]) cnt_sup2 = 1 + sup_all[ferm2[i - 1][j]] + sup_all[ferm2[i][j - 1]];
		else cnt_sup2 = 1 + sup_all[ferm2[i - 1][j]];
		c_cel = cferm[i - 1][j];
	}
	else if (vec[1] != 0 && vec[2] == vec[2]) {
		if (vecc[1] != vecc[1]) cnt_sup2 = 1 + sup_all[ferm2[i][j + 1]] + sup_all[ferm2[i + 1][j]];
		else cnt_sup2 = 1 + sup_all[ferm2[i][j + 1]];
		c_cel = cferm[i][j + 1];
	}
	else if (vec[1] != 0 && vec[3] == vec[3]) {
		if (vecc[1] != vecc[1]) cnt_sup2 = 1 + sup_all[ferm2[i][j + 1]] + sup_all[ferm2[i][j - 1]];
		else cnt_sup2 = 1 + sup_all[ferm2[i][j + 1]];
		c_cel = cferm[i][j + 1];
	}
	else if (vec[2] != 0 && vec[2] == vec[3]) {
		if (vecc[2] != vecc[2]) cnt_sup2 = 1 + sup_all[ferm2[i + 1][j]] + sup_all[ferm2[i][j - 1]];
		else cnt_sup2 = 1 + sup_all[ferm2[i + 1][j]];
		c_cel = cferm[i + 1][j];
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
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
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
