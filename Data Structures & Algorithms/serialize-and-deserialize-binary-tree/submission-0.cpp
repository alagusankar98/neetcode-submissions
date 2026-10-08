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

class Codec {
public:

    // Preorder traversal
    void serializeString(TreeNode* root, std::string& resultString){
        if(!root){
            resultString.append("#,");
            return;
        }
        resultString.append(std::to_string(root->val) + ",");
        serializeString(root->left, resultString);
        serializeString(root->right, resultString);
    }

    // std::string serializeString(TreeNode* root){
    //     if(!root) return "#";
        
    //     return std::to_string(root->val) + "," + serializeString(root->left) + "," + serializeString(root->right);
    // }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        std::string serializedTreeString = "";
        // std::stack<TreeNode*> treeStack;
        // if(root) treeStack.push(root);

        // while(!treeStack.empty()){
        //     auto node = treeStack.top(); treeStack.pop();

        //     while(node){
        //         if(node->left) treeStack.push(node->left);
        //         node = node->left;
        //     }
        // }
        serializeString(root, serializedTreeString);
        std::cout << serializedTreeString;

        return serializedTreeString;
    }

    TreeNode* constructTree(std::string_view data, size_t& currentPos){
        if(data[currentPos] == '#'){
            currentPos += 2;
            return nullptr;
        }

        // Get node value
        int nodeVal = 0;
        auto [nonNumberPos, _] = std::from_chars(data.data() + currentPos, data.data() + data.size(), nodeVal);
        currentPos = (nonNumberPos - data.data()) + 1;
        auto node = new TreeNode(nodeVal);

        node->left = constructTree(data, currentPos);
        node->right = constructTree(data, currentPos);

        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        size_t currentPos = 0;
        return constructTree(data, currentPos);
    }
};
