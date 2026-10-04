/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int calculateDepth(TreeNode* root){
        if(!root) return 0;

        int leftLength = calculateDepth(root->left);
        if(leftLength == -1) return -1;

        int rightLength = calculateDepth(root->right);
        if(rightLength == -1) return -1;
        
        if(std::abs(leftLength - rightLength) > 1) return -1;

        return 1 + std::max(rightLength, leftLength);
    }
    bool isBalanced(TreeNode* root){
        return (calculateDepth(root) != -1);
    }
};
