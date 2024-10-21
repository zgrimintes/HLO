#include <iostream>

using namespace std;

int a, b, c;
int n, m;
int MOD;

class Matrix
{
public:
	long long mat[3][3];

	Matrix(int a, int b, int c) {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				mat[i][j] = 0;

		mat[0][0] = a;
		mat[0][1] = b;
		mat[0][2] = c;
		mat[1][0] = 1;
		mat[2][2] = 1;
	}

	Matrix(int x) {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				mat[i][j] = 0;

		mat[0][0] = mat[1][1] = mat[2][2] = x;
	}

	Matrix operator * (Matrix m2) {
		Matrix result(a, b, c);

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				result.mat[i][j] = 0;

				for (int k = 0; k < 3; k++)
					result.mat[i][j] = result.mat[i][j] + (mat[i][k] * m2.mat[k][j] % MOD);
			}
		}

		return result;
	}
};

Matrix binary_pow(Matrix x) {
	Matrix rasp(1);
	n -= 2;

	while (n)
	{
		if (n % 2)
			rasp = rasp * x;

		x = x * x;
		n /= 2;
	}

	return rasp;
}

void solve() {
	Matrix knMat(a, b, c);
	Matrix powMat(a, b, c);

	knMat.mat[0][0] = 1;
	knMat.mat[1][0] = 1;
	knMat.mat[2][0] = 1;

	powMat = binary_pow(powMat);

	Matrix result = (powMat * knMat);

	cout << result.mat[0][0] % MOD;
}

int main() {
	cin >> a >> b >> c >> n >> m;

	MOD = m;

	solve();

	return 0;
}
