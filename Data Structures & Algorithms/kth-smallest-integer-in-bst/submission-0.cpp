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
    // void getKthNode(TreeNode* root){
    //     if(!root) return;

    //     getKthNode(root->left);

    //     std::cout << root->val << " ";

    //     getKthNode(root->right);
    // }

    // int kthSmallest(TreeNode* root, int k) {
    //     TreeNode* kthNode = nullptr;
    //     getKthNode(root);
    //     return -1;
    // }

    int kthSmallest(TreeNode* root, int k) {
        std::stack<TreeNode*> treeStack;
        int i = 0;

        TreeNode* current = root;

        while(current || !treeStack.empty()){

            while(current){
                treeStack.push(current); // All left nodes pushed to stack
                current = current->left;
            }

            auto node = treeStack.top(); treeStack.pop(); // Last left node

            i++;
            if(i == k) return node->val;

            current = node->right;
        }
        
        return -1;
    }
};
