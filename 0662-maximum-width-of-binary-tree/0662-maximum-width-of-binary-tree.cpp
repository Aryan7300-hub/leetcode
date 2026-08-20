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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        int ans = 0;
        queue<pair<TreeNode*, long long>>q;
        q.push({root, 0});

        while(!q.empty()){
            int size = q.size();
            long long minIndex = q.front().second;

            long long first = 0;
            long long last = 0;

            for(int i = 0; i<size; i++){
                auto curr = q.front();
                q.pop();

                TreeNode* node = curr.first;
                long long index = curr.second - minIndex;

                if(i==0) first = index;
                last = index;

                if(node->left) q.push({node->left, 2*index});
                if(node->right) q.push({node->right, 2*index+1});
            }
            ans = max(ans, (int)(last-first+1));
        }

        return ans;
    }
};