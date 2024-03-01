///23 PUNCTE - C1
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
	for (int i = 1; i <= m; i++)
		indsI[i] = i;
	sort(indsI, indsI + m, cmpI);

	for (int i = 1; i <= n; i++)
		indsJ[i] = i;
	sort(indsJ, indsJ + n, cmpJ);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m;j++)
			nMat[i][j] = mat[indsI[i]][indsJ[j]];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m;j++)
			if (nMat[i][j] < nMat[i][j - 1] && nMat[i][j] > nMat[i - 1][j]) return false;

	return true;
}

void solve() {
	
			
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
