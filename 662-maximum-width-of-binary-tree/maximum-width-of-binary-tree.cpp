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
    typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        ll ans = 0;
        queue<pair<TreeNode*, ll>> q;
        q.push({root, 0});

        while(!q.empty()) {
            int size = q.size();
            ll l = q.front().second;
            ll r = q.back().second;
            ans = max(ans, r-l+1);

            for(int i=0; i<size; i++) {
                auto top = q.front();
                q.pop();
                TreeNode* node = top.first;
                ll idx = top.second;
                if(node->left) {
                    q.push({node->left, 2*idx+1});
                }
                if(node->right) {
                    q.push({node->right, 2*idx+2});
                }
            }
        }

        return ans;
    }
};