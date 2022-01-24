#include <bits/stdc++.h>

using namespace std;

bool binarySearch(int a[], int n, int elem) {
    int start = 0, end = n - 1, mid;

    while (start <= end) {
        mid = start + (end - start) / 2;
        if (a[mid] == elem)
            return true;
        else if (a[mid] < elem)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return false;
}

int main() {
    int n = 8;
    int a[8] = {1,2,3,4,5,6,7,8};
    cout << binarySearch(a, n, 8) << "\n";
    cout << binarySearch(a, n, 9);
    return 0;
}