///10 PUNCTE
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

    return fact[N] * invmod(fact[N - K], fact[K]) % MOD;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

void solve() {
    for (int i = 0; i < n - k; i++) {
        for (int j = i + 1; j < n; j++) {
            if (max(copii[i].Si, copii[i].Fi) >= min(copii[j].Si, copii[j].Fi))
                cnt_dir[copii[j].drp]++;
        }

        moduri += (comb(cnt_dir[0] + cnt_dir[1], k - 1) - comb(cnt_dir[copii[i].drp], k - 1)) % MOD;
        //copii[i].drp ? cnt_dir[1]-- : cnt_dir[0]--;
        cnt_dir[0] = cnt_dir[1] = 0;
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
