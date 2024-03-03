///100 DE PUNCTE
#include <fstream> 

using namespace std;

ifstream fin("zona2.in");
ofstream fout("zona2.out");

struct Drum {
	int x, y;
};

Drum d[5000];
int dI[4] = { -1, 0, 1, 0 },
    dJ[4] = { 0, 1, 0, -1 };
int mat[55][55], mat_fin[55][55];
int n, xs, ys, p, ds = -1, cnt_pat;
bool inside = true;

void srchIntersection(int s) {
	for (int i = 0; i < s; i++)
		if (d[i].x == d[s].x && d[i].y == d[s].y)
			ds = i;
}

void fill(int i, int j) {
	if (i < 0 || i > n + 1 || j < 0 || j > n + 1) return;
	if (mat[i][j] == 1) return;
	if (mat[i][j] == -1) {
		inside = false;
		return;
	}

	cnt_pat++;
	mat[i][j] = 1;

	if ((mat_fin[i][j] & 1) == 0) fill(i - 1, j);
	if (((mat_fin[i][j] >> 1) & 1) == 0) fill(i, j + 1);
	if (((mat_fin[i][j] >> 2) & 1) == 0) fill(i + 1, j);
	if (((mat_fin[i][j] >> 3) & 1) == 0) fill(i, j - 1);
}

void moveDir(int dir, int &x, int &y) {
	x += dI[dir - 1]; y += dJ[dir - 1];
	
	switch (dir)
	{
	case 1:
		mat_fin[x + 1][y] += 2;
		mat_fin[x + 1][y + 1] += 8;
		break;
	case 2:
		mat_fin[x][y] += 4;
		mat_fin[x + 1][y] += 1;
		break;
	case 3:
		mat_fin[x][y] += 2;
		mat_fin[x][y + 1] += 8;
		break;
	case 4: 
		mat_fin[x][y + 1] += 4;
		mat_fin[x + 1][y + 1] += 1;
		break;
	}
}

void bordare_reset() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			mat[i][j] = 0;

	for (int i = 0; i <= n + 1; i++)
		mat[i][0] = mat[i][n + 1] = mat[0][i] = mat[n + 1][i] = -1;
}

void steps() {
	int step;
	int x = xs,
		y = ys;

	for (int i = 0; i <= p; i++) {
		d[i].x = x;
		d[i].y = y;

		if (mat[x][y] == 1) {
			///In cazul in care am mai trecut prin intersectia actuala, caut exact a cata intersectie 
			///este de la inceputul drumului, apoi determin lungimea traseului care formeaza zona inchisa.
			srchIntersection(i);
			break;
		}
		mat[x][y] = 1;

		fin >> step;

		moveDir(step, x, y);
	}

	fout << p - ds << "\n";

	bordare_reset(); ///Reutilizez matricea pentru fill
}

int main() {
	fin >> xs >> ys >> n >> p;
	steps();
	
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			///Caut primul colt format si incep fill-ul.
			///Aici apar doua cazuri:
			///1. Cand restul traseului (de la inceput pana la intersectia comuna) este in interiorul zonei delimitate.
			///2. Cand restul traseului este in afara zonei delimitate.
			///Astfel pentru primul caz o sa afisez numarul de patrate la care am dat fill, iar pentru al doilea,
			///numarul total de patrate minus cele umplute.
			if (((mat[i][j] & 1) == 0) && (((mat[i][j] >> 3) & 1) == 0)) { 
				fill(i, j);

				if (inside) fout << cnt_pat;
				else fout << n * n - cnt_pat;

				return 0;
			}

	return 0;
}
