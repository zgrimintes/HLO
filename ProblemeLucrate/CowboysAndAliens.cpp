#include <iostream>
#include <fstream>
#define MOD 555557

using namespace std;

ifstream fin("cowboysandaliens.in");
ofstream fout("cowboysandaliens.out");

long long factmod(long long n){
    long long rez = 1;
    for (long long i = 1; i <= n; i++)
        rez = rez * i % MOD;

    return rez % MOD;
}

long long clc_smp(long long n, long long b){
    int rez = 1;
    for (long long i = n; i >= b; i--) {
        rez = rez * i % MOD;
    }

    return rez;
}

void solve(long long n, long long m){
    cout << (factmod(m) * ((clc_smp(m - 1, m - n) % MOD))) % MOD;
}

int main()
{
    long long n, m;
    fin >> m >> n;
    solve(n, m);

    return 0;
}
