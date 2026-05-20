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
    int helper(TreeNode* root, int current_max){
        if(root == NULL){
            return 0;
        }

        int count = 0;
        if(root->val >= current_max){
            count = 1;
            current_max = root->val;
        }

        int l = helper(root->left,current_max);
        int r = helper(root->right,current_max);
        return l+r+count;
    }
    int goodNodes(TreeNode* root) {
        return helper(root,INT_MIN);
    }
};
