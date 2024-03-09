#include <fstream>
#include <deque>
#include <functional>

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

void citire() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            fin >> mat[i][j];
}

void calc(deque <int> &D, function<bool(int x, int y)> cmp, int i, int j) {
    if (!D.empty()) {
        if (D.front() + dx <= j) {
            ind_s++;
            D.pop_front();
        }

        while (!D.empty() && cmp(mat[i][j], mat[i][D.back()]))
            D.pop_back();

        D.push_back(j);
    }
    else D.push_back(j);
}

void emptyDeque(deque <int>& D) {
    while (!D.empty()) D.pop_back();
}

void calcMinMax() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            if (j >= dx && !Dm.empty())
                minim[i][ind_s] = Dm.front();

            if (j >= dx && !DM.empty())
                maxim[i][ind_s] = DM.front();

            calc(Dm, [](int x, int y) { return x < y;}, i, j);
            calc(DM, [](int x, int y) { return x > y;}, i, j);

        }
        ind_s = 0;
        emptyDeque(Dm);
        emptyDeque(DM);
    }
}

void solve() {
    while (p) {
        fin >> dx >> dy;
        calcMinMax();
        p--;
    }
}

int main() {
    fin >> n >> m >> p;
    citire();
    solve();
    return 0;
}
