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
    int findRightHt(TreeNode* root) {
        int ht = 0;
        while(root) {
            ht++;
            root = root->right;
        }
        return ht;
    }
    int findLeftHt(TreeNode* root) {
        int ht = 0;
        while(root) {
            ht++;
            root = root->left;
        }
        return ht;
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;

        int leftHt = findLeftHt(root);
        int rightHt = findRightHt(root);

        if(leftHt == rightHt) {
            return pow(2, leftHt)-1;
        }
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

};