#include <bits/stdc++.h>

using namespace std;

void merge_arrays(int a[], int start, int mid, int end) {
    int n = end - start + 1;
    int temp[n];

    int i = start, j = mid + 1, k = 0;
    while (i <= mid && j <= end) {
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= mid)
        temp[k++] = a[i++];

    while (j <= end)
        temp[k++] = a[j++];

    for (int z = start; z <= end; z++) {
        a[z] = temp[z - start];
    }
}

void merge_sort(int a[], int start, int end) {
    if (start < end) {
        int mid = start - (start - end) / 2;
        merge_sort(a, start, mid);
        merge_sort(a, mid + 1, end);
        merge_arrays(a, start, mid, end);
    }
}

void print_array(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}

int main() {
    cout << "\nEnter the size of the array: ";
    int n;
    cin >> n;
    int a[n];
    cout << "\nEnter the array elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    merge_sort(a, 0, n - 1);

    cout << "\nThe sorted array is: ";
    print_array(a, n);

    return 0;
}