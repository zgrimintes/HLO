///REZOLVAREA UNEI PROBLEME CARE CERE PRETUL OPTIM PENTRU O SFOARA CARE POATE FI TAIATA IN BUCATI DE ORICE LUNGIME, 
///FIECARE LUNGIME AVAND PRETUL EI SPECIFIC
#include <iostream>

using namespace std;

int n;
int opt[1005];
int pret[1005];

void citPret(){
    for (int i = 1; i <= n; i++)
        cin >> pret[i], opt[i] = pret[i];
}

int solve_bottom_up(){
    for (int i = 2; i <= n; i++) {
        ///int opt_v = INT_MIN;
        for (int j = 1; j <= i; j++)
            opt[i] = max(opt[i], opt[j] + opt[i - j]);
            ///opt_v = max(opt_v, pret[i] + opt[j - i])
        ///opt[i] = opt_v;
    }
    
    return opt[n];
}

int main()
{
    cin >> n;
    citPret();

    cout << solve_bottom_up();
    return 0;
}
