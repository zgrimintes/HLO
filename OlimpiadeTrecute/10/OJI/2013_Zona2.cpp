///DE TERMINAT
#include <fstream> 

using namespace std;

ifstream fin("zona2.in");
ofstream fout("zona2.out");

int dI[4] = { -1, 0, 1, 0 },
	dJ[4] = { 0, 1, 0, -1 };
int mat[55][55], mat_fin[55][55];
int n, xs, ys, p;

void stephs() {
	int step;
	int x = xs,
		y = ys;

	while (p) {
		mat[x][y] = 1;
		fin >> step;

		x += dI[step - 1]; y += dJ[step - 1];

		p--;
	}
}

int main() {
	fin >> xs >> ys >> n >> p;
	stephs();
	return 0;
}
