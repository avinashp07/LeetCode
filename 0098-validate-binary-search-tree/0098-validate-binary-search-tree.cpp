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
    bool isvalid(TreeNode* node,long long left,long long right)
    {
        if(node==NULL) return true;

        if(!(node->val<right && node->val>left)) return false;

        return isvalid(node->left,left,node->val) && isvalid(node->right,node->val,right);
    }
    bool isValidBST(TreeNode* root) {
        return isvalid(root,-LLONG_MAX,LLONG_MAX);
    }
};