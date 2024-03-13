///Exmeplu
#include <fstream>
#include <algorithm>

#define MOD 1000000009
#define NMAX 100001

typedef long long LL;

using namespace std;

ifstream fin("fotbal.in");
ofstream fout("fotbal.out");

struct Copil {
    int Si, Fi;
    bool drp;
};

Copil copii[NMAX];
LL fact[NMAX];
int n, k;
LL cnt_dir[2];
LL moduri;

void precalc() {
    fact[0] = 1;
    for (int i = 1; i < NMAX; i++) fact[i] = fact[i - 1] * i % MOD;
}

void citire() {
    for (int i = 0; i < n; i++) {
        fin >> copii[i].Si >> copii[i].Fi >> copii[i].drp;
        ///copii[i].drp ? cnt_dir[1]++ : cnt_dir[0]++;
    }
}

bool cond(Copil c1, Copil c2) {
    return c1.Si < c2.Si;
}

int min(Copil c) {
    return min(c.Si, c.Fi);
}

int max(Copil c) {
    return max(c.Si, c.Fi);
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
    return fact[N] * invmod(fact[N - K], fact[K]) % MOD;
}

void solve() {
    for (int i = 0; i < n - k; i++) {
        for (int j = i + 1; j < n; j++) {
            if (min(copii[i]) <= max(copii[j])) {
                cnt_dir[copii[i].drp]++;
            }
        }

        moduri += comb(cnt_dir[0] + cnt_dir[1], k - 1) - comb(cnt_dir[copii[i].drp], k - 1);
        copii[i].drp ? cnt_dir[1]-- : cnt_dir[0]--;
    }
}

int main()
{
    fin >> n >> k;
    precalc();
    citire();
    sort(copii, copii + n, cond);
    solve();

    fout << moduri;
    return 0;
}
