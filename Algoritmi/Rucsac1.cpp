#include <iostream>

using namespace std;

int gmax, g, v, n;
int dp[10001];

void formDP() {
    cin >> g >> v;

    for (int i = gmax; i >= g; i--) {
        dp[i] = max(v + dp[i - g], dp[i]);
    }
}

int main()
{
    cin >> n >> gmax;

    while (n) {
        formDP();
        n--;
    }

    cout << dp[gmax];

    return 0;
}
