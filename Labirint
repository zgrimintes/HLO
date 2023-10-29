///Rezolvare de 60 de puncte 
#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("labirint.in");
ofstream fout("labirint.out");

int lab[1005][1005];
int clab[1005][1005];
int di[4] = { -1, 0, 1, 0};
int dj[4] = { 0, 1, 0, -1};
int rez_min = 100001;

void copy_lab(int n) {
	for (int i = 0; i <= n + 1; i++)
		for (int j = 0; j <= n + 1; j++)
			clab[i][j] = lab[i][j];
}

void citire(int n) {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			fin >> lab[i][j];
			if (lab[i][j] < rez_min) rez_min = lab[i][j];
		}
}

void bordare(int n) {
	for (int i = 0; i <= n + 1; i++)
		lab[0][i] = lab[n + 1][i] = lab[i][0] = lab[i][n + 1] = -1;
}

void fill(int i, int j) {
	if (clab[i][j] > rez_min || clab[i][j] == -1) return;

	clab[i][j] = -1;
	
	for (int k = 0; k < 4; k++) {
		fill(i + di[k], j + dj[k]);
	}
}

int main() {
	int n; fin >> n;
	citire(n);
	bordare(n);
	copy_lab(n);

	while (clab[1][1] != -1) {
		fill(n, n);
		if (clab[1][1] != -1) {
			rez_min++;
			copy_lab(n);
		}
	}

	fout << rez_min;

	return 0;
}

///Rezolvare de 100 de puncte
#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

ifstream fin("labirint.in");
ofstream fout("labirint.out");

queue<pair<int, int>> Q;
int lab[1005][1005];
int clab[1005][1005];
int di[4] = { -1, 0, 1, 0};
int dj[4] = { 0, 1, 0, -1};
int rez_min = 100001;

void reset(int n) { ///copy_lab(int n)
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			clab[i][j] = 0;
}

void citire(int n) {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			fin >> lab[i][j];
			if (lab[i][j] < rez_min) rez_min = lab[i][j];
		}
}

void bordare(int n) {
	for (int i = 0; i <= n + 1; i++)
		clab[0][i] = clab[n + 1][i] = clab[i][0] = clab[i][n + 1] = -1;
}

/*void fill(int i, int j) {
	if (clab[i][j] > rez_min || clab[i][j] == -1) return;

	clab[i][j] = -1;
	
	for (int k = 0; k < 4; k++) {
		fill(i + di[k], j + dj[k]);
	}
}*/

int Lee( int n, int rez_min) {
	if (lab[1][1] > rez_min) return 0;
	reset(n);

	Q.push(make_pair(1, 1));
	clab[1][1] = 1;

	while (!Q.empty()) {
		pair<int, int> p = Q.front();
		Q.pop();

		for (int k = 0; k < 4; k++) {
			int ni = p.first + di[k];
			int nj = p.second + dj[k];

			if (clab[ni][nj] == 0 && lab[ni][nj] <= rez_min) {
				Q.push(make_pair(ni, nj ));

				clab[ni][nj] = clab[p.first][p.second] + 1;
			}
		}
	}

	return clab[n][n];
}

void cautarebin(int st, int dr, int n) {

	while (st <= dr) {
		int mj = (st + dr) / 2;
		if (Lee(n, mj)) dr = mj - 1;
		else st = mj + 1;
	}

	fout << st;
}

int main() {
	int n; fin >> n;
	citire(n);
	bordare(n);
	cautarebin(1, 100001, n);

	return 0;
}
/**
In aceasta rezovare am renuntat la a cauta valoarea minima incercand fiecare posibilitate(evident e ineficient), astefl am inceput cautand binar rezistenta minima.
Am facut asta trecand pritr-o copie a matriciei org cu algoritmul lee verificand daca aceasta poate ajunge la final verificand si rezistenta cu mat org.
La final am returnat valoarea din cautarea binara, aceasta fiind cea mai mica rezistenta cu care se poate trece labirintul.
*/
