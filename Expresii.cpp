//REZOLVARE DE 15 PUNCTE
#include <iostream>
#include <fstream>
#include <cstring>

#define MOD %1000000007

using namespace std;

ifstream fin("expresii.in");
ofstream fout("expresii.out");

char e[2000005];

int getParanthesis(int st, int dr) {
    int cnt = 0;

    for (st++; st < dr; st++) {
        if (e[st] == ')' || e[st] == ']') cnt++;
        if (e[st] == '(' || e[st] == '[') cnt--;

        if (e[st] == ',' && cnt == 0) return st;
    }
    return -1;
}

long long gcd(int a, int b) {
    int r = 1;
    while (b) {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

long long lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

long long getNum(int st, int dr, int x) {
    if (e[st] == 'x') return x;

    int num = 0;
    for (; st <= dr; st++)
        num = num * 10 + (e[st] - '0');

    return num;
}

long long eval(int st, int dr, int a) {
    int p = getParanthesis(st, dr);

    if (p != -1) {
        if (e[st] == '(') {
            long long E1 = eval(st + 1, p - 1, a);
            long long E2 = eval(p + 1, dr - 1, a);

            return gcd(E1, E2);
        }
        else if (e[st] == '[') {
            long long E1 = eval(st + 1, p - 1, a);
            long long E2 = eval(p + 1, dr - 1, a);

            return lcm(E1, E2);
        }
    }

    return getNum(st, dr, a);
}

int main()
{
    int l, a, b;
    int sum = 0;
    fin.getline(e, 2000005);
    fin >> a >> b;
    l = strlen(e);

    for (; a <= b; a++) {
        sum += eval(0, l - 1, a)MOD;
    }

    fout << sum;

    return 0;
}
