///100 PUNCTE
#include <fstream>
#include <stack>

#define MOD 1000000007

using namespace std;

ifstream fin("leftmax.in");
ofstream fout("leftmax.out");

stack <int> S;
int n;
int s[100001], d[100001];
int nr[100001];
long long cnt_mod;

void citire() {
    for (int i = 1; i <= n; i++) 
        fin >> nr[i];
}

long long gauss(long long n) {
    return (n * (n + 1)) / 2;
}

void solve() {
    for (int i = 1; i <= n; i++) {
        if (d[i] <= s[i])
            cnt_mod += gauss(d[i] + 1);
        else
            cnt_mod += gauss(d[i] + 1) - gauss(d[i] - s[i]);
    }
}

void calcStDr() {
    nr[0] = nr[n + 1] = n + 1;

    S.push(0);

    for (int i = 1; i <= n; i++) {
        while (nr[S.top()] < nr[i]) S.pop();

        s[i] = i - S.top() - 1;
        S.push(i);
    }
    
    while (S.size()) S.pop();

    S.push(n + 1);

    for (int i = n; i > 0; i--) {
        while (nr[S.top()] < nr[i]) S.pop();

        d[i] = S.top() - i - 1;
        S.push(i);
    }
}

int main()
{
    fin >> n;
    citire();
    calcStDr();
    solve();

    fout << cnt_mod % MOD;
    return 0;
}
