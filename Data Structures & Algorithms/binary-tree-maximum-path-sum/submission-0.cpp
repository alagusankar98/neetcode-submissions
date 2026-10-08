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
    int calculateMaxSum(TreeNode* root, int& maxSum){
        if(!root) return 0;

        int leftMax = std::max(0, calculateMaxSum(root->left, maxSum));
        int rightMax = std::max(0, calculateMaxSum(root->right, maxSum));

        maxSum = std::max(maxSum, (root->val + leftMax + rightMax));

        return root->val + std::max(leftMax, rightMax);
    }

    int maxPathSum(TreeNode* root) {
        int maxSum = std::numeric_limits<int>::min();
        calculateMaxSum(root, maxSum);
        return maxSum;
    }
};
