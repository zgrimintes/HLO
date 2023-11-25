//REZOLVARE DE 60 DE PUNCTE - NU FOLOSI STRTOK!
#include <iostream>
#include <cstring>

using namespace std;

char d[100][100];
int n, cuv_max = 0;

void revert(char *c) {
    int n = strlen(c);

    for (int i = 0; i < n / 2; i++){
        c[i] = c[i] ^ c[n - i - 1];
        c[n - i - 1] = c[i] ^ c[n - i - 1];
        c[i] = c[i] ^ c[n - i - 1];
    }
}

void afisare(int n) {
    for (int i = 0; i < n; i++) {
        cout << d[i] << " ";
    }
}

bool valid(char *c) {
    bool ok = false;

    for (int i = 0; i < strlen(c); i++)
        if (isalpha(c[i])) ok = true;

    return ok;
}

int main()
{
    char s[256];
    cin.getline(s, 256);

    char *p = strtok(s, " ");

    while (p) {
        strcpy(d[n++], p);

        if (cuv_max < strlen(d[n-1]))
            cuv_max = strlen(d[n-1]);

        p = strtok(NULL, " ");
    }

    for (int i = 0; i < n; i++) {
        if (cuv_max == strlen(d[i]) && valid(d[i])) {
            revert(d[i]);
        }
    }

    afisare(n);

    return 0;
}
