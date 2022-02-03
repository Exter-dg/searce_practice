#include <bits/stdc++.h>
#include <ctime>

using namespace std;

int main() {
    long long n = 1000000000;
    int *v = new int[n];
    clock_t start, end;
    start = clock();
    for (long long i = 0; i < n; i++)
        v[i] = 1;
    end = clock();
    cout << "for - CPU time = " << (double)(end - start) / CLOCKS_PER_SEC << endl;

    int *p = v;
    int *pe = p + n;
    start = clock();
    while (p < pe) {
        *p++ = 1;
    }
    end = clock();
    cout << "while - CPU time = " << (double)(end - start) / CLOCKS_PER_SEC << endl;

    return 0;
}