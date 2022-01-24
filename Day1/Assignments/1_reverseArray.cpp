#include <bits/stdc++.h>

using namespace std;

/*
 * void as array is passed by reference in c++.
 * Using two pointers - start , end.
 * Swap numbers from the front and rear until the pointers reach
 * the middle of the list.
 */
void reverseArray(int a[], int size) {
    int start = 0;
    int end = size - 1;
    while (start < end) {
        swap(a[start++], a[end--]);
    }
}

void printArray(int a[], int size) {
    cout << "\nArray: ";
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
}

int main() {
    int size;
    cin >> size;
    int a[size];
    for (int i = 0; i < size; i++)
        cin >> a[i];
    reverseArray(a, size);
    printArray(a, size);
    return 0;
}