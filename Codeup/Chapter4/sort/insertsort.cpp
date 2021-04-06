#include<iostream>
#include<vector>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    vector<int> arr {4,3,2,5,9,8,7,0,1,6};
    // 2, 3, 4, 5, 9, 8, 7, 0, 1, 6
    //             *  *
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = i; j > 0; j--) {
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