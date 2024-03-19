/*DE INTREBAT DE CE NU MERGE
struct Matrix {
	long long mat[2][2];
	
	Matrix(long long mat[2][2]) : mat() {};

	Matrix() {
		mat[0][0] = mat[1][1] = 1;
		mat[1][0] = mat[0][1] = 0;
	};

	Matrix operator* (Matrix a) {
		Matrix M;
		M.mat[0][0] = ((a.mat[0][0] * this-> mat[0][0])MOD + (a.mat[0][1] * this-> mat[1][0])MOD)MOD;
		M.mat[0][1] = ((a.mat[0][0] * this-> mat[0][1])MOD + (a.mat[0][1] * this-> mat[1][1])MOD)MOD;
		M.mat[1][0] = ((a.mat[1][0] * this-> mat[0][0])MOD + (a.mat[1][1] * this-> mat[1][0])MOD)MOD;
		M.mat[1][1] = ((a.mat[1][0] * this-> mat[0][1])MOD + (a.mat[1][1] * this-> mat[1][1])MOD)MOD;

		return M;
	}
};

Matrix ridicare(Matrix m, int k) {
	Matrix ans;
	while (k) {

		if (k % 2 == 1)
			ans = ans * m;

		m = m * m;
		k /= 2;
	}

	return ans;
}

int nth_fib(int n) {
	if (!n) return 0;
	
	long long mat[2][2] = { 0, 1, 1, 1 };
	Matrix fib_matrix = ridicare(Matrix(mat), n--);

	return (fib_matrix.mat[0][0] + fib_matrix.mat[0][1])MOD;
}

int main() {
	int k;
	fin >> k;
	long long fib_k = nth_fib(k);
	fout << fib_k;

	return 0;
}
*/

//Rezolvare de 100 de puncte la prob kfib folosind structuri
#include <iostream>
#include <fstream>

using namespace std;
#define MOD %666013

ifstream fin("kfib.in");
ofstream fout("kfib.out");

struct Matrix {
	unsigned long long mat[2][2] = { 1, 0, 0, 1 };

	Matrix operator* (Matrix a) {
		Matrix M;
		M.mat[0][0] = ((a.mat[0][0] * this-> mat[0][0])MOD + (a.mat[0][1] * this-> mat[1][0])MOD)MOD;
		M.mat[0][1] = ((a.mat[0][0] * this-> mat[0][1])MOD + (a.mat[0][1] * this-> mat[1][1])MOD)MOD;
		M.mat[1][0] = ((a.mat[1][0] * this-> mat[0][0])MOD + (a.mat[1][1] * this-> mat[1][0])MOD)MOD;
		M.mat[1][1] = ((a.mat[1][0] * this-> mat[0][1])MOD + (a.mat[1][1] * this-> mat[1][1])MOD)MOD;

		return M;
	}
};

Matrix ridicare(Matrix m, int k) {
	Matrix ans;
	while (k) {

		if (k % 2 == 1)
			ans = ans * m;

		m = m * m;
		k /= 2;
	}

	return ans;
}

int main() {
	int k;
	fin >> k;
	Matrix A;
	A.mat[0][0] = 0; A.mat[0][1] = A.mat[1][0] = A.mat[1][1] = 1;
	A = ridicare(A, k);

	fout << A.mat[0][1]MOD;
	return 0;
}
