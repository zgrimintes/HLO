#include <iostream>

using namespace std;

int nr_mare[100000];
int toMultp[100000];
int multiplier[100000];

int get_nbs(int n){
    int nbs = 0;

    while (n) {
        nbs++;
        n /= 10;
    }

    return nbs;
}

void multp(){
    nr_mare[0] = toMultp[0] + multiplier[0] - 1;

    for (int i = 1; i <= toMultp[0] + multiplier[0]; i++)
        nr_mare[i] = 0;

    for (int i = 1; i <= toMultp[0]; i++)
        for (int j = 1; j <= multiplier[0]; j++)
            nr_mare[i + j - 1] += toMultp[i] * multiplier[j];

    int t = 0;
    for (int i = 1; i <= nr_mare[0]; i++){
        nr_mare[i] += t;
        t = nr_mare[i] / 10;
        nr_mare[i] = nr_mare[i] % 10;
    }

    if(t != 0) {
        nr_mare[0]++;
        nr_mare[nr_mare[0]] = t;
    }

}

void afisare(){
    for (int i = nr_mare[0]; i > 0; i--)
        cout << nr_mare[i];
}

void fact(int n) {
    int cpy;
    for (int j = 2; j <= n; j++){
        for (int i = 0 ; i <= nr_mare[0]; i++)
            toMultp[i] = nr_mare[i];

        cpy = j;
        multiplier[0] = get_nbs(j);
        for (int i = 1; i <= multiplier[0]; i++){
            multiplier[i] = cpy % 10;
            cpy /= 10;
        }

        multp();
    }

    afisare();
}

void solve(int n){
    nr_mare[0] = nr_mare[1] = 1;
    fact(n);
}

int main()
{
    int n;
    cin >> n;
    solve(n);

    return 0;
}
