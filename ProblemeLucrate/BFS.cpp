///BFS pbinfo 100 p
#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>

const int NMAX = 100000;

using namespace std;

ifstream fin("BFS.in");
ofstream fout("BFS.out");

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

void bfs() {
	queue<int> Q;
	vector<int> dist(n + 1, -1);
	dist[s] = 0;
	Q.push(s);

	while (!Q.empty()) {
		int nod = Q.front();
		fout << nod << " ";
		Q.pop();

		for (auto vecin : G[nod]) {
			if (dist[vecin] == -1) {
				Q.push(vecin);
				dist[vecin] = dist[nod] + 1;
			}
		}
	}
}

int main() {
	fin >> n >> m >> s;
	citire();

	bfs();
	return 0;
}
