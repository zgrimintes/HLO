#include <iostream>
#include <fstream>
#define MOD %666013

using namespace std;

ifstream fin("iepuri.in");
ofstream fout("iepuri.out");

struct Matrix {
    long long mat[3][3];

    Matrix(int z1, int z2, int z3) {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                mat[i][j] = 0;

        mat[0][0] = z1;
        mat[1][0] = z2;
        mat[2][0] = z3;
    }

    Matrix(int a, int b, int c, int n) {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                mat[i][j] = 0;

        mat[0][1] = mat[1][2] = n;
        mat[2][0] = c;
        mat[2][1] = b;
        mat[2][2] = a;
    }

    Matrix(int n) {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (i != j) mat[i][j] = 0;
                else mat[i][j] = n;
    }        

    Matrix operator* (Matrix other) {
        Matrix new_mat(0);

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {

                for (int k = 0; k < 3; k++) {
                    new_mat.mat[i][j] = (new_mat.mat[i][j] + (this->mat[i][k] * other.mat[k][j])MOD)MOD;
                }
            }
        }

        return new_mat;
    }
};

Matrix ridicare(int n, Matrix base) {
    Matrix ans(1);

    while (n) {
        if (n % 2 == 1)
            ans = ans * base;

        base = base * base;
        n /= 2;
    }

    return ans;
}

int get_rabbits(int n, Matrix A, Matrix B) {
    
    A = ridicare(n - 2, B) * A;

    return A.mat[2][0]MOD;
}

int main()
{
    int t, x, y, z, a, b, c, n;
    fin >> t >> x >> y >> z >> a >> b >> c >> n;

    while (t) {
        Matrix A(x, y, z);
        Matrix B(a, b, c, 1);

        fout << get_rabbits(n, A, B) << "\n";

        fin >> x >> y >> z >> a >> b >> c >> n;
        t--;
    }

    return 0;
}
