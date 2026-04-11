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
// preorder - root,left,right
// inorder - left,root,right
class Solution {
public:
    TreeNode* buildTreeHelper(vector<int> preorder, vector<int> inorder,int InS,int InE,int PreS,int PreE){
        
        if(InS > InE){
            return NULL;
        }
        int rootData = preorder[PreS];

        int rootIndex = -1;
        for(int i=InS;i<=InE;i++){
            if(inorder[i] == rootData){
                rootIndex = i;
                break;
            }
        }
        
        int leftInS = InS;
        int leftInE = rootIndex - 1;
        int leftPreS = PreS + 1;
        int leftPreE = leftPreS + leftInE - leftInS;

        int rightInS = rootIndex + 1;
        int rightInE = InE;
        int rightPreS = leftPreE + 1;
        int rightPreE = PreE;

        TreeNode* root = new TreeNode(rootData);
        root->left = buildTreeHelper(preorder,inorder,leftInS,leftInE,leftPreS,leftPreE);
        root->right = buildTreeHelper(preorder,inorder,rightInS,rightInE,rightPreS,rightPreE);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        return buildTreeHelper(preorder,inorder,0,n-1,0,n-1);
    }
};
