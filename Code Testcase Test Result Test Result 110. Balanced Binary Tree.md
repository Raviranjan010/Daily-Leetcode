
https://leetcode.com/problems/balanced-binary-tree/description/?envType=daily-question&envId=2026-02-08




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
int h (TreeNode*root){
    if(!root)return 0;
    int l =h(root->left);
    int r=h(root->right);
    return max(l,r)+1;
}
    bool isBalanced(TreeNode* root) {
        if(!root)return true;
        int l=h(root->left);
        int r=h(root->right);
        if(abs(l-r)>1)return false;
        return isBalanced(root->left)&&isBalanced(root->right);
    }
};
