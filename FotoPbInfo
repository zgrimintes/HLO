#include <iostream>
#include <fstream>

//using namespace std;
using std::ifstream;
using std::ofstream;

ifstream fin("foto.in");
ofstream fout("foto.out");
int poza[100][100];
int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};
int lum_max = 0, cnt_lum = 0;

void citire(int n, int m){
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            fin >> poza[i][j];
}

void bordare(int n, int m) {
    for (int i = 0; i <= n + 1; i++)
        poza[i][0] = poza[i][m + 1] = -1;

    for (int i = 0; i <= m + 1; i++)
        poza[0][i] = poza[n + 1][i] = -1;
}

void fil(int i, int j){
    if (poza[i][j] != 0) return;

    cnt_lum++;
    poza[i][j] = -1;

    for (int k = 0; k < 4; k++)
        fil(i+di[k], j+dj[k]);

}

int main()
{

    int n, m; fin >> n >> m;
    citire(n, m);
    bordare(n, m);

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cnt_lum = 0;
            if (poza[i][j] == 0) fil(i, j);

            if (cnt_lum > lum_max) lum_max = cnt_lum;
        }
    }

    fout << lum_max;

    return 0;
}
