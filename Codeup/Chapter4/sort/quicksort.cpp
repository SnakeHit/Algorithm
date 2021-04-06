#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
int arr[N];

int three_swap(int *arr, int l, int r) {
    int mid = l + (r - l) / 2;
    if (arr[l] > arr[mid]) swap(arr[l], arr[mid]);
    if (arr[mid] > arr[r]) swap(arr[mid], arr[r]);
    if (arr[l] > arr[mid]) swap(arr[l], arr[mid]);
    return arr[mid];
}

void quicksort(int *arr ,int l, int r) {
    if (r - l <= 2) {
        three_swap(arr, l, r);
        return ;
    }
    int i = l - 1, j = r + 1, k = three_swap(arr, l, r);
    while (i < j) {
        while (arr[++i] < k) ;
        while (arr[--j] > k) ;
        if (i < j) swap(arr[i], arr[j]); 
    }
    quicksort(arr, l, j);
    quicksort(arr, j+1, r);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    quicksort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}