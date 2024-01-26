#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int sol[10];
int n;

void afis1(){
    for (int i = 0; i < n; i++) {
        if (sol[i] == 1)cout << i + 1 << " ";
    }
    cout << "\n";
}

void bec1(int k){
    if (k == n) {
        afis1();
        return;
    }

    for (int i = 0; i <= 1; i++){
        sol[k] = i;
        bec1(k+1);
    }
}

void bec2(int k) {
    if (k) {
        for (int i = 0; i < k; i++)
            cout << sol[i] << " ";
        cout << "\n";
    }

    for (int i = (k == 0)? 1 : sol[k - 1] + 1; i <= n; i++){
        sol[k] = i;
        bec2(k+1);
    }
}

int main()
{
    cin >> n;
  
    bec1(0);
    bec2(0);

    return 0;
}
