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
    int traversal(TreeNode* root, int& sum) {
        if (root == NULL) {
            return 0;
        }

        int left_sum = max(0,traversal(root->left, sum));
        int right_sum =max(0,traversal(root->right, sum));

        sum = max(sum, left_sum + right_sum+root->val );

        return root->val+max(left_sum, right_sum);
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;

        traversal(root, maxi);

        return maxi;
    }
};