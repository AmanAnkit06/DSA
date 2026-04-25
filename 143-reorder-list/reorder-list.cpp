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
    ListNode* reverse(ListNode* head) {
        ListNode *prev = NULL, *curr = head, *next;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
    void reorderList(ListNode* head) {

        if (!head || !head->next)
            return;

        ListNode *slow = head, *fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* rev = reverse(slow);

        ListNode* temp = head;
        ListNode* tail = rev;

        while (temp && tail) {

            ListNode* revtemp = tail->next;
            ListNode* currtemp = temp->next;

            temp->next = tail;
            tail->next = currtemp;

            temp = currtemp;
            tail = revtemp;
        }
    }
};