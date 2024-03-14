///100 PUNCTE
#include <fstream>
#include <algorithm>

#define MOD 1000000009
#define NMAX 100001

typedef long long LL;

using namespace std;

ifstream fin("fotbal.in");
ofstream fout("fotbal.out");

struct Copil {
    int pos;
    bool ev, drp;
};

Copil copii[NMAX * 2 + 1];
LL fact[NMAX + 2];
int n, k;
LL cnt_dir[2];
LL moduri;

void precalc() {
    fact[0] = 1;
    for (int i = 1; i <= NMAX; i++) fact[i] = fact[i - 1] * i % MOD;
}

void citire() {
    for (int i = 1; i <= n; i++) {
        int x, y, z;
        fin >> x >> y >> z;
        copii[2 * i - 2] = { x, false, (bool)z };
        copii[2 * i - 1] = { y, true, (bool)z };
    }
}

LL modpow(LL b, LL e) {
    LL rez = 1;
    while (e) {
        if (e & 1) 
            rez = rez * b % MOD;

        b = b * b % MOD;
        e /= 2;
    }

    return rez;
}

LL invmod(LL a, LL b) {
    return modpow(a * b % MOD, MOD - 2);
}

LL comb(LL N, LL K) {
    if (N == 0) return 0;
    if (N < K) return 0;

    return fact[N] * invmod(fact[N - K], fact[K]) % MOD;
}

void solve() {
    for (int i = 0; i <= 2 * n; i++) {
        if (!copii[i].ev) cnt_dir[copii[i].drp]++;
        else {
            cnt_dir[copii[i].drp]--;
            moduri = (moduri + comb(cnt_dir[0] + cnt_dir[1], k - 1) + MOD - comb(cnt_dir[copii[i].drp], k - 1)) % MOD;
        }
    }
}

bool cmp(Copil a, Copil b) {
    if (a.pos == b.pos) return a.ev < b.ev;

    return a.pos < b.pos;
}

int main()
{
    fin >> n >> k;
    precalc();
    citire();
    sort(copii, copii + n * 2, cmp);
    solve();

    fout << moduri;
    return 0;
}
