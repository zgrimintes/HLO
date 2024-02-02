///DE TERMINAT C2
#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

ifstream fin("ruine.in");
ofstream fout("ruine.out");

queue < pair <int, int> > Q;

pair <int, int> Pin[300];
pair <int, int> Pie[300];
int harta[105][105];
int cam[105][105];

int cnt_rooms = 0;
int n, m, p, c;
bool continueFill;

void citire() {
    int i, j;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++) {
            fin >> harta[i][j];
            //cam[i][j] = harta[i][j];
        }
}

void bordare() {
    for (int i = 0; i <= n + 1; i++)
        harta[i][0] = harta[i][m + 1] = -1;

    for (int i = 0; i <= m + 1; i++)
        harta[0][i] = harta[n + 1][i] = -1;
}

bool isCorner(int n) {
    if (n < 0) return 0;

    if (n & 1 && (n >> 3) & 1)
        return true;

    return false;
}

bool inMat(int i, int j) {
    if (i < 1 || i > n || j < 1 || j > m)
        return false;
    return true;
}

void fillRoom(int i, int j) {
    if (inMat(i, j)) {
        continueFill = false;
        cnt_rooms--;
        return;
    }

    if (cam[i][j] < 0) return;

    int nr = harta[i][j];

    cam[i][j] = -1;

    if ((nr & 1) == 0 && continueFill)
        fillRoom(i - 1, j);

    if (((nr >> 1) & 1) == 0 && continueFill)
        fillRoom(i, j + 1);

    if (((nr >> 2) & 1) == 0 && continueFill)
        fillRoom(i + 1, j);

    if (((nr >> 3) & 1) == 0 && continueFill)
        fillRoom(i, j - 1);
}

int camere(int i, int j) {
    for (int i = 1; i <= n; i++) {
        if (i == 3)
            cout << "";
        for (int j = 1; j <= m; j++)
            if (isCorner(harta[i][j])) {
                continueFill = true;
                fillRoom(i, j);
                cnt_rooms++;
            }
    }

    return cnt_rooms;
}

bool checkPortals(int i, int j, int step) {
    for (int k = 0; k < p; k++) {
        if (i == Pin[k].first && j == Pin[k].second) {
            Q.push({ Pie[k].first, Pie[k].second });
            cam[Pie[k].first][Pie[k].second] = step + 2;
            return true;
        }
        else if (i == Pie[k].first && j == Pie[k].second) {
            Q.push({ Pin[k].first, Pin[k].second });
            cam[Pin[k].first][Pin[k].second] = step + 2;
            return true;
        }
    }

    return false;
}

void Lee(int i, int j, int x, int y) {
    
    Q.push({ i, j });
    int ic = 0, jc = 0;
    cam[1][1] = 1;

    while (!Q.empty())
    {
        ic = Q.front().first;
        jc = Q.front().second;

        if (ic == 6) 
            cout << "";

        Q.pop();

        int nr = harta[ic][jc];

        if ((nr & 1) == 0 && cam[ic - 1][jc] == 0 && inMat(ic - 1, jc)) {

            if (!checkPortals(ic - 1, jc, cam[ic][jc]))
                Q.push({ ic - 1, jc });
            
            cam[ic - 1][jc] = cam[ic][jc] + 1;
        }
        if (((nr >> 1) & 1) == 0 && cam[ic][jc + 1] == 0 && inMat(ic, jc + 1)) {

            if (!checkPortals(ic, jc + 1, cam[ic][jc]))
                Q.push({ ic, jc + 1});

            cam[ic][jc + 1] = cam[ic][jc] + 1;
        }
        if (((nr >> 2) & 1) == 0 && cam[ic + 1][jc] == 0 && inMat(ic + 1, jc)) {
            
            if (!checkPortals(ic + 1, jc, cam[ic][jc]))
                Q.push({ ic + 1, jc });
            
            cam[ic + 1][jc] = cam[ic][jc] + 1;
        }
        if (((nr >> 3) & 1) == 0 && cam[ic][jc - 1] == 0 && inMat(ic, jc - 1)) {
            
            if (!checkPortals(ic, jc + 1, cam[ic][jc]))
                Q.push({ ic, jc + 1 });
            
            cam[ic][jc - 1] = cam[ic][jc] + 1;
        }
    }
}

void portale() {
    int indPort = 0;
    int cp = p;
    int xp, yp;
    while (cp) {
        fin >> xp >> yp;
        Pin[indPort].first = xp, Pin[indPort].second = yp;

        fin >> xp >> yp;
        Pie[indPort].first = xp, Pie[indPort].second = yp;

        indPort++;
        cp--;
    }
}

int main()
{
    int x, y;
    fin >> n >> m >> p >> c;
    citire();
    bordare();
    portale();
    if (c == 1)
        fout << camere(1, 1);
    else {
        fin >> x >> y;
        Lee(1, 1, x, y);
        fout << cam[x][y];
    }

    return 0;
}
