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
    void calculateDepth(TreeNode* root, int depth, std::vector<int>& resultVector){
        if(!root) return;

        if(resultVector.size() == depth){
            resultVector.push_back(root->val);
        }

        // Going one level deep, prioritize right side
        calculateDepth(root->right, depth + 1, resultVector);
        calculateDepth(root->left, depth + 1, resultVector);
    }
    std::vector<int> rightSideView(TreeNode* root) {
        std::vector<int> resultVector;
        calculateDepth(root, 0, resultVector);
        return resultVector;
    }
};
