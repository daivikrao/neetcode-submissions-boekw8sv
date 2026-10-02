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
    TreeNode* buildhelper(vector<int>& preorder, vector<int>& inorder,int inS, int inE, int preS, int preE){
        if(inS > inE){
            return NULL;
        }

        int rootData = preorder[preS];
        int rootIndex = -1;
        for(int i=inS;i<=inE;i++){
            if(inorder[i] == rootData){
                rootIndex = i;
                break;
            }
        }

        int leftInS = inS;                                      //left root right
        int leftInE =  rootIndex - 1;                                     // root left right
        int leftPreS = preS + 1;
        int leftPreE =  leftInE - leftInS + leftPreS;

        int rightInS = rootIndex + 1;
        int rightInE = inE;
        int rightPreS = leftPreE + 1;
        int rightPreE = preE;

        TreeNode* newNode = new TreeNode(rootData);

        newNode->left = buildhelper(preorder, inorder,leftInS,leftInE,leftPreS,leftPreE);
        newNode->right = buildhelper(preorder, inorder,rightInS,rightInE,rightPreS,rightPreE);
        return newNode;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        return buildhelper(preorder, inorder,0,n-1,0,n-1);
    }
};
