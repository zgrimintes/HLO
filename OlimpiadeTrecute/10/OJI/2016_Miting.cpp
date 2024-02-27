///REZOLVARE DE 45 DE PUNCTE - C1, C2 PARTIAL
#include <fstream>
#include <cstring>
#include <queue>

#define NMAX 1000000001

using namespace std;

ifstream fin("miting.in");
ofstream fout("miting.out");

struct Tinar
{
	int x, y;
	char lit;
	bool bun;
};

int dI[4] = { -1, 0, 1, 0 },
	dJ[4] = { 0, 1, 0, -1 };

queue <pair <int, int>> Q;
Tinar tineri[11];
int c, n, m, ind_t;
char cuv[1000];
int mat[65][65], cMat[65][65];
int i_min = 100, j_min = 100, i_max, j_max, cnt_comb, min_comb = NMAX;

void checkLetter(char c) {
	if (strchr(cuv, c)) 
		tineri[ind_t].bun = true;
}

void bordare() {
	for (int i = 0; i <= n + 1; i++)
		mat[i][0] = mat[i][m + 1] = -1;

	for (int i = 0; i <= m + 1; i++)
		mat[0][i] = mat[n + 1][i] = -1;
}

void citire() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			char temp;
			fin >> temp;
			switch (temp)
			{
			case '#':
				mat[i][j] = cMat[i][j] = - 1;
				break;
			case '_':
				mat[i][j] = cMat[i][j] = 0;
				break;
			default:
				mat[i][j] = cMat[i][j] = 0;
				tineri[ind_t].x = i;
				tineri[ind_t].y = j;
				tineri[ind_t].lit = temp;

				if (i < i_min) i_min = i;
				if (j < j_min) j_min = j;

				if (i > i_max) i_max = i;
				if (j > j_max) j_max = j;
				
				checkLetter(temp);
				ind_t++;

				break;
			}
		}

	bordare();
}

void Lee(int i, int j) {
	Q.push({ i, j });

	mat[i][j] = -1;

	while (!Q.empty()) {
		int x = Q.front().first,
			y = Q.front().second;

		Q.pop();
		
		for (int k = 0; k < 4; k++) {
			int iv = dI[k] + x,
				jv = dJ[k] + y;

			if (mat[iv][jv] != 0) continue;

			Q.push({ iv, jv });
			mat[iv][jv] = mat[x][y] + 1;
			if (mat[x][y] == -1) mat[iv][jv] = 1;
		}
	}
}

void reset() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			mat[i][j] = cMat[i][j];
}

void checkTineri() {
	for (int i = 0; i < ind_t; i++) {
		if (tineri[i].bun && mat[tineri[i].x][tineri[i].y] > 0)
			cnt_comb += mat[tineri[i].x][tineri[i].y];
		else if (mat[tineri[i].x][tineri[i].y] == 0)
			cnt_comb = NMAX;
	}
}

int main() {
	fin >> c >> n >> m;
	fin.get();
	fin.getline(cuv, 1000);
	citire();

	if (c == 1) {
		fout << (i_max - i_min + 1) * (j_max - j_min + 1);
	}
	else {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (mat[i][j] == 0) {
					Lee(i, j);
					
					if (i == 5 && j == 6)
						fout << "";

					checkTineri();

					if (cnt_comb < min_comb && cnt_comb) min_comb = cnt_comb;

					cnt_comb = 0;
					reset();
				}
			}
		}

		fout << min_comb;
	}

	return 0;
}
