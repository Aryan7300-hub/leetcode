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
    TreeNode* xParent = NULL;
    TreeNode* yParent = NULL;
    int xDepth = -1;
    int yDepth = -1;

    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, NULL, 0, x, y);
        return xDepth == yDepth && xParent!= yParent;
    }
private:
    void dfs(TreeNode* root, TreeNode* parent, int depth, int x, int y){
        if(!root) return;
        if(root->val == x){
            xParent = parent;
            xDepth = depth;
        }
        if(root->val == y){
            yParent = parent;
            yDepth = depth;
        }

        dfs(root->left, root, depth+1, x, y);
        dfs(root->right, root, depth+1, x, y);
    }
};