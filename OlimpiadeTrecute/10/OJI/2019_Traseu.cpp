///REZOLVARE DE 33 PUNCTE
#include <fstream>
#include <queue>

using namespace std;

ifstream fin("traseu.in");
ofstream fout("traseu.out");

int dI[2] = { 0, 1 },
	dJ[2] = { 1, 0 };

queue <pair<int, int>> Q;
int mat[505][505];
int cost[505][505];
int n, m;
int d_max, cnt_d;

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

	bordare();
}

void reset_cost() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cost[i][j] = 0;
}

void solve(int i, int j) {
	int ns = mat[i][j];
	Q.push({ i, j });

	while (!Q.empty()) {
		int x = Q.front().first,
			y = Q.front().second;

		Q.pop();

		for (int k = 0; k < 2; k++) {
			int iv = x + dI[k],
				jv = y + dJ[k];

			if (cost[iv][jv] != 0 || mat[iv][jv] == -1) continue;

			Q.push({ iv, jv });
			cost[iv][jv] = cost[x][y] + 1;
		}
	}

	for (int k = 1; k <= n; k++) {
		if (mat[k][m] < ns) cost[k][m] = 0;

		if (d_max < cost[k][m]) d_max = cost[k][m];
	}

	for (int k = 1; k <= n; k++) {
		if (mat[n][k] < ns) cost[n][k] = 0;

		if (d_max < cost[n][k]) d_max = cost[n][k];
	}

	reset_cost();
}

int main() {
	fin >> n >> m;
	citire();

	for (int i = 1; i < n; i++)
		for (int j = 1; j < m; j++)
			solve(i, j);

	if (!d_max) {
		fout << 0;
		return 0;
	}

	fout << d_max + 1;
	return 0;
}
