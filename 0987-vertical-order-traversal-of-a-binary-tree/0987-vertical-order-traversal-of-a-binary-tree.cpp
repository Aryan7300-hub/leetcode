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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        vector<vector<int>>nodes;

        if(!root) return ans;

        queue<tuple<TreeNode*, int , int>>q;
        q.push({root, 0, 0});

        while(!q.empty()){
            auto [node, row, col] = q.front();
            q.pop();
            nodes.push_back({col, row, node->val});

            if(node->left) q.push({node->left, row+1, col-1});
            if(node->right) q.push({node->right, row+1, col+1});
        }

        sort(nodes.begin(), nodes.end());

        int prevCol = INT_MAX;

        for(auto &node: nodes){
            if(node[0]!=prevCol){
                ans.push_back({});
                prevCol = node[0];
            }
            ans.back().push_back(node[2]);
        }

        return ans;
    }
};