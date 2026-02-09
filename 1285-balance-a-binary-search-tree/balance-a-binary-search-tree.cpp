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
    vector<int> arr;
    void inOrder(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        inOrder(root->left);
        arr.push_back(root->val);
        inOrder(root->right);
    }

    TreeNode* construct_BST(int start, int end) {

        if (start > end) {
            return nullptr;
        }

        int mid = (start + end) / 2;

        TreeNode* root = new TreeNode(arr[mid]);
        root->left = construct_BST(start, mid - 1);
        root->right = construct_BST(mid + 1, end);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        inOrder(root);

        return construct_BST(0, arr.size() - 1);
    }
};