///REZOLVAREA UNEI PROBLEME CARE CERE PRETUL OPTIM PENTRU O SFOARA CARE POATE FI TAIATA IN BUCATI DE ORICE LUNGIME,
///FIECARE LUNGIME AVAND PRETUL EI SPECIFIC
#include <iostream>
#include <vector>

using namespace std;

int n;
int opt[1005];
int pret[1005];
vector<int> sol;

void citPret(){
    for (int i = 1; i <= n; i++)
        cin >> pret[i]; ///opt[i] = pret[i];
}

int solve_bottom_up(){
    sol.resize(n);

    for (int i = 1; i <= n; i++) {
        ///Prefer sa folosesc varianta soranei fata de a mea deoarece e mai usoara apoi contructia solutiei
        int opt_v = INT_MIN;
        for (int j = 1; j <= i; j++){
            //opt_v = max(opt_v, pret[j] + opt[i - j]);
            if (opt_v < pret[j] + opt[i - j]){
                opt_v = pret[j] + opt[i - j];
                sol[i] = j;
            }
        }

            ///opt[i] = max(opt[i], opt[j] + opt[i - j]);
        opt[i] = opt_v;
    }

    return opt[n];
}

int main()
{
    cin >> n;
    citPret();

    cout << solve_bottom_up() << "\n";

    int bara = n;
    while (bara > 0) {
        cout << sol[bara] << " ";
        bara -= sol[bara];
    }

    return 0;
}
