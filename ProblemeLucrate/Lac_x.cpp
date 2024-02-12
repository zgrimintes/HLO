///REZOLVARE DE 100 DE PUNCTE
#include <fstream>

using namespace std;

ifstream fin("lac_x.in");
ofstream fout("lac_x.out");

int mat[1005][1005];
int n, m;
int max_pen, max_in;
int cnt_arie;
bool insula;

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
	if (mat[i][j] == -1) insula = false;
	if (mat[i][j] != 1) return;

	mat[i][j] = 0;
	cnt_arie++;

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
			insula = true;
			cnt_arie = 0;

			if (mat[i][j] == 1)
				fill(i, j);

			if (insula) {
				if (cnt_arie > max_in)
					max_in = cnt_arie;
			}
			else {
				if (cnt_arie > max_pen)
					max_pen = cnt_arie;
			}

		}

	fout << max_in << " " << max_pen;

	return 0;
}
