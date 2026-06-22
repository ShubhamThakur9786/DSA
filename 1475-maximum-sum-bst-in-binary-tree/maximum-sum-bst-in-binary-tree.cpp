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

class NodeValue {
public:
    int maxSum;
    int sum;
    int mini;
    int maxi;

    NodeValue(int maxSum, int sum, int mini, int maxi) {
        this->maxSum = maxSum;
        this->sum = sum;
        this->mini = mini;
        this->maxi = maxi;
    }
};

class Solution {
public:

    NodeValue solve(TreeNode* root) {
        if (!root) {
            return NodeValue(0, 0, INT_MAX, INT_MIN);
        }

        NodeValue left = solve(root->left);
        NodeValue right = solve(root->right);

        // BST condition
        if (left.maxi < root->val && root->val < right.mini) {

            int sum = root->val + left.sum + right.sum;

            return NodeValue(
                max(sum, max(left.maxSum, right.maxSum)),
                sum,
                min(root->val, left.mini),
                max(root->val, right.maxi)
            );
        }

        // Not a BST
        return NodeValue(
            max(left.maxSum, right.maxSum),
            0,
            INT_MIN,
            INT_MAX
        );
    }

    int maxSumBST(TreeNode* root) {
        return solve(root).maxSum;
    }
};