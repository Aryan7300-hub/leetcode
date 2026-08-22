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

        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        
        q.push(target);
        visited.insert(target);
        int dis = 0;

        while(!q.empty()){
            if(dis == k) break;

            int size = q.size();

            while(size--){
                TreeNode* node = q.front();
                q.pop();

                if(node->left && visited.insert(node->left).second) q.push(node->left);
                if(node->right && visited.insert(node->right).second) q.push(node->right);
                if(parent[node] && visited.insert(parent[node]).second) q.push(parent[node]);
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