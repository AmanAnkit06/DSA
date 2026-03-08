/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode *curr = head, *next = head;
        while (curr != 0 && curr->next != 0) {
            curr = curr->next->next;
            next = next->next;
            if (curr == next) {
                return true;
            }
        }
        return false;
    }
};