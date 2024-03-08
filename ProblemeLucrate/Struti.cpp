///DE TERMINAT!!!
#include <fstream>
#include <deque>

using namespace std;

ifstream fin("struti.in");
ofstream fout("struti.out");

deque <int> Dm, DM;
int n, m, p;
int mat[1005][1005];
int minim[1005][1005];
int maxim[1005][1005];
int dx, dy;
int ind_s;

void citire(){
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j++)
            fin >> mat[i][j];
}

void calc(deque D, bool m, int i, int j){
    if (!D.empty()) {
        if (D.front() + dx <= j) {
            ind_s++;
            Dm.pop_front();
        }

        while (!D.empty() && (m) ? (mat[i][j] < mat[i][D.back()]) : (mat[i][j] > mat[i][D.back()]))
            D.pop_back();

        D.push_back(j);
    }
    else D.push_back(j);
}

void calcMinMax(){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++){
            if (j >= dx && !Dm.empty())
                minim[i][ind_s] = Dm.front();

            if (j >= dx && !DM.empty())
                maxim[i][ind_s] = DM.front();

            calc(Dm, 1, i, j);
            calc(DM, 0, i, j);

        }

    }
}

void solve(){
    while (p){
        fin >> dx >> dy;
        calcMinMax();
        p--;
    }
}

int main(){
    fin >> n >> m >> p;
    citire();
    solve();
    return 0;
}
