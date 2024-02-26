///C1
#include <fstream>
#include <queue>

using namespace std;

ifstream fin("rover.in");
ofstream fout("rover.out");

int dI[4] = { -1, 0, 1, 0 },
	dJ[4] = { 0, 1, 0, -1 };

queue <pair<int, int>> Q;
int mat[505][505];
int cost[505][505];
int v, n, g;
int min_dng;

void bordare() {
	for (int i = 0; i <= n + 1; i++)
		mat[0][i] = mat[n + 1][i] = mat[i][0] = mat[i][n + 1] = -1,
		cost[0][i] = cost[n + 1][i] = cost[i][0] = cost[i][n + 1] = -1;
}

void citire() {
	if (v == 1) fin >> g;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			fin >> mat[i][j];
	
	bordare();
}

int isDangerous(int d) {
	return d < g;
}

void LEEastDangerous() {
	Q.push({ 1, 1 });

	while (!Q.empty()) {
		int x = Q.front().first,
			y = Q.front().second;

		Q.pop();

		for (int k = 0; k < 4; k++) {
			int iv = dI[k] + x,
				jv = dJ[k] + y;

			if (mat[iv][jv] < 0) continue;

			if (cost[iv][jv] == 0 || cost[iv][jv] > (cost[x][y] + isDangerous(mat[iv][jv]))) {
				cost[iv][jv] = cost[x][y] + isDangerous(mat[iv][jv]);
				Q.push({ iv, jv });

				if (cost[iv][jv] == 0) mat[iv][jv] = -1;
			}
		}
	}
}

int main() {
	fin >> v >> n;
	citire();

	if (v == 1) {
		LEEastDangerous();
		fout << cost[n][n];
	}
	else {

	}

	return 0;
}
