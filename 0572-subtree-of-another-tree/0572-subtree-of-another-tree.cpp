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
    bool isSameTree(TreeNode* p,TreeNode* q)
    {
        if(p==NULL && q==NULL) return 1;
        if(p==NULL || q==NULL) return 0;
        if(p->val!=q->val) return false;
        if(!isSameTree(p->left,q->left) || !isSameTree(p->right,q->right)) return false;

        return true;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL && subRoot==NULL) return 1;
        if(root==NULL || subRoot==NULL) return 0;
        if(isSameTree(root,subRoot)) return true;
        if(isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot)) return true;
        return false;
    }
};