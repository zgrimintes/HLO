#include <iostream>

using namespace std;

void citire(int *arr, int n) {
    for (int i = 0; i < n; i++)
        cin >> arr[n];
}

void mergeArr(int *arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int arrL[100], arrR[100];

    for (int i = 0; i < n1; i++) {
        arrL[i] = arr[l + i];
    }

    for (int i = 0; i < n2; i++) {
        arrR[i] = arr[m + 1 + i];
    }

    int i = 0, j = 0, indArr = l;

    while (i < n1 && j < n2) {
        if (arrL[i] < arrR[j])
            arr[indArr++] = arrL[i++];
        else
            arr[indArr++] = arrR[j++];
    }

    while (i < n1) arr[indArr++] = arrL[i++];

    while (j < n2) arr[indArr++] = arrR[j++];
}

void mergeSort(int *arr, int l, int r) {
    while (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        mergeArr(arr, l, m, r);
    }
}

void afisare(int *arr, int n) {
    for (int i = 0; i < n; i++)
        cout << arr[n];
}

int main() {
    int arr[100];
    int n; cin >> n;
    citire(arr, n);

    mergeSort(arr, 0, n);

    return 0;
}
