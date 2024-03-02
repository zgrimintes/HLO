///20 PUNCTE - C1
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
int n, xs, ys, p, ds = -1;

void srchIntersection(int s) {
	for (int i = 0; i < s; i++)
		if (d[i].x == d[s].x && d[i].y == d[s].y)
			ds = i;
}

void stephs() {
	int step;
	int x = xs,
		y = ys;

	for (int i = 0; i <= p; i++) {
		d[i].x = x;
		d[i].y = y;

		if (mat[x][y] == 1) {
			srchIntersection(i);
			break;
		}
		mat[x][y] = 1;

		fin >> step;

		x += dI[step - 1]; y += dJ[step - 1];
	}

	fout << p - ds;
}

int main() {
	fin >> xs >> ys >> n >> p;
	stephs();
	return 0;
}
