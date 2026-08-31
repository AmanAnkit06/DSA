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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<pair<int, int>> p;

        ListNode* prev = 0;
        ListNode* curr = head;
        int i = 1;
        vector<int> ans(2, -1);
        while (curr->next != NULL) {

            if (prev != NULL) {
                if (curr->val > prev->val && curr->val > curr->next->val) {
                    p.push_back({i, curr->val});

                } else if (curr->val < prev->val &&
                           curr->val < curr->next->val) {
                    p.push_back({i, curr->val});
                }
            }

            i++;
            prev = curr;
            curr = curr->next;
        }

        if (p.size() >= 2) {
            int n = p.size();
            int max = p[n - 1].first - p[0].first;
            int m = INT_MAX;
            for (int i = 1; i < n; i++) {
                m = min(m, p[i].first - p[i - 1].first);
            }
            ans[0] = m;
            ans[1] = max;
        }
        return ans;
    }
};