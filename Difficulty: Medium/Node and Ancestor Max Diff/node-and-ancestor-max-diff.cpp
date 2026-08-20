/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
    
    
  public:
  int ans=INT_MIN;
  
  int helper(Node*root){
       if(root==NULL){
            return INT_MAX;
        }
        
        int left=helper(root->left);
        int right=helper(root->right);
        
        int mini=min(left,right);
        if(mini!=INT_MAX){
            ans=max(ans,root->data-mini);
        }
        return min(root->data,mini);
  }
    int maxDiff(Node* root) {
        // code here
       helper(root);
       
       return ans;
    }
};