#include <iostream>
#include <fstream>
#include <cstring>
#include <queue>

using namespace std;

ifstream fin("concurs.in");
ofstream fout("concurs.out");

int dI[8] = {-1, 0, 1, 0, -1 , 1, 1, -1},
    dJ[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int matCost[55][55], matA[55][55], matB[55][55], n;
char finish[55], cuv[55];

pair <int, int> stop;
queue <pair <int, int>> Q;

bool inMat(int i, int j){
    if (i < 1 || i > n || j < 1 || j > n) return false;
    return true;
}

int toNumber(char *c){
    int nub = 0;
    for (int i = 0; c[i]; i++){
        if (c[i] >= '0' && c[i] <= '9')
            nub = nub * 10 + c[i] - '0';
    }

    return nub;
}

void citire(int n){
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++){
            fin >> cuv;
            if (strstr(cuv, finish))
                stop.first = i, stop.second = j;

            matCost[i][j] = toNumber(cuv);
        }
}

void lee(){
    matA[1][1] = 1;
    matB[1][1] = 1;

    while (!Q.empty()){
        int ic = Q.front().first,
            jc = Q.front().second;
        Q.pop();

        for (int i = 0; i < 8; i++) {
            int iv = ic + dI[i],
                jv = jc + dJ[i];

            if (!inMat(iv, jv)) continue;

            if (matA[iv][jv] == 0 || matA[iv][jv] > matA[ic][jc] + matCost[iv][jv]) {
                matA[iv][jv] = matA[ic][jc] + matCost[iv][jv];
                matB[iv][jv] = matB[ic][jc] + 1;

                Q.push({iv, jv});
            }
        }
    }
}

int main()
{
    Q.push( {1, 1} );
    fin >> n;
    fin.get();
    fin.getline(finish, 55);
    citire(n);
    lee();

    fout << matA[stop.first][stop.second] << " " << matB[stop.first][stop.second];
    return 0;
}
