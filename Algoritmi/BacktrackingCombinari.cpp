#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int sol[10];
int n, p;

void afis(){
    for (int i = 0; i < p; i++) {
        cout << sol[i] << " ";
    }
    cout << "\n";
}

void backtrack(int k) {
    if (k == p) {
        afis();
        return;
    }

    for (int i = (k == 0)?1:sol[k-1]+1; i <= n - p + k +1; i++) {
        sol[k] = i;
        backtrack(k + 1);
    }

}

int main()
{
    cin >> n >> p;
    backtrack(0);

    return 0;
}
