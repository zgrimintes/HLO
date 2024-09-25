#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("matrice_div_et_imp.in");
ofstream fout("matrice_div_et_imp.out");

int mat[1005][1005];

void div_et_imp(int is, int js, int ij, int jj, int l) {
    if (is == ij) {
        fout << mat[is][js];
        return;
    }

    div_et_imp(0, 0, l / 2, l / 2, l);
    div_et_imp(l / 2 + 1, l / 2 + 1, l, l, l / 2);
    div_et_imp(0, l / 2 + 1, l / 2, l, l / 2);
    div_et_imp(l / 2 + 1, 0, l / 2, l, l / 2);
}

int main()
{
    int n; fin >> n;
    int l = 1;
    while (n) l *= 2, n--;

    div_et_imp(0, 0, l / 2, l / 2, l);
    return 0;
}
