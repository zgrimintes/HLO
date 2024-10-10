#include <iostream>
#include <map>
#define LL long long

using namespace std;

int arr[200000];
LL cnt = 0;

void citire(int n) {
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void solve(int n, int x) {
    map<LL, LL> prefSum;

    prefSum[0] = 1;
    LL pref = 0;

    for (int i = 0; i< n; i++) {
        pref += arr[i];
        cnt += prefSum[pref - x];
        prefSum[pref]++;
    }
}

int main()
{
    int n, x; cin >> n >> x;
    citire(n);
    solve(n, x);

    cout << cnt;
    return 0;
}
