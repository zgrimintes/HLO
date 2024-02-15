//De terminat, nu da la toate testele
#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <cstring>

using namespace std;

ifstream fin("castel.in");
ofstream fout("castel.out");

stack <char> smn;
stack <int> nbs;
queue < pair <int, int> > Q;

int mat[105][105];
int tmp[105][105];
char ec[2000];
int n, exps, ind;
int cnt_cam = 0;
int lastI, lastJ;

int dI[4] = {-1, 0, 1, 0},
    dJ[4] = {0, 1, 0, -1};

int getY(int nr) {
    return (nr % n == 0) ? n : nr % n;
}

int eval(int a, int b, char s) {
    switch (s) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    }
}

int getRes() {
    int v1 = nbs.top();
    nbs.pop();

    int v2 = nbs.top();
    nbs.pop();

    char s = smn.top();
    smn.pop();

    return eval(v2, v1, s);
}

bool prioritate(char s1, char s2) {
    if (s1 == '(') return true;
    if ((s1 == '+' || s1 == '-') && (s2 == '*' || s2 == '/')) return true;

    return false;
}

int getNb() {
    int nb = 0;
    for (; ec[ind] >= '0' && ec[ind] <= '9'; ind++)
        nb = nb * 10 + ec[ind] - '0';

    return nb;
}

void solve() {

    int lng = strlen(ec);
    while (ind < lng) {
        switch (ec[ind]) {
            case '(':
                smn.push(ec[ind++]);
                break;
            case ')':
                while (smn.top() != '(')
                    nbs.push(getRes());

                smn.pop();
                ind++;
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                if (smn.empty() || prioritate(smn.top(), ec[ind]))
                    smn.push(ec[ind++]);
                else {
                    do {
                        nbs.push(getRes());
                    } while (!smn.empty() && !prioritate(smn.top(), ec[ind]));
                    smn.push(ec[ind++]);
                }
                break;
            default:
                nbs.push(getNb());
                break;
        }
    }

    while (!smn.empty()) {
        nbs.push(getRes());
    }
}

void citire() {
    for (int i = 0; i < exps; i++) {
        ind = 0;
        fin.getline(ec, 2000);
        int cam = getNb();
        ind++;
        solve();
        mat[(cam - 1) / n][getY(cam)] = nbs.top();
    }

}

bool inMat(int i, int j) {
    return (i >= 0 && i < n) && (j >= 1 && j <= n);
}

void Lee() {
    Q.push({ 0, 1 });
    tmp[0][1] = mat[0][1];
    cnt_cam = 1;

    while (!Q.empty()) {
        int ic = Q.front().first,
            jc = Q.front().second;

        Q.pop();

        if (lastI < ic) lastI = ic;
        if (lastJ < jc) lastJ = jc;

        for (int k = 0; k < 4; k++) {
            int iv = ic + dI[k],
                jv = jc + dJ[k];

            if (!inMat(iv, jv)) continue;

            if (mat[iv][jv] > 0 && (tmp[ic][jc] + mat[iv][jv] < tmp[iv][jv] || tmp[iv][jv] == 0)) {
                if (tmp[iv][jv] == 0) cnt_cam++;
                tmp[iv][jv] = mat[iv][jv] + tmp[ic][jc];
                Q.push({iv, jv});
            }
        }
    }
}

int main()
{
    fin >> n >> exps;
    fin.get();
    citire();
    Lee();

    if (tmp[n - 1][n]) {
        cout << 1 << "\n";
        cout << cnt_cam << "\n";
        cout << tmp[n - 1][n] << "\n";
    }
    else {
        cout << 0 << "\n";
        cout << cnt_cam << "\n";
        cout << tmp[lastI][lastJ] << "\n";
    }

    return 0;
}
