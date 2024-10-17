///LIMITA DE MEMORIE
#include <iostream>
#define MOD 997

using namespace std;

int plinuri[100];
int k_static = 0, x;

int tzese(int n, int m, int k)
{
    if (k < 0) return 0;

    if (n == m && plinuri[n] < 1 && n != x) return 0;

    if (plinuri[n] == 1) k = k_static;

    if(n==1||m==1)
        return n+m;
    return (tzese(n, m-1, k - 1)+tzese(n-1, m, k - 1)) % MOD;

}

void citire_plin(int k) {
    int temp = 0;
    for (int i = 0; i < k; i++) {
        cin >> temp;
        plinuri[temp]++;
    }
}

int main()
{
    int k, pl;
    cin >> x >> k >> pl; k_static = k;
    citire_plin(pl);
    cout << tzese(x, x, k) % MOD;
    return 0;
}
