#include <iostream>
#define LL long long

using namespace std;

int arr[200000];
LL cnt = 0;

void citire(int n) {
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void solve(int n, int x) {
    int l = 0;
    LL sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        while (sum > x) {
            sum -= arr[l++];
        }

        if (sum == x) cnt++;
    }

    while (sum > x) {
        sum -= arr[l++];
        
        if (sum == x) cnt++;
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
