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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> resultVector;
        std::queue<TreeNode*> treeQueue;
        if(root) treeQueue.push(root);
        
        while(!treeQueue.empty()){
            const size_t n = treeQueue.size();
            std::vector<int> levelVector;
            levelVector.reserve(n);

            for(size_t i = 0; i < n; i++){
                auto node = treeQueue.front(); treeQueue.pop();
                levelVector.push_back(node->val);
                if(node->left) treeQueue.push(node->left);
                if(node->right) treeQueue.push(node->right);
            }

            resultVector.push_back(std::move(levelVector));
        }
        return resultVector;
    }
};
