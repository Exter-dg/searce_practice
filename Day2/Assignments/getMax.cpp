#include <bits/stdc++.h>

using namespace std;

// Using vector - Insertion O(1), Deletion O(1), Max-element O(n)
// Using Single Stack to store max - Insertion O(1), Deletion O(1), Max-element O(1)

// Store max element till position i at inside maxElement[i]
// Insertion - Insert max till now - O(1)
// Deletion - Pop top element - O(1)
// Find max - return top - O(1)
vector<int> getMax(string operations[], int q) {
    stack<int> maxElement;
    vector<int> result;
    int maxSoFar = INT_MIN;

    for (int i = 0; i < q; i++) {
        if (operations[i][0] == '1') {
            // Insert
            maxSoFar = max(maxSoFar, stoi(operations[i].substr(2)));
            maxElement.push(maxSoFar);
        } else if (operations[i][0] == '2') {
            // Delete
            maxElement.pop();
            if (!maxElement.empty())
                maxSoFar = maxElement.top();
            else
                maxSoFar = INT_MIN;
        } else
            result.push_back(maxElement.top());
    }
    return result;
}

int main() {
    int q;
    cin >> q;

    // Discard Input buffer
    string temp;
    getline(cin, temp);

    string operations[q];
    for (int i = 0; i < q; i++)
        getline(cin, operations[i]);

    vector<int> result = getMax(operations, q);

    for (auto a : result)
        cout << a << "\n";

    return 0;
}