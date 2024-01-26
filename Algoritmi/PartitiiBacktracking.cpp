#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int sol[10], maxim[10];
int n;

void afis(){
    for (int i = 1; i <= maxim[n]; i++){
        cout << "{";
        for (int j = 0; j < n; j++)
            if (sol[j] == i) cout << j + 1;
        cout << "}";
    }
    cout << "\n";
}

void part(int k) {
    if (k == n) {
        afis();
        return;
    }

    for (int i = 1; i <= maxim[k]+1; i++) {
        sol[k] = i;
        maxim[k+1] = max(maxim[k],i);
        part(k + 1);
    }
}

int main()
{
    cin >> n;
    part(0);

    return 0;
}
