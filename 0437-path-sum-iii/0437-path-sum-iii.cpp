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
    long long count = 0;
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;

        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            dfs(node,0, targetSum);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }

        return count;

        return count;
    }
private:
    void dfs(TreeNode* root, long long sum, long long targetSum){
        if(!root) return;

        sum+=root->val;
        if(sum == targetSum) count++;

        dfs(root->left, sum, targetSum);
        dfs(root->right, sum, targetSum);
    }
};