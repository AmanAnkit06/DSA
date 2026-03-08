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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = 0, *temp = 0;
        while (list1 != 0 || list2 != 0) {
            if (list1 != 0 && list2 != 0) {
                if (list1->val <= list2->val) {
                    ListNode* newnode = new ListNode(list1->val);
                    list1 = list1->next;
                    if (head == 0) {
                        head = newnode;
                        temp = newnode;
                    } else {
                        temp->next = newnode;
                        temp = newnode;
                    }
                } else {
                    ListNode* newnode = new ListNode(list2->val);
                    list2 = list2->next;
                    if (head == 0) {
                        head = newnode;
                        temp = newnode;
                    } else {
                        temp->next = newnode;
                        temp = newnode;
                    }
                }
            }

            else if (list1 != 0) {
                ListNode* newnode = new ListNode(list1->val);
                list1 = list1->next;
                if (head == 0) {
                    head = newnode;
                    temp = newnode;
                } else {
                    temp->next = newnode;
                    temp = newnode;
                }
            } else if (list2 != 0) {
                ListNode* newnode = new ListNode(list2->val);
                list2 = list2->next;
                if (head == 0) {
                    head = newnode;
                    temp = newnode;
                } else {
                    temp->next = newnode;
                    temp = newnode;
                }
            }
        }

        return head;
    }
};