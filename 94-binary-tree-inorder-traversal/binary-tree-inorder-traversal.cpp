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
    // void inOrder(TreeNode* root, vector<int> &ans) {
    //     if(root == NULL) {
    //         return;
    //     }
    //     inOrder(root->left, ans);
    //     ans.push_back(root->val);
    //     inOrder(root->right, ans);
    // }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        //moris traversal

        while(root) {
            if(!root->left) {
                ans.push_back(root->val);
                root = root->right;
            }
            else {
                TreeNode* curr = root->left;
                while(curr->right && curr->right != root) {
                    curr = curr->right;
                }
                if(curr->right == NULL) {
                    curr->right = root;
                    root = root->left;
                }
                else {
                    curr->right = NULL;
                    ans.push_back(root->val);
                    root = root->right;
                }
            }
        }
        return ans;
    }
};

        // vector<int> ans;
        // if(!root) return ans;
        // stack<bool> vis;
        // stack<TreeNode*> st;
        // st.push(root);
        // vis.push(0);

        // while(!st.empty()) {
        //     TreeNode* temp = st.top();
        //     st.pop();
        //     bool flag = vis.top();
        //     vis.pop();
        //     if(!flag) {
        //         //right node push
        //         if(temp->right) {
        //             st.push(temp->right);
        //             vis.push(0);
        //         }
        //         //root node push
        //         st.push(temp);
        //         vis.push(1);
        //         //left node push
        //         if(temp->left) {
        //             st.push(temp->left);
        //             vis.push(0);
        //         }
        //     }
        //     else {
        //         ans.push_back(temp->val);
        //     }
        // }
        // return ans;