// Leetcode - https://leetcode.com/problems/trapping-rain-water/submissions/

// Using stack - O(n^2)

class Solution {
public:
    int trap(vector<int> &height) {
        vector<int> st;
        int maxSoFar = 0;
        int res = 0;

        int i = 0;
        while (i < height.size() && height[i] == 0)
            i++;

        for (; i < height.size(); i++) {
            if (st.empty()) {
                st.push_back(height[i]);
                maxSoFar = height[i];
            }
            int j = st.size() - 1;
            while (j >= 0 && st[j] < height[i] && st[j] != maxSoFar) {
                res += min(maxSoFar, height[i]) - st[j];
                st[j] = min(maxSoFar, height[i]);
                j--;
            }
            st.push_back(height[i]);
            if (height[i] > maxSoFar)
                maxSoFar = height[i];
        }
        return res;
    }
};

// -------------------------------------------------------------------------------

// Using prefix/suffix Sum - O(n)

class Solution {
public:
    int trap(vector<int> &height) {
        int res = 0;
        int n = height.size();
        int prefix[n];
        int suffix[n];

        prefix[0] = height[0];
        for (int i = 1; i < n; i++)
            prefix[i] = max(prefix[i - 1], height[i]);

        suffix[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
            suffix[i] = max(suffix[i + 1], height[i]);

        for (int i = 0; i < n; i++)
            res += min(prefix[i], suffix[i]) - height[i];

        return res;
    }
};