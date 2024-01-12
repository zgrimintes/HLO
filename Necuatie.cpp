#include <iostream>
#include <fstream>
#define MOD 555557

using namespace std;

ifstream fin("necuatie.in");
ofstream fout("necuatie.out");

long long factmod(long long n){
    long long rez = 1;
    for (long long i = 1; i <= n; i++)
        rez = (rez * i) % MOD;

    return rez % MOD;
}

long long modpow(long long n, long long e) {
    long long r = 1;
    while (e){
        if (e % 2 == 1)
            r = (r * n) % MOD;
        n = (n * n) % MOD;
        e /= 2;
    }

    return r % MOD;
}

long long combination(long long n, long long k){
    long long up = factmod(n);
    long long down = (factmod(k) * factmod(n-k)) % MOD;
    long long revmod = modpow(down, MOD - 2);

    return (up * revmod) % MOD;
}

void addCombinations(long long &z, long long n){

    for (long long i = 0; i <= n/2; i++){
        z += (combination(n, i) * combination(n - i, i)) % MOD;
    }

}

void solve(long long n) {
    long long rez = 0;
    addCombinations(rez, n);

    fout << rez % MOD;
}

int main()
{
    long long n;
    fin >> n;
    solve(n);

    return 0;
}
