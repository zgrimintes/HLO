//DE TERMINAT
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("ciupercute.in");
ofstream fout("ciupercute.out");

int grad[105][105], viz[105][105], timp = 99999, inapoi;
int n, m, k;

const int dI[4] = {1, 0, -1, 0},
          dJ[4] = {0, 1, 0, -1};

void bordare(){
    for (int i = 0; i <= m + 1; i++)
        grad[0][i] = grad[n + 1][i] = viz[0][i] = viz[n + 1][i] = -1;

    for (int j = 0; j <= n + 1; j++)
        grad[j][0] = grad[j][m + 1] = viz[j][0] = viz[j][m + 1] = -1;
}

int getNb(char *s){
    int nb = 0;

    for (int i = 0; s[i]; i++) {
        nb = nb * 10 + s[i] - '0';
    }

    return nb;
}

void citire(){
    fin >> n >> m >> k;
    fin.get();
    char rand[455];

    for (int i = 1; i <= n; i++) {
        fin.getline(rand, 455);
        char *p = strtok(rand, " ");
        int j = 1;

        while (p){
            if (p[0] == 'C')
                grad[i][j] = viz[i][j] = -1;
            else if (p[0] >= '0' && p[0] <= '9')
                grad[i][j] = getNb(p);
            j++;
            p = strtok(NULL, " ");
        }
    }

    bordare();
}

void backtrack(int i, int j, int t, int c) {
    if (c > k) return;

    if (c == k && i == 1 && j == 1 && t != 0)
        timp = min(t, timp);

    viz[i][j] = 1;

    int ciup = 0;
    if (viz[i][j] != 0)
        ciup = 1;

    for (int k = 0; k < 4; k++) {
        int vi = i + dI[k],
            vj = j + dJ[k];

        if (viz[vi][vj] == 0)
            backtrack(vi, vj, grad[i][j] + 1 + t, c + ciup);
        else {
            if (vi == 1 && vj == 1 && inapoi == 0) {
                inapoi = 1;
                backtrack(vi, vj, grad[i][j] + 1 + t, c + ciup);
                inapoi = 0;
            }
        }
    }

    viz[i][j] = 0;
}

int main()
{
    citire();
    backtrack(1, 1, 0, 0);

    if (timp == 99999) fout << -1;
    else fout << timp;

    return 0;
}
