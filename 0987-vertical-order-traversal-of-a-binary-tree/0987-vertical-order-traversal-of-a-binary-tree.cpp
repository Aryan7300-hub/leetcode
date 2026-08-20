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
    vector<vector<int>>ans;
    vector<vector<int>>nodes;

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);

        sort(nodes.begin(), nodes.end());

        int prevCol = INT_MAX;

        for(auto &node: nodes){
            if(node[0] != prevCol){
                ans.push_back({});
                prevCol = node[0];
            }
            ans.back().push_back(node[2]);
        }

        return ans;
    }
private:
    void dfs(TreeNode* root, int row, int col){
        if(!root) return;
        nodes.push_back({col, row, root->val});

        dfs(root->left, row+1, col-1);
        dfs(root->right, row+1, col+1);
    }
};