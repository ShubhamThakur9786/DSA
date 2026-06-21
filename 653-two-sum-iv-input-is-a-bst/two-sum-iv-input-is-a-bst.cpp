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
    void inorder(TreeNode* &root, vector<int> &ans) {
        if(!root) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    bool check(vector<int> &ans, int k) {
        int st = 0;
        int end = ans.size()-1;
        while(st < end) {
            if(ans[st] + ans[end] < k) {
                st++;
            }
            else if(ans[st] + ans[end] > k) {
                end--;
            }
            else {
                return true;
            }
        }
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        inorder(root, ans);
        return check(ans, k);
    }
};