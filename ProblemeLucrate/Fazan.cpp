#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

char cuvs[100][100];
int ok[100], x[100];
int faz_max[100], ind;
int n, ind_c;

bool valid(int k) {
    char temp[100] = "";

    strcpy(temp, cuvs[x[0]]);

    for (int i = 1; i < k; i++) {
        int lentemp = strlen(temp);

        if (temp[lentemp - 1] != cuvs[x[i]][1]) return false;
        if (temp[lentemp - 2] != cuvs[x[i]][0]) return false;
    }

    return true;
}

void backt(int k) {
    if (k >= 2) {
        if (valid(k)) {
            for (int i = 0; i < k; i++) faz_max[i] = x[i];
            ind = k;
        }
    }

    for (int i = 0; i < n; i++) {
        if (ok[i]) continue;

        ok[i] = true;
        x[k] = i;

        backt(k + 1);

        ok[i] = false;
    }
}

void citire()
{
    char temp[1000];
    cin.get();
    cin.getline(temp, 100);

    char* p = strtok(temp, " ");

    while (p != NULL)
    {
        strcpy(cuvs[ind_c], p);
        ind_c++;
        p = strtok(NULL, " ");
    }
}

void afisare() {
    for (int i = 0; i < ind; i++)
        cout << cuvs[faz_max[i]] << " ";
}

int main()
{
    cin >> n;
    citire();

    backt(0);

    afisare();
    return 0;
}
