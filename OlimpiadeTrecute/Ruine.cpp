///DE TERMINAT C1(PARTIAL) SI C2
#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

ifstream fin("ruine.in");
ofstream fout("ruine.out");

queue < pair <int, int> > Q;

pair <int, int> P[300];
int harta[105][105];
int cam[105][105];
int cnt_rooms = 0;
int n, m, p, c;

void citire(){
    int i, j;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++){
            fin >> harta[i][j];
            cam[i][j] = harta[i][j] ;
        }
}

void bordare(){
    for (int i = 0; i <= m + 1; i++)
        harta[i][0] = harta[i][n + 1] = -1;

    for (int i = 0; i <= n + 1; i++)
        harta[0][i] = harta[n + 1][i] = -1;
}

bool isCorner(int n){
    if (n < 0) return 0;

    if (n & 1 && (n >> 3) & 1)
        return true;

    return false;
}

void fillRoom(int i, int j ) {
    if (i < 1 || i > n  || j < 1 || j > m) {
        cnt_rooms--;
        return;
    }

    if (cam[i][j] < 0) return;

    int nr = cam[i][j];

    cam[i][j] = -1;

    if ((nr & 1) == 0)
        fillRoom(i - 1, j);

    if (((nr >> 1) & 1) == 0)
        fillRoom(i, j + 1);

    if (((nr >> 2) & 1) == 0)
        fillRoom(i + 1, j);

    if (((nr >> 3 )& 1) == 0)
        fillRoom(i, j - 1);
}

int camere(int i, int j){
    for (int i = 1; i <= n; i++){
        if (i == 3)
            cout << "";
        for (int j = 1; j <= m; j++)
            if (isCorner(cam[i][j])){
                fillRoom(i, j);
                cnt_rooms++;
            }
    }

    return cnt_rooms;
}

int main()
{
    fin >> n >> m >> p >> c;
    citire();
    bordare();
    if (c == 1)
        fout << camere(1, 1);

    return 0;
}
