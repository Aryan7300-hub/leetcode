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
        if(root == NULL) return ans;

        map<int,map<int, multiset<int>>>mp;
        queue<tuple<TreeNode*, int, int>>q;
        q.push({root, 0, 0});

        while(!q.empty()){
            auto [node, row, col] = q.front();
            q.pop();

            mp[col][row].insert(node->val);

            if(node->left) q.push({node->left, row+1, col-1});
            if(node->right) q.push({node->right, row+1, col+1});
        }

       for(auto &col : mp){
            vector<int>temp;
            for(auto &row: col.second){
                for(int val: row.second)
                    temp.push_back(val);
            }
            ans.push_back(temp);
       }

        return ans;
    }
};