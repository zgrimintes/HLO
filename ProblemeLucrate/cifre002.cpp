#include <iostream>

using namespace std;

int get_nbs(int n, int &even){
    int nbs = 0;

    while (n) {
        if (n % 10 % 2 == 0) even++;
        nbs++;
        n /= 10;
    }

    return nbs;
}

int fact(int n) {
    long long f = 1;
    for (int i = 1; i <= n; i++)
        f *= i;

    return f;
}

void solve(int n){
    int per = 0;
    int cpy = n;
    int even_nbs = 0, nbs = 0;
    nbs = get_nbs(n, even_nbs);

    for (; even_nbs; even_nbs--){
        per += fact(nbs - 1);
    }

    cout << per;
}

int main()
{
    int n;
    cin >> n;
    solve(n);

    return 0;
}
