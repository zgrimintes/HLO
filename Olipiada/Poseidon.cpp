#include <fstream>
#include <queue>

#define MOD 1000000007

using namespace std;

ifstream fin("poseidon.in");
ofstream fout("poseidon.out");

int dI[4] = { -1, 0, 1, 0 },
	dJ[4] = { 0, 1, 0, -1 };

queue <pair<int, int>> Q;
int mat[1005][1005];
int c, n, m;
int xp, yp;
int cnt_t, ans;
int prm[11], ap[11];
int cnt_temp;

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

void fill(int xs, int ys) {
	Q.push({ xs, ys });
	if (mat[xs][ys] > 0) cnt_t++;
	mat[xs][ys] = -1;

	while (!Q.empty()) {
		int x = Q.front().first,
			y = Q.front().second;

		Q.pop();

		mat[x][y] = -1;

		for (int k = 0; k < 4; k++) {
			int ni = x + dI[k],
				nj = y + dJ[k];

			if (mat[ni][nj] < 0) continue;

			if (mat[ni][nj]) { cnt_t++; mat[ni][nj] = 0; }

			Q.push({ ni, nj });
		}
	}
}

bool checkOK() {
	for (int i = 1; i <= cnt_t; i++)
		if (prm[i - 1] == i) return false;

	return true;
}

void getPoss(int k) {
	if (k == cnt_t) {
		if (checkOK())
			cnt_temp = (cnt_temp + 1) % MOD;

		return;
	}

	for (int i = 1; i <= cnt_t; i++) {
		if (ap[i] == 0) {
			ap[i] = 1;
			prm[k] = i;
			getPoss(k + 1);
			ap[i] = 0;
		}
	}
}

int main() {
	fin >> c >> n >> m;
	citire();

	if (c == 1) {
		fin >> xp >> yp;
		fill(xp, yp);
		fout << cnt_t;
	}
	else {
		ans = 1;
		for (int i = 1; i <= n; i++) {
			cnt_t = cnt_temp = 0;
			for (int j = 1; j <= m; j++) {
				if (mat[i][j] >= 0)
					fill(i, j);
				if (i == 5)
					fout << "";

				getPoss(0);
				ans = ans * cnt_temp % MOD;

				cnt_t = cnt_temp = 0;
			}
		}

		fout << ans;
	}

	return 0;
}
