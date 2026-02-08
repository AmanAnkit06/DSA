/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = NULL;
        ListNode* temp;
        int carry = 0;
        while (l1 && l2) {
            int sum = carry + l1->val + l2->val;
            carry = sum / 10;
            ListNode* newnode = new ListNode(sum % 10);
            if (ans == NULL) {
                ans = newnode;
                temp = newnode;
            } else {
                temp->next = newnode;
                temp = newnode;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1) {
            int sum = carry + l1->val;
            carry = sum / 10;
            ListNode* newnode = new ListNode(sum % 10);
            if (ans == NULL) {
                ans = newnode;
                temp = newnode;
            } else {
                temp->next = newnode;
                temp = newnode;
            }
            l1 = l1->next;
        }
        while (l2) {
            int sum = carry + l2->val;
            carry = sum / 10;
            ListNode* newnode = new ListNode(sum % 10);
            if (ans == NULL) {
                ans = newnode;
                temp = newnode;
            } else {
                temp->next = newnode;
                temp = newnode;
            }
            l2 = l2->next;
        }
        if (carry != 0) {
            ListNode* newnode = new ListNode(carry);
            if (ans == NULL) {
                ans = newnode;
                temp = newnode;
            } else {
                temp->next = newnode;
                temp = newnode;
            }
        }
        return ans;
    }
};