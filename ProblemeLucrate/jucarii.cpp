#include <iostream>
#define MOD 224737

using namespace std;

long long aranjamente(long long n, long long k) {
    long long rez = 1;
    for (int i = n - k + 1; i <= n; i++)
        rez = rez * i % MOD;

    return rez % MOD;
}

int main() {
    long long n, k;
    cin >> k >> n;
    cout << aranjamente(n, k);

    return 0;
}
