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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int inSt, int inEnd, int &idx) {
        if(inSt>inEnd) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[idx]);
        idx++;
        int i = inSt;
        while(i<=inEnd) {
            if(inorder[i] == root->val) {
                break;
            }
            i++;
        }
        root->left = solve(preorder, inorder, inSt, i-1, idx);
        root->right = solve(preorder, inorder, i+1, inEnd, idx);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int inSt = 0;
        int inEnd = inorder.size()-1;
        int idx = 0;
        return solve(preorder, inorder, inSt, inEnd, idx);
    }
};