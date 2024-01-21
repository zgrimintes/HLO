#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

ifstream fin("livada.in");
ofstream fout("livada.out");

queue <pair <int, int>> Q;
stack <pair <int, int>> S;

pair <int, int> start;
pair <int, int> stop;
int livada[105][105];
int n, m;

int dI[8] = {-1, 0, 1, 0, -1, 1, 1, -1},
	dJ[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int atribuire (char *s){
	if (strstr(s, "mar") || strstr(s, "par") || strstr(s, "prun")) return 0;
	return -1;
}

void citire() {
	char pom[10];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			fin >> pom;
			livada[i][j] = atribuire(pom);
		}
	}
}

void bordare() {
	for (int i = 0; i <= m + 1; i++)
		livada[0][i] = livada[n + 1][i] = -1;

	for (int j = 0; j <= n + 1; j++)
		livada[j][0] = livada[j][m + 1] = -1;
}

void lee() {
	int is = start.first,
		ij = start.second;
	livada[is][ij] = 1;
	Q.push({ is, ij });

	while (!Q.empty()) {
		int ic = Q.front().first,
			jc = Q.front().second;

		Q.pop();

		for (int i = 0; i < 8; i++) {
			int iv = ic + dI[i],
				jv = jc + dJ[i];

			if (livada[iv][jv] == 0)
			{
				Q.push({ iv, jv });
				livada[iv][jv] = livada[ic][jc] + 1;
			}
		}
	}
}

void construireDrum() {
	S.push({ stop.first, stop.second });

	while (S.top() != make_pair(start.first, start.second)) {
		int ic = S.top().first,
			jc = S.top().second;

		for (int i = 0; i < 8; i++) {
			int iv = ic + dI[i],
				jv = jc + dJ[i];

			if (livada[iv][jv] == livada[ic][jc] - 1)
			{
				S.push({ iv, jv });
				break;
			}
		}
	}

	while (!S.empty()) {
		cout << "(" << S.top().first << "," << S.top().second << ")";
		S.pop();
	}
}

void construireDrumrec(int i, int j) {
	if (i == start.first && j == start.second) return;

	for (int k = 0; i < 8; i++) {
		int iv = i + dI[k],
			jv = j + dJ[k];

		if (livada[iv][jv] == livada[i][j] - 1) {
			construireDrumrec(iv, jv);
			cout << "(" << iv << "," << jv << ")";
			return;
		}
	}
}

int main() {
	fin >> n >> m >> start.first >> start.second >> stop.first >> stop.second;
	citire();
	bordare();

	lee();
	construireDrum();
	//construireDrumrec(stop.first, stop.second);

	return 0;
}
