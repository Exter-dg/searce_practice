// Leetcode - https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/

class Solution {
public:
    int pairSum(ListNode* head) {
        stack<int> st;
        ListNode* curr = head;
        while(curr!=NULL) {
            st.push(curr->val);
            curr = curr->next;
        }
        
        curr = head;
        int n = st.size();
        int sum = 0;
        
        for(int i=0;i<n/2 ; i++) {
            sum = max(sum, curr->val + st.top());
            curr = curr->next;
            st.pop();
        }
        return sum;
    }
};