#include <bits/stdc++.h>

using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int findKthSmallest(int a[], int n, int k) {
    priority_queue<int> maxh;

    for (int i = 0; i < n; i++) {
        maxh.push(a[i]);
        if (maxh.size() > k)
            maxh.pop();
    }
    return maxh.top();
}

int main() {
    int arr[] = {7, 10, 9, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    int k = 3;

    cout << "Array: \n";
    printArray(arr, n);

    cout << "\nThe kth smallest element is: " << findKthSmallest(arr, n, k);

    return 0;
}