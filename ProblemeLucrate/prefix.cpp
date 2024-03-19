//REZOLVARE DE 100 DE PUNCTE
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("prefix.in");
ofstream fout("prefix.out");

char s[10][1000005] = {0};
int p[10][1000005] = {0};

void make_pref(int ind) {
    int i = 0, j = -1;
    p[ind][0] = -1;
    int len = strlen(s[ind]);

    while (i < len) {
        while (j >= 0 && s[ind][i] != s[ind][j])
            j = p[ind][j];

        j++;
        i++;
        p[ind][i] = j;
    }
}

void find_longest_pref(int ind) {
    int longest_pref = 0;
    int len = strlen(s[ind]);
    for (int i = 0; i <= len; i++) {
        if (i % (i - p[ind][i]) == 0 && p[ind][i] != 0) {
            if (longest_pref < i)
                longest_pref = i;
        }
    }

    fout << longest_pref << "\n";
}

int main()
{
    int n, index = 0;
    fin >> n;
    fin.get();

    while (n) {
        fin.getline(s[index], 1000005);
        make_pref(index);
        find_longest_pref(index);

        index++;
        n--;
    }
    return 0;
}
