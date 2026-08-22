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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        buildParent(root, NULL);

        queue<TreeNode*>q;
        unordered_set<TreeNode*> visited;
        
        q.push(target);
        visited.insert(target);
        int dis = 0;

        while(!q.empty()){
            if(dis == k) break;
            int size = q.size();

            while(size--){
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left && visited.insert(curr->left).second) q.push(curr->left);
                if(curr->right && visited.insert(curr->right).second) q.push(curr->right);
                if(parent[curr] && visited.insert(parent[curr]).second) q.push(parent[curr]);
            }
            dis++;
        }

        vector<int>ans;

        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }

private:
    void buildParent(TreeNode* root, TreeNode* par){
        if(!root) return;

        parent[root] = par;

        buildParent(root->left, root);
        buildParent(root->right, root);
    }
};