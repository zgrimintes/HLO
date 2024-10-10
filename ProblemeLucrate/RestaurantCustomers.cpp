#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

pair<int, int> cst[200];
deque< pair<int, int> > d;
int maxAtTime = 0;

void citire(int n) {
    for (int i = 0; i < n; i++)
        cin >> cst[i].first >> cst[i].second;
}

void afisare(int n) {
    for (int i = 0; i < n; i++)
        cout << cst[i].first << cst[i].second;
}

bool ok(pair<int, int> p1, pair<int, int> p2) {
    if (p1.first < p2.first) return 1;

    if (p1.second < p2.second) return 1;

    return 0;
}

void getMax(int n) {
    d.push_front(cst[0]); maxAtTime = 1;
    for (int i = 1; i < n; i++) {
        if (d.front().second >= cst[i].first) { // || d.front().second >= cst[i].second) {
            d.push_back(cst[i]);
            if(d.size() > maxAtTime) maxAtTime = d.size();
        }
        else {
            d.pop_front();
            i--;
        }
    }

}

int main()
{
    int n; cin >> n;
    citire(n);
    sort(cst, cst + n, ok);
    getMax(n);
    cout << maxAtTime;
    return 0;
}


//100 PCT
#include <iostream>
#include <algorithm>

using namespace std;

int cst_in[200000];
int cst_out[200000];
int maxAtTime = 0;

void citire(int n) {
    for (int i = 0; i < n; i++)
        cin >> cst_in[i] >> cst_out[i];
}

void getMax(int n) {
    int i1, i2; i1 = i2 = 0;

    int cntTemp = 0;

    while (i1 < n && i2 < n) {
        if (cst_in[i1] <= cst_out[i2]) cntTemp++, i1++;
        else cntTemp--, i2++;

        if (maxAtTime < cntTemp) maxAtTime = cntTemp;
    }

    while (i1 < n) {
        if (cst_in[i1] <= cst_out[i2 - 1]) cntTemp++, i1++;

        if (maxAtTime < cntTemp) maxAtTime = cntTemp;
    }
}

void sortare(int n) {
    sort(cst_in, cst_in + n);
    sort(cst_out, cst_out + n);

    getMax(n);
}

int main()
{
    int n; cin >> n;
    citire(n);
    sortare(n);


    cout << maxAtTime;
    return 0;
}
