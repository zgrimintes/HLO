#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("matrice_div_et_imp.in");
ofstream fout("matrice_div_et_imp.out");

int mat[1005][1005];

void div_et_imp(int is, int js, int l) {
    if (l == 1) {
        fout << mat[is][js] << " ";
        return;
    }

    div_et_imp(is, js, l / 2);
    div_et_imp(is + l / 2, js + l / 2 , l / 2);
    div_et_imp(is, js + l / 2, l / 2);
    div_et_imp(is + l / 2, js, l / 2);
}

void citire(int l) {
    for (int i = 1; i <= l; i++)
        for (int j = 1; j <= l; j++)
            fin >> mat[i][j];
}

int main()
{
    int n; fin >> n;
    int l = 1;
    while (n) l *= 2, n--;

    citire(l);

    div_et_imp(1, 1, l);
    return 0;
}
