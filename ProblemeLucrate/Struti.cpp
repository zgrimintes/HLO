///REZOLVARE DE 80 PUNCTE
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
int ind_m, ind_M;
int min_loc, cnt_min, cnt_col;

void citire() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            fin >> mat[i][j];
}

void calc(deque <int> &D, function<bool(int x, int y)> cmp, int i, int j, int d) {
    if (!D.empty()) {
        if (D.front() + d <= j) {
            D.pop_front();
        }

        while (!D.empty() && cmp(mat[i][j], mat[i][D.back()]))
            D.pop_back();
    }

    D.push_back(j);
}

void calcTot(deque <int>& D, function<bool(int x, int y)> cmp, int i, int j, int m[][1005], int d) {
    if (!D.empty()) {
        if (D.front() + d <= j) {
            D.pop_front();
        }

        while (!D.empty() && cmp(mat[j][m[j][i]], mat[D.back()][m[D.back()][i]]))
            D.pop_back();
    }

    D.push_back(j);
}

void emptyDeque(deque <int>& D) {
    while (!D.empty()) D.pop_back();
}

void calcMinMax(int d) {
    ind_m = 0;
    ind_M = 0;
    emptyDeque(Dm);
    emptyDeque(DM);
    
    for (int i = 0; i < n; i++) {
        cnt_col = 0;

        for (int j = 0; j <= m; j++) {
            if (j >= d && !Dm.empty())
                minim[i][ind_m++] = Dm.front(), cnt_col++;

            if (j >= d && !DM.empty())
                maxim[i][ind_M++] = DM.front();

            calc(Dm, [](int x, int y) { return x < y;}, i, j, d);
            calc(DM, [](int x, int y) { return x > y;}, i, j, d);

        }
        ind_m = 0;
        ind_M = 0;
        emptyDeque(Dm);
        emptyDeque(DM);
    }
}

void getBarDif(int M, int m) {
    if (M - n < 0) return;

    if ((M - m) < min_loc) {
        min_loc = M - m;
        cnt_min = 1;
    }
    else if ((M - m) == min_loc) cnt_min++;
}

void calcMinMaxTot(int d, int m) {
    int minT = 10000, maxT = -1;
    ind_m = 0;
    ind_M = 0;
    emptyDeque(Dm);
    emptyDeque(DM);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j <= n; j++) {
            if (j >= d && !Dm.empty()) {
                minT = mat[Dm.front()][minim[Dm.front()][i]];
                minim[ind_m++][i] = Dm.front();
            }

            if (j >= d && !DM.empty()) {
                maxT = mat[DM.front()][maxim[DM.front()][i]];
                maxim[ind_M++][i] = DM.front();
            }

            calcTot(Dm, [](int x, int y) { return x < y;}, i, j, minim, d);
            calcTot(DM, [](int x, int y) { return x > y;}, i, j, maxim, d);

            getBarDif(maxT, minT);
        }
        ind_m = 0;
        ind_M = 0;
        emptyDeque(Dm);
        emptyDeque(DM);
        minT = 10000, maxT = -1;
    }
}

void solve() {
    while (p) {
        min_loc = 100000;
        cnt_min = 0;

        fin >> dx >> dy;
        calcMinMax(dy);
        calcMinMaxTot(dx, cnt_col);
        cnt_col = 0;

        if (dx != dy) {
            calcMinMax(dx);
            calcMinMaxTot(dy, cnt_col);
        }

        fout << min_loc << " " << cnt_min << '\n';
        p--;
    }
}

int main() {
    fin >> n >> m >> p;
    citire();
    solve();
    return 0;
}
