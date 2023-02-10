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
    int count=0;
    void check(TreeNode* node, int c)
    {
        if(node==NULL) return;
        if(node->val>=c)
        {
            count++;
            c=node->val;
        }
        check(node->left,c);
        check(node->right,c);
    }
    int goodNodes(TreeNode* root) {
        check(root,root->val);
        return count;
    }
};