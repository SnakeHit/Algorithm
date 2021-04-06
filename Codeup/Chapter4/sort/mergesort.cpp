#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
int arr[N];
int temp[N];
void mergesort(int *arr, int l, int r) {
    if (l >= r) return;
    int mid = l + (r - l) / 2;
    mergesort(arr, l, mid);
    mergesort(arr, mid + 1, r);
    int i = l, j = mid + 1;
    int k = l;
    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    while (i == mid + 1 && j <= r) temp[k++] = arr[j++];
    while (i <= mid && j == r + 1) temp[k++] = arr[i++];
    for (int i = l; i <= r; i++) {
        arr[i] = temp[i];
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    mergesort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}