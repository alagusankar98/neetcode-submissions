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
    bool checkTree(TreeNode* node_1, TreeNode* node_2) {
        if(!node_1 && !node_2) return true; // Structural match
        
        if(!node_1 || !node_2) return false; // Structural mismatch

        if(node_1->val != node_2->val) return false; // Value mismatch

        return checkTree(node_1->left, node_2->left) && checkTree(node_1->right, node_2->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(checkTree(root, subRoot)) return true;

        if(!root) return false;
        
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
