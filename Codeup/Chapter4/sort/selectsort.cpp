#include<iostream>
#include<vector>
using namespace std;
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
int main() {
    vector<int> arr{4, 2, 3, 5, 9, 7, 6, 1, 0};
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        int min = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min])
                min = j;
        }
        swap(arr[i], arr[min]);
    }

    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}