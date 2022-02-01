// https://leetcode.com/problems/merge-two-sorted-lists/

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode *head = new ListNode();
        ListNode *temp = head;

        while (list1 && list2) {
            if (list1->val > list2->val) {
                ListNode *t = new ListNode(list2->val);
                temp->next = t;
                temp = t;
                list2 = list2->next;
            } else {
                ListNode *t = new ListNode(list1->val);
                temp->next = t;
                temp = t;
                list1 = list1->next;
            }
        }

        while (list1) {
            ListNode *t = new ListNode(list1->val);
            temp->next = t;
            temp = t;
            list1 = list1->next;
        }

        while (list2) {
            ListNode *t = new ListNode(list2->val);
            temp->next = t;
            temp = t;
            list2 = list2->next;
        }

        head = head->next;
        return head;
    }
};