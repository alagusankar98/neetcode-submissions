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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p && q && (p->val > q->val)) return lowestCommonAncestor(root, q, p);
        
        std::stack<TreeNode*> treeStack;
        treeStack.push(root);

        while(!treeStack.empty()){
            auto node = treeStack.top(); treeStack.pop();

            if(node->val >= p->val && node->val <= q->val) return node;

            if(node->val <= p->val){
                // Move to right side (higher  value side)
                if(node->right) treeStack.push(node->right);
            } else {
                // Move to left side (lower value side)
                if(node->left) treeStack.push(node->left);
            }
        }
        return nullptr;
    }
};
