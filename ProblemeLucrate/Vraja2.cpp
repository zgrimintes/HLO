//100 PUNCTE
#include <iostream>

using namespace std;

int n;
int arr[1000];
int cnt_vraji = 0;

void citire() {
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

int minArr(int l, int r) {
    int m = 1000001;
    for (int i = l; i <= r; i++)
        m = min(m, arr[i]);

    return m;
}

void cutDown(int l, int r, int m) {
    for (int i = l; i <= r; i++)
        arr[i] -= m;
}

void vraja(int l, int r) {
    if (l > r) return;

    cnt_vraji++;
    int pozMin[1000];
    for (int i = 0; i < 1000; i++) pozMin[i] = 0;

    int m = minArr(l, r);
    cutDown(l, r, m);

    int indMin = 0;

    for (int i = l; i <= r; i++) {if (!arr[i]) {pozMin[indMin++] = i;}}

    if (l == r) return;

    int lt = l;
    for (int i = 0; i < indMin; i++) {
        vraja(lt, pozMin[i] - 1);

        lt = pozMin[i] + 1;
    }

    vraja(lt, r);
}

int main()
{
    cin >> n;
    citire();
    vraja(0, n - 1);
    cout << cnt_vraji;
    return 0;
}
