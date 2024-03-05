#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("sahara.in");
ofstream fout("sahara.out");

int sh[1005][1005];
int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};
int q, cnt_arie = 0, arie_max = 0;
int x1, x2, yy1, y2, q2;

void bordare(int n, int m) {
    for (int i = 0; i < n; i++)
        sh[i][0] = sh[i][m] = -1;

    for (int i = 0; i < m; i++)
        sh[0][i] = sh[n][i] = -1;
}

void uda() {
    sh[x1][yy1] += q2;
    sh[x1][y2 + 1] -= q2;
    sh[x2 + 1][yy1] -= q2;
    sh[x2 + 1][y2 + 1] += q2;
}

void fill(int i, int j) {
    if (sh[i][j] < q) return;

    cnt_arie++;
    sh[i][j] = -1;

    for (int k = 0; k < 4; k++)
        fill(i + di[k], j + dj[k]);
}

int main()
{
    int n, m, t;
    fin >> n >> m >> q >> t;

    while (t) {
        fin >> x1 >> yy1 >> x2 >> y2 >> q2;
        uda();
        t--;
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            sh[i][j] += sh[i - 1][j] + sh[i][j - 1] - sh[i - 1][j - 1];
    
    bordare(n + 1, m + 1);
            
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (sh[i][j] >= q) fill(i, j);
            if (arie_max < cnt_arie) arie_max = cnt_arie;
            cnt_arie = 0;
        }

    fout << arie_max;

    return 0;
}
