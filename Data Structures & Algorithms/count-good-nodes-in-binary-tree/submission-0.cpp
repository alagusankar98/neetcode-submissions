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
    void countGoodNodes(TreeNode* root, int maxSoFar, int& goodNodeCount){
        if(!root) return;

        if(root->val >= maxSoFar){
            goodNodeCount++;
            maxSoFar = root->val;
        }

        countGoodNodes(root->left, maxSoFar, goodNodeCount);
        countGoodNodes(root->right, maxSoFar, goodNodeCount);
    }
    int goodNodes(TreeNode* root) {
        int goodNodeCount = 0;
        countGoodNodes(root, std::numeric_limits<int>::min(), goodNodeCount);
        return goodNodeCount;
    }
};
