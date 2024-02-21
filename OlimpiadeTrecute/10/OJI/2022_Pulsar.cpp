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
	dJ[5] = { 0, 1, 0, -1 };

queue <pair <int, int> > Q;
Pulsar p[15005];
int mat[505][505];
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
		mat[i][0] = mat[i][N + 1] = mat[0][i] = mat[N + 1][i] = -1;
}

void citire() {
	int cp = P - 1;
	fin >> p[ind_p].x >> p[ind_p].y >> p[ind_p].r >> p[ind_p].t;
	T = p[ind_p].r;
	ind_p++;

	if (cp > 0) {
		fin >> p[ind_p].x >> p[ind_p].y >> p[ind_p].r >> p[ind_p].t;
		T = cmmmc(p[ind_p - 1].r, p[ind_p].r);
		ind_p++;
	}


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
			if (mat[i][j] == 1) cnt_puls++;
			mat[i][j] = 0;
		}

}

int get_radius(int s) {
	int rez = 1, plus = 4;

	while (s) {
		rez = rez + plus;
		plus += 4;
		s--;
	}

	return rez;
}

void Lee_pulsar(int nrP, int i) {
	int rad = get_radius(i % p[nrP].r);

	Q.push({ p[nrP].x, p[nrP].y });
	mat[p[nrP].x][p[nrP].y] = 1;
	rad--;

	while (!Q.empty() && rad) {
		int x = Q.front().first,
			y = Q.front().second;

		Q.pop();
		rad--;
		mat[x][y] = 1;

		for (int k = 0; k < 4; k++) {
			int ni = x + dI[k],
				nj = y + dJ[k];

			if (mat[ni][nj] == 0 && mat[ni][nj] != -1) {
				Q.push({ ni, nj });
				
			}
		}
	}

}


int get_max_puls() {
	
	for (int i = 0; i < T; i++) {
		for (int j = 0; j < P; j++) {
			Lee_pulsar(j, i);
		}

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
