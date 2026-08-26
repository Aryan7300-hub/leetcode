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
    unordered_map<int, int>mp;
    int postorderIndex;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postorderIndex = postorder.size()-1;

        for(int i = 0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }

        return build(postorder, 0, inorder.size()-1);
    }
private:
    TreeNode* build(vector<int>&postorder, int left, int right){
        if(left>right) return NULL;

        TreeNode* root = new TreeNode(postorder[postorderIndex--]);

        int inorderIndex = mp[root->val];

        root->right = build(postorder, inorderIndex+1, right);
        root->left = build(postorder, left, inorderIndex-1);

        return root;
    }
};