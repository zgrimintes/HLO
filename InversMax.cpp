//REZOLVARE DE 80 DE PUNCTE
#include <iostream>
#include <cstring>

using namespace std;

void revert(char* c) {
    int n = strlen(c);

    for (int i = 0; i < n / 2; i++) {
        c[i] = c[i] ^ c[n - i - 1];
        c[n - i - 1] = c[i] ^ c[n - i - 1];
        c[i] = c[i] ^ c[n - i - 1];
    }
}

bool valid(char* c, int s, int f) {
    for (s; s < f; s++)
        if (isalpha(c[s])) return true;

    return false;
}

void copiere(char *s, char *c, int st, int f) {
    for (; st < f; st++) {
        c[st] = s[st];
    }
}

int main()
{
    char s[256];
    cin.getline(s, 256);
    int cuv_max = 0, index_s = 0, cnt_max = 0;

    while (index_s < strlen(s)) {
        if (s[index_s] == ' ') {
            if (cnt_max > cuv_max) cuv_max = cnt_max;
            cnt_max = 0;
        }
        else
            cnt_max++;

        index_s++;
    }

    if (cuv_max < cnt_max) cuv_max = cnt_max;

    int last_w = 0;
    char ss[256] = { 0 };
    for (index_s = 0; index_s <= strlen(s); index_s++) {
        if (s[index_s] != ' ' && s[index_s] != '\0') continue;

        if (index_s - last_w == cuv_max) {
            copiere(s, ss, last_w, index_s);

            if (valid(ss, last_w, index_s)) {
                int offset = 1;
                for (; last_w < index_s; last_w++) {
                    s[last_w] = ss[index_s - offset++];
                }
            }
        }

        last_w = index_s + 1;
    }

    cout << s;

    return 0;
}
