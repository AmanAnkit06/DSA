/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int bfs(TreeNode* root) {
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        long long maxi = 0;
        while (!q.empty()) {
            int size = q.size();
            long long x = 0;
            long long y = 0;
            long long min = q.front().second;
            for (int i = 0; i < size; i++) {

                TreeNode* temp = q.front().first;
                long long idx = q.front().second;
                idx -= min;
                q.pop();
                if (i == 0) {
                    x = idx;
                }
                if (i == size - 1) {
                    y = idx;
                }
                if (temp->left) {
                    q.push({temp->left, 2 * idx + 1});
                }
                if (temp->right) {
                    q.push({temp->right, 2 * idx + 2});
                }
                
            }

            maxi = max(maxi, y - x + 1);
        }
        return (int)maxi;
    }
    int widthOfBinaryTree(TreeNode* root) { return bfs(root); }
};