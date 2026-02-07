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
    int cnt = 0;
    typedef long long ll;
    void check(TreeNode* root, ll targetSum, ll sum) {
        if (root == NULL) {
            return;
        }
        sum += root->val;
        if (sum == targetSum) {
            cnt++;
        }

        check(root->left, targetSum, sum);
        check(root->right, targetSum, sum);
    }
    void preOrder(TreeNode* root, int targetSum) {
        if (root == NULL) {
            return;
        }
        check(root, targetSum, 0);

        preOrder(root->left, targetSum);
        preOrder(root->right, targetSum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        preOrder(root, targetSum);

        return cnt;
    }
};