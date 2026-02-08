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
    ListNode* rev(ListNode* head) {
        ListNode *prev, *curr, *next;
        curr = head;
        prev = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* r = rev(head);

        ListNode* temp = r;

        if (n == 1) {
            ListNode* del = temp;
            r = r->next;
            delete del;
            return rev(r);
        }

        int i = 1;
        while (temp && i < n - 1) {
            i++;
            temp = temp->next;
        }

        if (temp && temp->next) {
            ListNode* del = temp->next;
            temp->next = del->next;
            delete del;
        }
        return rev(r);
    }
};