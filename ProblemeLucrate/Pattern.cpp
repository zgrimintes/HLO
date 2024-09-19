#include <iostream>

using namespace std;

int mat[1025][1025];

void fillPattern(int is, int js, int l) {
    for (int it = is; it - is < l / 2; it++)
        for (int jt = js; jt - js < l / 2; jt++)
            mat[it][jt] = 1;

    if (l < 1) return;

    fillPattern(is, js + l / 2, l / 2);
    fillPattern(is + l / 2, js, l / 2);
    fillPattern(is + l / 2, js + l / 2, l / 2);
}

void afisare( int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << mat[i][j] << " ";

        cout << "\n";
    }
}

int main()
{
    int mat[1025][1025];
    int n; cin >> n;
    int l = n;
    int temp = 1;
    while (l) temp *= 2, l--;

    l = temp;

    fillPattern(0, 0, l);

    afisare(l);
    return 0;
}
