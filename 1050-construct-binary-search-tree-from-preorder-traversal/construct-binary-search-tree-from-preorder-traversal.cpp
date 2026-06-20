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
    TreeNode* createBST(vector<int> &preorder, int &idx, long long mini, long long maxi) {
        if(idx == preorder.size()) {
            return NULL;
        }
        if(preorder[idx] <= mini || preorder[idx] >= maxi) {
            return NULL;
        }

        TreeNode* newNode = new TreeNode(preorder[idx++]);
        newNode->left = createBST(preorder, idx, mini, newNode->val);
        newNode->right = createBST(preorder, idx, newNode->val, maxi);
        return newNode;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        long long mini = LLONG_MIN;
        long long maxi = LLONG_MAX;
        int idx = 0;
        TreeNode* ans = createBST(preorder, idx, mini, maxi);
        return ans;
    }
};