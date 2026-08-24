/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        buildParent(root, NULL);
        unordered_set<TreeNode*> ancestors;

        while(p){
            ancestors.insert(p);
            p = parent[p];
        }
        while(!ancestors.count(q)){
            q = parent[q];
        }

        return q;
    }
private:
    void buildParent(TreeNode* root, TreeNode* par){
        if(!root) return;

        parent[root] = par;

        buildParent(root->left, root);
        buildParent(root->right, root);
    }
};