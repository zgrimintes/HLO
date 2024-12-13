///BFS pe un graf orientat

#include <fstream>
#include <queue>
#include <vector>

const int NMAX = 100000;

using namespace std;

ifstream fin("bfs.in");
ofstream fout("bfs.out");

vector<int> G[NMAX + 1];
bool viz[NMAX + 1];

int n, m, s;

void citire() {
	for (int i = 1; i <= m; i++) {
		int x, y;
		fin >> x >> y;

		G[x].push_back(y);
		//G[y].push_back(x);
	}
}

void bfs() {
	queue<int> Q;
	vector<int> dist(n + 1, -1);
	dist[s] = 0;
	Q.push(s);

	while (!Q.empty()) {
		int nod = Q.front();
		Q.pop();

		for (auto vecin : G[nod]) {
			if (dist[vecin] == -1) {
				Q.push(vecin);
				dist[vecin] = dist[nod] + 1;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		fout << dist[i] << " ";
	}
}

int main() {
	fin >> n >> m >> s;
	citire();

	bfs();
	return 0;
}
