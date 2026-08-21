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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;

        queue<pair<TreeNode*, int>>q;
        q.push({root, targetSum});

        while(!q.empty()){
            auto [curr, sum] = q.front();
            q.pop();
            if(!curr->left && !curr->right && curr->val == sum){
                return true;
            }
            if(curr->left) q.push({curr->left, sum-curr->val});
            if(curr->right) q.push({curr->right, sum-curr->val});
        }

        return false;
    }
};