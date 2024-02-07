#include <iostream>
#include <fstream>
#include <unordered_set>
#define MOD 666013

using namespace std;

ifstream fin("monede.in");
ofstream fout("monede.out");

long long n, k;
long long factorial[100005];

unordered_set <int> monede;

void getCoins(){
    for (int i = 0; i < n; i++) {
        int val;
        fin >> val;
        monede.insert(val);
    }
}

void makeFacts(){
    factorial[0] = 1;
    for (int i = 1; i < 100005; i++){
        factorial[i] = i * factorial[i - 1] % MOD;
    }
}

long long modPow(long long b, long long e){
    long long rez = 1;
    while (e){
        if (e & 1)
            rez = rez * b % MOD;
        b = b * b % MOD;
        e /= 2;
    }

    return rez;
}

long long invMod(long long x) {
    return modPow(x, MOD - 2);
}

long long solve(){
    return (factorial[n] * invMod(factorial[n-k] * factorial[k] % MOD)) % MOD;
}

int main()
{
    fin >> n >> k;
    getCoins();
    makeFacts();

    n = monede.size();

    fout << solve();

    return 0;
}
