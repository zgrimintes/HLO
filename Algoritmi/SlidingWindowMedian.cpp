#include <iostream>
#include <set>
#define LL long long

using namespace std;

LL n, k;
LL arr[200010];
multiset<LL> low;
multiset<LL> up;

void insert_to_set(LL val) {
    LL temp = *low.rbegin();

    if (temp < val) {
        up.insert(val);
        if (up.size() > k / 2) {
            low.insert(*up.begin());
            up.erase(up.find(*up.begin()));
        }
    }
    else {
        low.insert(val);
        if (low.size() > (k + 1) / 2) {
            up.insert(*low.rbegin());
            low.erase(low.find(*low.rbegin()));
        }
    }
}

void erase_from_set(LL val) {
    if (up.find(val) != up.end())
        up.erase(up.find(val));
    else
        low.erase(low.find(val));

    if (low.empty()) {
        low.insert(*up.begin());
        up.erase(up.find(*up.begin()));
    }
}

void citire(int n) {
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

int main()
{
    cin >> n >> k;
    citire(n);
    low.insert(arr[0]);

    for (int i = 1; i < k; i++) {
        insert_to_set(arr[i]);
    }

    cout << *low.rbegin() << " ";

    for (int i = k; i < n; i++) {
        if (k == 1) {
            insert_to_set(arr[i]);
            erase_from_set(arr[i - k]);
        }
        else {
            erase_from_set(arr[i - k]);
            insert_to_set(arr[i]);
        }

        cout << *low.rbegin() << " ";
    }

    return 0;
}
