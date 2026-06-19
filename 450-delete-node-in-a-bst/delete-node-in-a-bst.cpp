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
    TreeNode* find(TreeNode* root) {
        if(!root->right) {
            return root;
        }
        return find(root->right);
    }
    TreeNode* helper(TreeNode* root) {
        if(!root->left) return root->right;
        if(!root->right) return root->left;
        TreeNode* rightNode = root->right;
        TreeNode* leftMostNode = find(root->left);
        leftMostNode->right = rightNode;
        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) {
            return root;
        }
        if(root->val == key) {
            return helper(root);
        }

        TreeNode* dummyNode = root;
        while(dummyNode) {
            if(dummyNode->val < key) {
                //go to right
                if(dummyNode->right && dummyNode->right->val == key) {
                    dummyNode->right = helper(dummyNode->right);
                    break;
                }
                else {
                    dummyNode = dummyNode->right;
                }
            }
            else {
                if(dummyNode->left && dummyNode->left->val == key) {
                    dummyNode->left = helper(dummyNode->left);
                    break;
                }
                else {
                    dummyNode = dummyNode->left;
                }
            }
        }
        return root;
    }
};