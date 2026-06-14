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
 //iterative approch
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            vector<int> temp;
            for(int i=0; i<size; i++) {
                TreeNode* tp = q.front();
                q.pop();
                temp.push_back(tp->val);
                if(tp->left) q.push(tp->left);
                if(tp->right) q.push(tp->right);
            }

            ans.push_back(temp[temp.size()-1]);
        }
        return ans;
    }
};

//recursive approch 

// class Solution {
// public:
//     void solve(TreeNode* &root, vector<int> &ans, int level) {
//         if(root == NULL) return;
//         if(level == ans.size()) {
//             ans.push_back(root->val);
//         }
//         solve(root->right, ans, level+1);
//         solve(root->left, ans, level+1);
//     }
//     vector<int> rightSideView(TreeNode* root) {
//         vector<int> ans;
//         if(!root) return ans;
//         int level = 0;
//         solve(root, ans, level);
//         return ans;
//     }
// };