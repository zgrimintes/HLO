//DE TERMINAT
#include <iostream>
#include <cstring>

using namespace std;

char exp[260];

int cautaSemn(int st, int dr){
    int cnt_p = 0;
    for (; dr >= st; dr--) {
        if (exp[dr] == ')') cnt_p++;
        if (exp[dr] == '(') cnt_p--;

        if (cnt_p = 0 && (exp[dr] == '+' || exp[dr] == '-' )) return dr;
    }
    return -1;
}

int solve(int st, int dr) {

    int s = cautaSemn(st, dr);

    if (s != -1) {
        int E1 = solve(st, s - 1);
        int E2 = solve(s + 1, dr);

        if (exp[s] == '+') return E1 + E2;
        return E1 - E2;
    }


}

int main()
{
    cin.getline(exp, 260);
    int len = strlen(exp);

    cout << solve(0, len - 1);

    return 0;
}
