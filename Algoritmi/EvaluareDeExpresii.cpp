#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

char exp[100000];

int cautaSemn(int st, int dr, char c1, char c2) {
    int cnt = 0;
    for (; dr >= st; dr--) {
        if (exp[dr] == ')') cnt++;
        if (exp[dr] == '(') cnt--;

        if (cnt == 0 && (exp[dr] == c1 || exp[dr] == c2)) return dr;
    }
    return -1;
}

int num(int st, int dr){
    int nr = 0;
    for (; st <= dr; st++) {
        nr = nr * 10 + (exp[st] - '0');
    }
    return nr;
}

int solve( int st, int dr) {
    int s1 = cautaSemn(st, dr, '+', '-');
    if (s1 != -1){
        int E1 = solve(st, s1 - 1);
        int E2 = solve(s1 + 1, dr);

        if (exp[s1] == '+') return E1 + E2;
        return E1 - E2;
    }

    int s2 = cautaSemn(st, dr, '*', '/');
    if (s2 != -1){
        int E1 = solve(st, s2 - 1);
        int E2 = solve(s2 + 1, dr);

        if (exp[s2] == '*') return E1 * E2;
        return E1 / E2;
    }

    if (exp[st] == '(' && exp[dr] == ')')
        return solve(st + 1, dr - 1);
    return num(st, dr);

}

int main()
{
    ifstream fin("evaluare.in");
    ofstream fout("evaluare.out");

    fin.getline(exp, 100000);
    int l = strlen(exp);

    fout << solve(0, l - 1);

    return 0;
}
