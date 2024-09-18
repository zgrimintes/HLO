#include <iostream>

using namespace std;

void fillPattern(int is, int js, int ij, int jj, int n, int mat[1025][1025]) {
    for (int ii = is; ii < n; ii++)
        for (int jj = js; jj < n; jj++)
            mat[ii][jj] = 1;

    if (n == 1) return;

    bool ok == true;

    for (; is <= ij; is++)
        for (; js <= jj; js++)
            if (mat[is][js] == 0) ok = false;

    if (ok) return;

    fillPattern(0, n / 2 + 1, n - 1, mat);
    fillPattern(n / 2 + 1, 0, n - 1, mat);
    fillPattern(n / 2 + 1, n / 2 + 1, n - 1, mat);
}

int main()
{
    int mat[1025][1025];
    int n; cin >> n;
    fillPattern(0, 0, n - 1, mat);
    fillPattern(0, n / 2 + 1, n - 2, mat);
    fillPattern(n / 2 + 1, 0, n - 2, mat);
    fillPattern(n / 2 + 1, n / 2 + 1, n - 2, mat);
    return 0;
}
