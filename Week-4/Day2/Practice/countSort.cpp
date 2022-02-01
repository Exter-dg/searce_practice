#include <bits/stdc++.h>

using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

void countSort(int arr[], int n) {
    int k = INT_MIN;
    int temp[n];

    // find the max element in the array
    for (int i = 0; i < n; i++)
        if (arr[i] > k)
            k = arr[i];

    int count[k + 1] = {0};

    // find number of occurrences of each key
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    // find the last position of every element
    for (int i = 1; i < k + 1; i++)
        count[i] += count[i - 1];

    // start the traversal from end to maintain the stability of the sorting algorithm
    for (int i = n - 1; i >= 0; i--) {
        count[arr[i]]--;
        temp[count[arr[i]]] = arr[i];
    }

    // copy elements from the temp array to the original array
    for (int i = 0; i < n; i++)
        arr[i] = temp[i];
}

int main() {
    int arr[] = {0, 1, 0, 9, 7, 8, 4, 6, 1, 0, 3, 3, 8, 8, 9, 0, 11, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array: \n";
    printArray(arr, n);

    countSort(arr, n);

    cout << "\nArray after sort: \n";
    printArray(arr, n);

    return 0;
}