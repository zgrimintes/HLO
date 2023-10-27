#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

queue< pair< int, int > > Q;
ifstream fin("insule.in");
ofstream fout("insule.out");
int arh[105][105];
int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};
int pod_min = 1000000;
int insuleR = 0;
int insuleG = 0;
int insuleB = 0;
char c;

void citire(int n, int m){
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            fin >> c;
            arh[i][j] = (int)c - 48;
        }
}

void bordare(int n, int m) {
    for (int i = 0; i <= n + 1; i++)
        arh[i][0] = arh[i][m + 1] = -7;

    for (int i = 0; i <= m + 1; i++)
        arh[0][i] = arh[n + 1][i] = -7;
}

void fil(int i, int j, int v){
    if (arh[i][j] != v) return;

    arh[i][j] = 0 - v;

    for (int k = 0; k < 4; k++)
        fil(i+di[k], j+dj[k], v);

}

void nr_insule(int n, int m) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arh[i][j] == 1) {
                fil(i, j, 1);
                insuleR++;
            }
            if (arh[i][j] == 2) {
                fil(i, j, 2);
                insuleG++;
            }
            if (arh[i][j] == 3) {
                fil(i, j, 3);
                insuleB++;
            }
        }
    }
}

void start_pod(int n, int m) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arh[i][j] == -1) {
                for (int k = 0; k < 4; k++)
                    if (arh[i+di[k]][j+dj[k]] == 0) {
                        arh[i+di[k]][j+dj[k]] = 1;
                        Q.push(make_pair(i+di[k], j+dj[k]));
                    }
            }
        }
    }
}

void Lee() {
    while(!Q.empty()) {
        pair<int,int> pos = Q.front();

        for (int k = 0; k < 4; k++) {
            int ni = pos.first + di[k];
            int nj = pos.second + dj[k];

            if (arh[ni][nj] == 0) {
                Q.push(make_pair(ni, nj));
                arh[ni][nj] = arh[pos.first][pos.second] + 1;
            }
        }

        Q.pop();
    }
}

void find_pod(int n, int m) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arh[i][j] == -2) {
                for (int k = 0; k < 4; k++)
                    if (arh[i+di[k]][j+dj[k]] < pod_min && arh[i+di[k]][j+dj[k]] > 0) pod_min = arh[i+di[k]][j+dj[k]];
            }
        }
    }
}

int main()
{

    int n, m; fin >> n >> m;
    citire(n, m);
    bordare(n, m);
    nr_insule(n, m);
    start_pod(n, m);
    Lee();
    find_pod(n, m);

    fout << insuleR << " " << insuleG << " " << insuleB << " " << pod_min;

    return 0;
}
