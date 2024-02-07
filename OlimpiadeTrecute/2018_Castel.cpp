//De terminat
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
char ec[2000];
int n, exps, ind;
int cnt_cam = 0;

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
        mat[(cam - 1) / 5][getY(cam)] = nbs.top();
    }

}

void Lee(int i, int j) {
    Q.push({ 1, 1 });

    while (!Q.empty()) {
        int ic = Q.front().first,
            jc = Q.front().second;

        Q.pop();
    }
}

int main()
{
    fin >> n >> exps;
    fin.get();
    citire();
    Lee(1, 1);
    return 0;
}
