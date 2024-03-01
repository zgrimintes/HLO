///100 DE PUNCTE
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("yingyang.in");
ofstream fout("yingyang.out");

int n, m;
int mat[105][105], nMat[105][105];
int indsI[105], indsJ[105];
int cnt_swaps;

void citire() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			fin >> mat[i][j];
}

bool cmpI(int a, int b) {
	for (int i = 1; i <= n; i++) {
		if (mat[a][i] == mat[b][i]) continue;

		return mat[a][i] < mat[b][i];
	}

	return a < b;
}

bool cmpJ(int a, int b) {
	for (int i = 1; i <= m; i++) {
		if (mat[i][a] == mat[i][b]) continue;

		return mat[i][a] < mat[i][b];
	}

	return a < b;
}

bool verif() {
	for (int i = 1; i <= n; i++)
		indsI[i] = i;
	sort(indsI + 1, indsI + n + 1, cmpI);

	for (int i = 1; i <= m; i++)
		indsJ[i] = i;
	sort(indsJ + 1, indsJ + m + 1, cmpJ);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m;j++)
			nMat[i][j] = mat[indsI[i]][indsJ[j]];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m;j++)
			if (nMat[i][j] < nMat[i][j - 1] || nMat[i][j] < nMat[i - 1][j]) return false;

	return true;
}

void solve() {
	for (int i = 2; i <= n; i++)
		for (int j = 1; j < i; j++)
			cnt_swaps += (indsI[i] < indsI[j]);

	for (int i = 2; i <= m; i++)
		for (int j = 1; j < i; j++)
			cnt_swaps += (indsJ[i] < indsJ[j]);
}

int main() {
	fin >> n >> m;
	citire();

	if (!verif()) {
		fout << -1;
		return 0;
	}

	solve();
	fout << cnt_swaps;

	return 0;
}
