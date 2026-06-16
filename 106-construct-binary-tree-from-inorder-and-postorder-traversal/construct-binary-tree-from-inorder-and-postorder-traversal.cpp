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
    int find(vector<int>& inorder, int target, int inSt, int inEnd) {
        for(int i = inSt; i <= inEnd; i++) {
            if(inorder[i] == target) {
                return i;
            }
        }
        return -1;
    }

    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,
                    int inSt, int inEnd, int &idx) {

        if(inSt > inEnd) {
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[idx--]);

        int pos = find(inorder, root->val, inSt, inEnd);

        root->right = solve(inorder, postorder, pos + 1, inEnd, idx);
        root->left  = solve(inorder, postorder, inSt, pos - 1, idx);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int idx = postorder.size() - 1;
        return solve(inorder, postorder, 0, inorder.size() - 1, idx);
    }
};