#include <fstream>
#include <map>

#define MOD 1000000007

typedef long long LL;

using namespace std;

ifstream fin("ohio.in");
ofstream fout("ohio.out");

map <int, int> M;
LL fact[100001];
LL n, k, maxn;
LL ans;

LL modPow(LL b, LL e){
    LL rez = 1;
    while (e){
        if (e & 1)
            rez = rez * b % MOD;
        b = b * b % MOD;
        e /= 2;
    }

    return rez;
}

LL invMod(LL a, LL b){
    return modPow(a * b % MOD, MOD - 2);
}

LL comb (LL N, LL K){
    return fact[N] * invMod(fact[N - K], fact[K]) % MOD;
}

LL max(LL a, LL b){
    return a < b ? b : a;
}

solve(){
    for (int i = maxn; i > 0; i--){
        int temp = 0;
        for (int j = 1; j <= max(k, M[i]); j++){
            temp = (temp + comb(n - M[i], k - j) * comb(M[i], j) % MOD) % MOD;
        }
        if (M[i] != 0) ans = (ans + (temp * i % MOD)) % MOD;
        n -= M[i];
    }

    fout << ans;
}

void citire(){
    int x;
    for (int i = 0; i < n; i++){
        fin >> x, M[x]++;
        if (x > maxn) maxn = x;
    }

}

void precalc(){
    fact[0] = fact[1] = 1;
    for (int i = 2; i < 100001; i++)
        fact[i] = fact[i - 1] * i % MOD;
}

int main()
{
    fin >> n >> k;
    citire();
    precalc();
    solve();
    return 0;
}
