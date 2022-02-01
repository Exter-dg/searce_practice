// Leetcode - https://leetcode.com/problems/integer-to-roman

class Solution {
public:
    string intToRoman(int num) {
        // Store values and their corresponding roman representation
        int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        // initialize answer string
        string ans = "";
        int k = 0;

        // iterate while num is non-zero
        while (num) {
            // if num is bigger than current value, subtract current val from it else increment k
            if (num >= values[k]) {
                num -= values[k];
                ans += roman[k];
            } else
                k++;
        }
        return ans;
    }
};