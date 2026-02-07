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
    vector<vector<int>> ans;
    void check(TreeNode* root, int targetSum, vector<int>& temp, int sum) {
        if (root == NULL) {
            return;
        }
        if (root->left == NULL && root->right == NULL and
            sum + root->val == targetSum) {
            temp.push_back(root->val);
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        sum += root->val;
        temp.push_back(root->val);
        check(root->left, targetSum, temp, sum);
        check(root->right, targetSum, temp, sum);
        sum -= root->val;
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<int> temp;
        check(root, targetSum, temp, 0);

        return ans;
    }
};