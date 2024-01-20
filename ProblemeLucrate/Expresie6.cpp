//REZOLVARE DE 100 DE PUNCTE
#include <iostream>
#include <cstring>

using namespace std;

char exps[260];
int nrX[200], nrY[200], nrZ[200];

int cautaSemn(int st, int dr) {
    int cnt_p = 0;
    for (; dr >= st; dr--) {
        if (exps[dr] == ')') cnt_p++;
        if (exps[dr] == '(') cnt_p--;

        if (cnt_p == 0 && (exps[dr] == '+' || exps[dr] == '-')) return dr;
    }
    return -1;
}

int getNum(int st, int dr, char nec) {
    int nr = 0;
    int cntcif = 0;
    for (; st <= dr; st++) {
        if (exps[st] >= '0' && exps[st] <= '9') {
            nr = nr * 10 + (exps[st] - '0');
            cntcif++;
        }
        else if (exps[st] == nec) {
            if (nr != 0) return nr;
            else if (cntcif) return 0;
            return 1;
        }
        else return 0;
    }

    return 0;
}

int solveX(int st, int dr) {

    int s = cautaSemn(st, dr);

    if (s != -1) {
        int E1 = solveX(st, s - 1);
        int E2 = solveX(s + 1, dr);

        if (exps[s] == '+') return E1 + E2;
        return E1 - E2;
    }

    return getNum(st, dr, 'x');
}

int solveY(int st, int dr) {

    int s = cautaSemn(st, dr);

    if (s != -1) {
        int E1 = solveY(st, s - 1);
        int E2 = solveY(s + 1, dr);

        if (exps[s] == '+') return E1 + E2;
        return E1 - E2;
    }

    return getNum(st, dr, 'y');
}

int solveZ(int st, int dr) {

    int s = cautaSemn(st, dr);

    if (s != -1) {
        int E1 = solveZ(st, s - 1);
        int E2 = solveZ(s + 1, dr);

        if (exps[s] == '+') return E1 + E2;
        return E1 - E2;
    }

    return getNum(st, dr, 'z');
}

void solve(int n) {
    int x = solveX(0, n); if (!x) x = -2000000001;
    int y = solveY(0, n); if (!y) y = -2000000001;
    int z = solveZ(0, n); if (!z) z = -2000000001;

    int m = max(x, max(y, z));

    if (m == -2000000001) {
        cout << 0;
        return;
    }

    if (x == m) {
        cout << x << "x ";
    }
    if (y == m) {
        cout << y << "y ";
    }
    if (z == m) {
        cout << z << "z ";
    }
}

void eraseSpaces() {
    char cexp[260] = { 0 };
    int indC = 0;
    for (int i = 0;i < strlen(exps); i++)
        if (exps[i] != ' ') cexp[indC++] = exps[i];

    for (int i = 0; i < strlen(exps); i++)
        exps[i] = cexp[i];
}

int main()
{
    cin.getline(exps, 260);
    eraseSpaces();
    int len = strlen(exps);
    solve(len - 1);

    return 0;
}
