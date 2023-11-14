///REZOLVARE DE 100 DE PUNCTE
#include <iostream>
#include <fstream>
#define MOD %666013

using namespace std;

ifstream fin("recurenta2.in");
ofstream fout("recurenta2.out");

struct Matrix {
	unsigned long long mat[7][7] = { 0, 0 };

	Matrix(int n) {
		for (int i = 0; i < 7; i++)
			for (int j = 0; j < 7; j++)
				if (i == j) mat[i][i] = n;
				else mat[i][j] = 0;
	}

	Matrix() {
		for (int i = 0; i < 7; i++)
			for (int j = 0; j < 7; j++)
				mat[i][j] = 0;
	}

	Matrix(int x1, int x2, int s, int nr) {
		mat[0][0] = x1;
		mat[1][0] = x2;
		mat[2][0] = s;
		mat[3][0] = 3 * x1;
		mat[4][0] = 3 * x2;
		mat[5][0] = nr;
		mat[6][0] = 1;

		for (int i = 0; i < 7; i++)
			for (int j = 1; j < 7; j++)
				mat[i][j] = 0;
	}

	Matrix(int a, int b, int c) {
		for (int i = 0; i < 7; i++)
			for (int j =0; j < 7; j++)
				mat[i][j] = 0;


		mat[0][1] = mat[2][2] = mat[3][1] = mat[3][4] = mat[5][5] = mat[5][6] = mat[6][6] = 1;
		mat[1][1] = mat[2][4] = mat[4][1] = mat[4][4] = a;
		mat[1][0] = mat[2][3] = mat[4][0] = mat[4][3] = b;
		mat[1][6] = mat[2][5] = mat[4][5] = mat[4][6] = c;
	}

	Matrix operator*(Matrix A) {
		Matrix new_mat;

		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 7; j++) {

				for (int k = 0; k < 7; k++) {
					new_mat.mat[i][j] = (new_mat.mat[i][j] + (mat[i][k] * A.mat[k][j])MOD)MOD;
				}
			}
		}

		return new_mat;
	}

};

Matrix to_power(int n, Matrix base) {

	Matrix ans(1);

	while (n) {
		if (n % 2 == 1)
			ans = ans * base;
		
		base = base * base;
		n /= 2;
	}

	return ans;
}

int get_sum(Matrix a, Matrix b, int n, int s2) {
	if (n == 2) return s2;

	Matrix x = to_power(n - 2, b);
	a = x * a;

	return a.mat[2][0];
}

int main() {
	int x1, x2, a, b, c, n;
	fin >> a >> b >> c >> x1 >> x2 >> n;
	Matrix A(x1, x2, x1 + 2 * x2, 3);
	Matrix B(a, b, c);

	fout << get_sum(A, B, n, x1 + 2 * x2);

	return 0;
}
