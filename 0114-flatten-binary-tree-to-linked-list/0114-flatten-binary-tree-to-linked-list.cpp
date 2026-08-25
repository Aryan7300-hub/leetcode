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
    void flatten(TreeNode* root) {
        if(!root) return;

        TreeNode* curr = root;

        while(curr){
            if(curr->left){
                TreeNode* temp = curr->right;
                curr->right = curr->left;
                curr->left = NULL;

                TreeNode* rightMost = RightMost(root->right);

                rightMost->right = temp;
            }
            curr = curr->right;
        }
    }
private:
    TreeNode* RightMost(TreeNode* root){
        while(root->right){
            root = root->right;
        }

        return root;
    }
};