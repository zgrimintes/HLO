#include <iostream>
#include <fstream>
#include <queue>
#include <limits.h>

using namespace std;

ifstream fin("panda.in");
ofstream fout("panda.out");

queue< pair <int, int> > Q;
pair <int, int> mancare[25000]; int indxm = 0;
int tarc[505][505];
int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };
int cnt_cam = 0;
int L, C, k, s, t;
int cnt_smin = INT_MAX, cnt_manc = 0;

int ultimiiSBiti(int n) {
	int mask = (1u << s) - 1;
	return n & mask;
}

bool count_rooms(int n) {
	int complement = n ^ ultimiiSBiti(k);
	int allOnes = (1u << s) - 1;

	if (complement == allOnes) {
		cnt_cam++;
		return 1;
	}
	return 0;
}

void citire(int n, int m) {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			fin >> tarc[i][j];
			if (i != L || j != C) {
				if (count_rooms(ultimiiSBiti(tarc[i][j])) == 1)
					tarc[i][j] = 0;
				else
					tarc[i][j] = -1;
			}

		}
}

void bordare(int n, int m) {
	for (int i = 0; i <= n; i++)
		tarc[i][0] = tarc[i][m] = -1;

	for (int i = 0; i <= m; i++)
		tarc[0][i] = tarc[n][i] = -1;
}

void Lee(int i, int j) {
	Q.push({ i, j });

	while (!Q.empty()) {
		int x = Q.front().first,
			y = Q.front().second;

		Q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + di[k],
				ny = y + dj[k];
			if (tarc[nx][ny] == 0) {
				Q.push({nx, ny});
				tarc[nx][ny] = tarc[x][y] + 1;
			}
		}
	}
}

void short_meal() {
	for (int i = 0; i < indxm; i++) {
		int x = mancare[i].first,
			y = mancare[i].second;

		if (cnt_smin > tarc[x][y] && tarc[x][y] > 1) {
			cnt_manc = 1;
			cnt_smin = tarc[x][y];
		}
		else if (cnt_smin == tarc[x][y]) cnt_manc++;
	}
}

int main() {
	int c, n, m;
	fin >> c >> n >> m >> t;
	fin >> L >> C >> k >> s;

	while (t) {
		int tempi, tempj;
		fin >> tempi >> tempj;
		mancare[indxm] = { tempi, tempj };
		indxm++;
		t--;
	}

	citire(n, m);
	bordare(n + 1, m + 1);

	tarc[L][C] = 0;
	Lee(L, C);
	short_meal();

	if (c == 1) fout << cnt_cam;
	if (c == 2) fout << cnt_smin << " " << cnt_manc;

	return 0;
}
