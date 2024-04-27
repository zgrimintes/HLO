#include <iostream>

using namespace std;

void afisare(int* v, int n) {
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";

    cout << "\n";
}

void bkt(int n, int k, int *v, bool *used) {
    if (k == n) {
        afisare(v, n);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (used[i]) continue;

        used[i] = true;
        v[k] = i + 1;
        bkt(n, k + 1, v, used);
        used[i] = false;
        v[k] = 0;
    }

}

int main()
{
    int sir[100] = { 0 };
    bool verif[100] = { 0 };
    int n;
    cin >> n;
    bkt(n, 0, sir, verif);
    return 0;
}

///varianta cu std::vector
#include <iostream>
#include <vector>

using namespace std;

void afisare(vector<int> v) {
    int n = v.size();
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";

    cout << "\n";
}

void bkt(int n, int k, vector<int> v, bool *used) {
    if (k == n) {
        afisare(v);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (used[i]) continue;

        used[i] = true;
        v.push_back(i + 1); //v[k] = i + 1;
        bkt(n, k + 1, v, used);
        used[i] = false;
        v.pop_back(); //v[k] = 0;
    }

}

int main()
{
    vector<int> sir;
    bool verif[100] = { 0 };
    int n;
    cin >> n;
    bkt(n, 0, sir, verif);
    return 0;
}
