///DFS pbinfo 100 p
#include <fstream>
#include <vector>
#include <algorithm>

const int NMAX = 100000;

using namespace std;

ifstream fin("dfs.in");
ofstream fout("dfs.out");

vector<int> G[NMAX + 1];
bool viz[NMAX + 1];

int n, m, s;

void citire() {
	for (int i = 1; i <= m; i++) {
		int x, y;
		fin >> x >> y;

		G[x].push_back(y);
		G[y].push_back(x);
	}

	for (int i = 1; i <= m; i++) {
		sort(G[i].begin(), G[i].end());
	}
}

void dfs(int nod) {
	if (viz[nod]) return;
	
	viz[nod] = 1;
	fout << nod << " ";

	for (auto varf : G[nod]) {
		dfs(varf);
	}
}

int main() {
	fin >> n >> m >> s;
	citire();

	dfs(s);

	return 0;
}
