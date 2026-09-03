/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    int i = 0;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "#";

        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> arr;
        stringstream ss(data);
        string value;
        while(getline(ss, value, ','))
            arr.push_back(value); 
        
        i = 0;
        return build(arr);
    }
private:
    TreeNode* build(vector<string>& arr){
        string value = arr[i++];

        if(value == "#") return NULL;

        TreeNode* root = new TreeNode(stoi(value));
        root->left = build(arr);
        root->right = build(arr);

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));