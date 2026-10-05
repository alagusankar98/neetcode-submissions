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
    bool checkBST(TreeNode* root, TreeNode* floorNode, TreeNode* ceilingNode){
        if(!root) return true;

        if((floorNode && root->val <= floorNode->val) || (ceilingNode && root->val >= ceilingNode->val)) return false;

        return checkBST(root->left, floorNode, root) && checkBST(root->right, root, ceilingNode);
    }
    bool isValidBST(TreeNode* root) {
        return checkBST(root, nullptr, nullptr);
    }
};
