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
    unordered_map<int,int>mp;
    int preorderIndex = 0;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        for(int i = 0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        
        return build(preorder, 0, inorder.size()-1);
    }
private:
    TreeNode* build(vector<int>&preorder, int left, int right){
        if(left > right) return NULL;

        TreeNode* root = new TreeNode(preorder[preorderIndex++]);

        int inorderIndex = mp[root->val];

        root->left = build(preorder, left, inorderIndex-1);
        root->right = build(preorder, inorderIndex+1,right);

        return root;
    }
};