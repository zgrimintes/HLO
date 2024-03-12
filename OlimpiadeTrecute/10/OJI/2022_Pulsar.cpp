///100 PUNCTE
#include <fstream> 
#include <queue>

using namespace std;

ifstream fin("pulsar.in");
ofstream fout("pulsar.out");

struct Pulsar
{
	int x, y, r, t;
};

int dI[5] = { -1, 0, 1, 0, 0 },
dJ[5] = { 0, 1, 0, -1, 0 };

queue <pair <int, int> > Q;
queue < int > T_Q;
Pulsar p[15005];
int mat[61][505][505];
int mat_verif[505][505];
int C, N, P;
int xs, ys, xf, yf;
int ind_p;
int T, t_act;
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
		for (int j = 0; j < 60; j++)mat[j][i][0] = mat[j][i][N + 1] = mat[j][0][i] = mat[j][N + 1][i]= -1;
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

void reset_mat(int t) {
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			if (mat[t][i][j] == -2) cnt_puls++;
			///mat[i][j][t] = 0;
			mat_verif[i][j] = -1;
		}

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

		mat[t][x][y] = -2;
		mat_verif[x][y] = nrP;

		for (int k = 0; k < 4; k++) {
			int ni = x + dI[k],
				nj = y + dJ[k];

			if (mat_verif[ni][nj] != nrP && mat[t][ni][nj] != -1)
				Q.push({ ni, nj });
		}
	}
}


void get_max_puls() {
	reset_mat(0);

	for (int i = 0; i < T; i++) {
		for (int j = 0; j < P; j++) { Lee_pulsar(j, (i + p[j].t) % p[j].r, i); }

		reset_mat(i);

		if (cnt_puls > max_puls) max_puls = cnt_puls;

		cnt_puls = 0;
	}
}

void Lee3D() {
	t_act = 0;
	T_Q.push(t_act);
	Q.push({ xs, ys });

	while (!Q.empty()) {
		t_act = T_Q.front();
		int x = Q.front().first,
			y = Q.front().second;

		Q.pop(); T_Q.pop();

		//if (mat[x][y][t_act] <= -1) continue;
		//mat[x][y][t_act] = 1;

		for (int k = 0; k < 5; k++) {
			int ni = x + dI[k],
				nj = y + dJ[k];
			int t_next = (t_act + 1) % T;

			if (mat[t_next][ni][nj] == 0) {
				Q.push({ ni, nj });
				T_Q.push(t_next);
				mat[t_next][ni][nj] = mat[t_act][x][y] + 1;
			}
		}
	}
}

int min_reach() {
	int min_r = 10000001;
	for (int i = 0; i < T; i++)
		if (mat[i][xf][yf] < min_r && mat[i][xf][yf] > 0)
			min_r = mat[i][xf][yf];

	return min_r;
}

int main() {
	fin >> C >> N >> P;
	citire();

	get_max_puls();

	if (C == 1) {
		fout << max_puls;
	}
	else {
		Lee3D();
		fout << min_reach();
	}

	return 0;
}
