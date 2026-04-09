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
        ListNode *crtNode = head, *prevNode = 0, *nextNode = 0;
        while (crtNode) {
            nextNode = crtNode->next;
            crtNode->next = prevNode;
            prevNode = crtNode;
            crtNode = nextNode;
        }

        return prevNode;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* temp = reverse(head);
        ListNode* tail = temp;
        if (n == 1) {
            tail = tail->next;
            return reverse(tail);
        }
        int cnt = 1;
        while (temp != NULL && cnt < n - 1) {
            temp = temp->next;
            cnt++;
        }

        if (temp->next->next == 0) {
            temp->next = 0;
        }

        else {
            temp->next = temp->next->next;
        }

        return reverse(tail);
    }
};