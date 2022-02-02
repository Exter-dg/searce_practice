#include <bits/stdc++.h>

using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

vector<int> findKLargestElements(int a[], int n, int k) {
    priority_queue<int, vector<int>, greater<int>> minh;

    for (int i = 0; i < n; i++) {
        minh.push(a[i]);
        if (minh.size() > k)
            minh.pop();
    }

    vector<int> ans;
    while (!minh.empty()) {
        ans.push_back(minh.top());
        minh.pop();
    }
    return ans;
}

int main() {
    int arr[] = {7, 10, 9, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    int k = 3;

    cout << "Array: \n";
    printArray(arr, n);

    cout << "\nThe k largest elements are: \n";
    vector<int> ans = findKLargestElements(arr, n, k);
    for (auto a : ans)
        cout << a << " ";
    return 0;
}