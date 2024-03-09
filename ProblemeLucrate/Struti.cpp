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

///CONTINUAREA NU CORECTA
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

        D.push_back(j);
    }
    else D.push_back(j);
}

void calcTot(deque <int>& D, function<bool(int x, int y)> cmp, int i, int j, int m[][1005], int d) {
    if (!D.empty()) {
        if (D.front() + d <= j) {
            D.pop_front();
        }

        while (!D.empty() && cmp(mat[j][m[j][i]], mat[j - 1][m[D.back()][i]]))
            D.pop_back();

        D.push_back(j);
    }
    else D.push_back(j);
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
        for (int j = 0; j <= m; j++) {
            if (j >= d && !Dm.empty())
                minim[i][ind_m++] = Dm.front();

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

void calcMinMaxTot(int d) {
    ind_m = 0;
    ind_M = 0;
    emptyDeque(Dm);
    emptyDeque(DM);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j <= n; j++) {
            if (j >= d && !Dm.empty())
                minim[ind_m++][i] = Dm.front();

            if (j >= d && !DM.empty())
                maxim[ind_M++][i] = DM.front();

            calcTot(Dm, [](int x, int y) { return x < y;}, i, j, minim, d);
            calcTot(DM, [](int x, int y) { return x > y;}, i, j, maxim, d);
        }
        ind_m = 0;
        ind_M = 0;
        emptyDeque(Dm);
        emptyDeque(DM);
    }
}

void solve() {
    while (p) {
        fin >> dx >> dy;
        calcMinMax(dy);
        calcMinMaxTot(dx);
        p--;
    }
}

int main() {
    fin >> n >> m >> p;
    citire();
    solve();
    return 0;
}
