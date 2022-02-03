#include <bits/stdc++.h>

using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

void heapify(int a[], int n, int i) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;

    if (l < n && a[l] > a[largest])
        largest = l;
    if (r < n && a[r] > a[largest])
        largest = r;

    if (largest != i) {
        swap(a[largest], a[i]);
        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n) {
    // heapify all non-leaf nodes
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    // we have a max heap now
    for (int i = n - 1; i > 0; i--) {
        // put max node in its position
        swap(a[0], a[i]);
        // heapify the root node
        heapify(a, i, 0);
    }
}

int main() {
    int arr[] = {7, 10, 9, 3, 20, 15, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "\nArray: \n";
    printArray(arr, n);

    heapSort(arr, n);

    cout << "\nArray after Sorting: \n";
    printArray(arr, n);

    return 0;
}