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

//REZOLVARE FOLOSIND STACK-URI
#include <iostream>
#include <fstream>
#include <cstring>
#include <stack>

#define MOD %1000000007

using namespace std;

ifstream fin("expresii.in");
ofstream fout("expresii.out");

char e[2000005];
int pos;

stack <char> paranthesis;
stack <int> nums;


long long gcd() {
    int a = nums.top(); nums.pop();
    int b = nums.top(); nums.pop();
    int r = 1;
    while (b) {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
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

long long lcm() {
    int a = nums.top(); nums.pop();
    int b = nums.top(); nums.pop();
    return (a * b) / gcd(a, b);
}

int getNum(int x) {
    if (e[pos] == 'x') { pos++; return x; }

    int nb = 0;
    for (; e[pos] >= '0' && e[pos] <= '9';) {
        nb = nb * 10 + (e[pos++] - '0');
    }

    return nb;
}

int solve(int n, int x) {
    while (pos < n) {
        switch (e[pos])
        {
        case '(':
        case '[':
            paranthesis.push(e[pos++]);
            break;
        case ')':
        case ']':
            paranthesis.pop();
            if (e[pos] == ')') nums.push(gcd());
            else if (e[pos] == ']') nums.push(lcm());
            pos++;
            break;
        case ',':
            pos++;
            break;
        default:
            nums.push(getNum(x));
            break;
        }
    }

    return nums.top();
}

int main() {
    int a, b, sum = 0;
    fin.getline(e, 2000005);
    fin >> a >> b;

    for (; a <= b;) {
       sum = (sum + solve(strlen(e), a++))MOD;
       nums.pop();
       pos = 0;
    }

    fout << sum;

    return 0;
}
