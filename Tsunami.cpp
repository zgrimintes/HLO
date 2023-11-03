///REZOLVARE DE 80 DE PUNCTE
#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

queue< pair< int, int > > Q;
ifstream fin("tsunami.in");
ofstream fout("tsunami.out");
int arh[1005][1005];
int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };
int h;
int cnt_afc = 0;

void citire(int n, int m) {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            fin >> arh[i][j];
        }
}

void bordare(int n, int m) {
    for (int i = 0; i <= n + 1; i++)
        arh[i][0] = arh[i][m + 1] = 11;

    for (int i = 0; i <= m + 1; i++)
        arh[0][i] = arh[n + 1][i] = 11;
}

void fil(int i, int j) {
    if (arh[i][j] >= h) return;

    if (arh[i][j] != 0) { 
        cnt_afc++; 
        arh[i][j] = 100; 
    }
    else arh[i][j] = 11;

    for (int k = 0; k < 4; k++)
        fil(i + di[k], j + dj[k]);

}

int main()
{

    int n, m; fin >> n >> m >> h;
    citire(n, m);
    bordare(n, m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arh[i][j] == 0) fil(i, j);
        }
    }

    fout << cnt_afc;

    return 0;
}
