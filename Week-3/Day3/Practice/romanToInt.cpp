class Solution {
public:
    int romanToInt(string s) {
        // Store values and their corresponding roman representation
        unordered_map<char, int> roman;
        roman['M'] = 1000;
        roman['D'] = 500;
        roman['C'] = 100;
        roman['L'] = 50;
        roman['X'] = 10;
        roman['V'] = 5;
        roman['I'] = 1;

        int ans = 0;
        int k = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            // check for edge - case
            // if two or more characters are left and
            // the next roman Number is smaller than the current
            // Cases - IV, IX, XL, XC, CD, CM
            if (i < n - 1 && roman[s[i]] < roman[s[i + 1]]) {
                ans += roman[s[i + 1]] - roman[s[i]];
                i++;
            } else {
                ans += roman[s[i]];
            }
        }
        return ans;
    }
};