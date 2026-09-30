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
    TreeNode* invertTree(TreeNode* root) {
    if(!root) return nullptr; // Empty tree

    std::stack<TreeNode*> treeStack;
    treeStack.push(root);

    while(!treeStack.empty()){
        TreeNode* node = treeStack.top();
        treeStack.pop();

        std::swap(node->left, node->right);

        if(node->left) treeStack.push(node->left);
        if(node->right) treeStack.push(node->right);
    }

    return root;
}
};
