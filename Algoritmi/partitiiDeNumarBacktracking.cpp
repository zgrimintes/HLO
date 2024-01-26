#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int sol[10], maxim[10];
int n;

void afis(int k){
    for (int i = 0; i < k; i++) {
        cout << sol[i] << " ";
    }
    cout << "\n";
}

void partNum(int k, int s) {
    if (s == n) {
        afis(k);
        return;
    }

    for (int i = 1; i <= n - s; i++) { ///for (int i = (k == 0) ? 1 : sol[k - 1]; i <= n - s; i++)
        sol[k] = i;
        partNum(k + 1, s + i);
    }
}

int main()
{
    cin >> n;
    partNum(0, 0);

    return 0;
}
