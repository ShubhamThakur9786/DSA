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
    void parent(TreeNode* root, map<TreeNode*, TreeNode*> &mp) {
        if(!root) return;
        if(root->left) mp[root->left] = root;
        if(root->right) mp[root->right] = root;
        parent(root->left, mp);
        parent(root->right, mp);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if(!root) return ans;
        map<TreeNode*, TreeNode*> mp;
        parent(root, mp);
        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> vis;
        q.push(target);
        vis[target] = true;
        int currLevel = 0;
        while(!q.empty()) {
            int size = q.size();
            if(currLevel == k) break;
            currLevel++;
            
            for(int i=0; i<size; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left && !vis[temp->left]) {
                    q.push(temp->left);
                    vis[temp->left] = true;
                }
                if(temp->right && !vis[temp->right]) {
                    q.push(temp->right);
                    vis[temp->right] = true;
                }
                if(mp[temp] && !vis[mp[temp]]) {
                    q.push(mp[temp]);
                    vis[mp[temp]] = true;
                }
            }
        }

        while(!q.empty()) {
            TreeNode* tp = q.front();
            q.pop();
            ans.push_back(tp->val);
        }
        return ans;
    }
};