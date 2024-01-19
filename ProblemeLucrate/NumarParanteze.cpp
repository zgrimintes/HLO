//REZOLVARE DE 100 DE PUNCTE 
//+ Numere Catalan
#include <iostream>

#define MOD 666013

using namespace std;

long long factmod(long long n){
    long long rez = 1;
    for (long long i = 1; i <= n; i++)
        rez = (rez * i) % MOD;

    return rez % MOD;
}

long long modPow(long long n, long long e) {
    long long rez = 1;
    while (e){
        if (e % 2 == 1)
            rez = (rez * n) % MOD;

        n = (n * n) % MOD;
        e /= 2;
    }

    return rez % MOD;
}

long long combs(int n, int k) {
    long long sus = factmod(n);
    long long jos = (factmod(n - k) * factmod(k + 1)) % MOD;
    long long invMod = modPow(jos, MOD - 2);

    return (sus * invMod) % MOD;
}

long long solve(int n) {
    return ((combs(2 * n, n) % MOD)) % MOD;
}

int main()
{
    int n;
    cin >> n;
    cout << solve(n);

    return 0;
}
