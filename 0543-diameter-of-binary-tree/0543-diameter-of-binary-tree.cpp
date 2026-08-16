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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            int left = height(node->left);
            int right = height(node->right);
            diameter = max(diameter, left+ right);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }

        return diameter;
    }
private:
    int height(TreeNode* root){
        int h = 0;
        if(root == NULL) return 0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            h++;
        }

        return h;
    }
};