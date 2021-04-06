#include<iostream>
#include<vector>
using namespace std;
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    vector<int> arr{4,2,3,5,9,7,6,1,0};
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n - i; j++) {
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
            }
        }
    }
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}