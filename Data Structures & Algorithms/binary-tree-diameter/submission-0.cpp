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
    int calculateDiameter(TreeNode* root, int& maxDiameter){
        if(!root) return 0;

        int leftLength = calculateDiameter(root->left, maxDiameter);
        int rightLength = calculateDiameter(root->right, maxDiameter);
        maxDiameter = std::max(maxDiameter, (leftLength + rightLength));

        return 1 + std::max(leftLength, rightLength);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = std::numeric_limits<int>::min();
        calculateDiameter(root, maxDiameter);
        return maxDiameter;
    }
};
