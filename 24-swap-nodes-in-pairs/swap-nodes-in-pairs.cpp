class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;
        ListNode* curr = head;

        while (curr && curr->next) {
            ListNode* next = curr->next;

            // swap
            curr->next = next->next;
            next->next = curr;
            prev->next = next;

            // move pointers
            prev = curr;
            curr = curr->next;
        }

        return dummy.next;
    }
};
