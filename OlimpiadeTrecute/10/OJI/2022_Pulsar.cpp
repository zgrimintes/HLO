///19 PUNCTE - C1
#include <fstream> 
#include <queue>

using namespace std;

ifstream fin("pulsar.in");
ofstream fout("pulsar.out");

struct Pulsar
{
	int x, y, r, t;
};

int dI[4] = { -1, 0, 1, 0 },
dJ[4] = { 0, 1, 0, -1 };

queue <pair <int, int> > Q;
Pulsar p[15005];
int mat[505][505][61];
int mat_verif[505][505];
int C, N, P;
int xs, ys, xf, yf;
int ind_p;
int T;
int max_puls, cnt_puls;

int cmmdc(int a, int b) {
	int r = 0;
	while (b) {
		r = a % b;
		a = b;
		b = r;
	}

	return a;
}

int cmmmc(int a, int b) {
	return a * b / cmmdc(a, b);
}

void bordare() {
	for (int i = 0; i <= N + 1; i++)
		for (int j = 0; j < 60; j++)
		mat[i][0][j] = mat[i][N + 1][j] = mat[0][i][j] = mat[N + 1][i][j] = -1;
}

void citire() {
	int cp = P - 1;
	fin >> p[ind_p].x >> p[ind_p].y >> p[ind_p].r >> p[ind_p].t;
	T = p[ind_p].r;
	ind_p++;

	while (cp) {
		fin >> p[ind_p].x >> p[ind_p].y >> p[ind_p].r >> p[ind_p].t;

		T = cmmmc(T, p[ind_p].r);
		ind_p++;
		cp--;
	}

	fin >> xs >> ys >> xf >> yf;

	bordare();
}

void reset_mat() {
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			for (int t = 0; t < 60; t++) {
				if (mat[i][j][t] == 1) cnt_puls++;
				mat[i][j][t] = 0;
				mat_verif[i][j] = -1;
			}
		}

}
void resetVerif() {
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			mat_verif[i][j] = 0;
}

void Lee_pulsar(int nrP, int i, int t) {
	int xs = p[nrP].x,
		ys = p[nrP].y;

	Q.push({ p[nrP].x, p[nrP].y });

	while (!Q.empty()) {
		int x = Q.front().first,
			y = Q.front().second;

		Q.pop();
		if (abs(xs - x) + abs(ys - y) > i) continue;

		mat[x][y][t] = 1;
		mat_verif[x][y] = nrP;

		for (int k = 0; k < 4; k++) {
			int ni = x + dI[k],
				nj = y + dJ[k];

			if (mat_verif[ni][nj] != nrP && mat[ni][nj][t] != -1)
				Q.push({ ni, nj });
		}
	}
}


int get_max_puls() {
	reset_mat();

	for (int i = 0; i < T; i++) {
		for (int j = 0; j < P; j++) { Lee_pulsar(j, (i + p[j].t) % p[j].r, i); }

		reset_mat();

		if (cnt_puls > max_puls) max_puls = cnt_puls;

		cnt_puls = 0;
	}

	return max_puls;
}

int main() {
	fin >> C >> N >> P;
	citire();

	if (C == 1) {
		fout << get_max_puls();
	}
	else {

	}

	return 0;
}
