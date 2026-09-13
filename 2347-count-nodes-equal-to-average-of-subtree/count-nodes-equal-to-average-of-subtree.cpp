class Solution {
public:
    int ans = 0;

    pair<int, int> preorder(TreeNode* root) {
        if (root == NULL) {
            return {0, 0};
        }

        auto left = preorder(root->left);
        auto right = preorder(root->right);

        int sum = root->val + left.first + right.first;
        int cnt = 1 + left.second + right.second;

        if (sum / cnt == root->val) {
            ans++;
        }

        return {sum, cnt};
    }

    int averageOfSubtree(TreeNode* root) {
        preorder(root);
        return ans;
    }
};