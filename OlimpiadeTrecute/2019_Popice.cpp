#include <iostream>
#include <fstream>
#include <cstring>
#define MOD 666013

using namespace std;

ifstream fin("popice.in");
ofstream fout("popice.out");

long long n, k, q;
char res[10];

long long getNb(int i){
    long long nb = 0;
    for (i; res[i]; i++)
        if (res[i] >= '0' && res[i] <= '9')
            nb = nb * 10 + res[i] - '0';

    return nb;
}

void citire_res() {
    while (q) {
        fin >> res;
        for (int i = 0; res[i]; i++){
            if (res[i] == '=') {
                n -= getNb(i+1);
                k--;
                break;
            }
            if (res[i] == '+'){
                n -= getNb(i+1);
                break;
            }
        }

        q--;
    }
}

long long factMod(long long x){
    long long rez = 1;
    for (int i = 1; i <= x; i++)
        rez = rez * i % MOD;

    return rez;
}

long long modPow(long long b, long long e) {
    long long rez = 1;
    while (e) {
        if (e % 2 == 1)
            rez = (rez * b) % MOD;
        b = b * b % MOD;
        e /= 2;
    }

    return rez;
}

long long invMod(long long x){
    return modPow(x, MOD - 2);
}

long long solve(){

    return (factMod(n + k - 1) * invMod(factMod(k - 1) * factMod(n) % MOD)) % MOD;
}

int main()
{
    fin >> n >> k >> q;
    citire_res();
    fout << solve();
    return 0;
}
