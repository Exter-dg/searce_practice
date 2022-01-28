// Leetcode - https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0, start = 0, end = 0;
        bool a[128];
        for (auto i = 0; i < 128; i++)
            a[i] = false;
        for (int i = 0; i < s.length(); i++) {
            if (!a[s[i]]) {
                a[s[i]] = true;
            } else {
                len = max(len, end - start);
                // cout<<end<<" "<<start<<endl;

                while (a[s[i]]) {
                    a[s[start]] = false;
                    start++;
                }
                a[s[i]] = true;
            }
            end++;
        }
        len = max(len, end - start);
        return len;
    }
};